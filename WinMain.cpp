#include <windows.h>
#include <ctime>
#include "DxLib.h"
#include "Screen.h"
#include "LoadImages.h"
#include "GameManagerMain.h"
#include "Background.h"
#include "Camera.h"
#include "Collider.h"
#include "StageMain.h"
#include "Unit.h"
#include "UnitMove.h"
#include "Needle.h"
#include "PlayerMain.h"
#include "PlayerMove.h"
#include "PlayerGravity.h"
#include "PlayerJump.h"
#include "PlayerRun.h"
#include "PlayerDisplay.h"


bool InitDX() {

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_DEPTH);

	// �E�B���h�E���[�h�̐ݒ�
	ChangeWindowMode(TRUE);

	// ��ʔ䗦��ς����邩�ǂ���
	SetWindowSizeChangeEnableFlag(TRUE);

	// DX���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

// deltaTime�̃Z�b�g
void SetDeltaTime(StageMain* _stageMain ,PlayerMove& _playerMove, float _deltaTime) {
	_stageMain->SetDeltaTime(_deltaTime);
	_playerMove.SetDeltaTime(_deltaTime);
}

void GameManagerDraw(GameManagerMain* _gameManagerMain) {
	_gameManagerMain->Display();
}

void PlayerDraw(PlayerMain* _playerMain) {
	_playerMain->Display();
}

// �v���O�����̊J�n
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(nullptr));

	InitDX();

	// �f���^�^�C���̊Ǘ�
	float oldTime = GetNowCount();
	float nowTime = 0;
	float deltaTime = 0;

	// �e�N���X�̃C���X�^���X�𐶐����邽�߂̗񋓌^�����
	// ���Ԃ́AUpdate�𔭓������鏇
	enum GameManagerClassName {
		GAMEMANAGER_BACKGROUND,
		GAMEMANAGER_CAMERA,
		GAMEMANAGER_COLLIDER,
		GAMEMANAGER_ARRAY_SIZE // ����Ŕz��̃T�C�Y���擾
	};

	enum StageClassName {
		STAGE_UNIT_MOVE,
		STAGE_UNIT,
		STAGE_NEEDLE,
		STAGE_MAIN,
		STAGE_ARRAY_SIZE // ����Ŕz��̃T�C�Y���擾
	};

	enum PlayerClassName {
		PLAYER_RUN,
		PLAYER_JUMP,
		PLAYER_GRAVITY,
		PLAYER_MOVE,
		PLAYER_DISPLAY,
		PLAYER_ARRAY_SIZE // ����Ŕz��̃T�C�Y���擾
	};

	// �e�N���X�̃C���X�^���X�̐���
	LoadImages loadImages;

	// cast���ē���Ă������������Ȃ��������C���X�^���X�������Ȃ�
	PlayerMain* players[PLAYER_ARRAY_SIZE];
	PlayerMove playerMove;
	players[PLAYER_MOVE] = &playerMove;
	players[PLAYER_RUN] = new PlayerRun(playerMove);
	players[PLAYER_JUMP] = new PlayerJump(playerMove);
	players[PLAYER_GRAVITY] = new PlayerGravity(playerMove);
	players[PLAYER_DISPLAY] = new PlayerDisplay(loadImages, playerMove);

	StageMain* stages[STAGE_ARRAY_SIZE];
	stages[STAGE_MAIN] = new StageMain();
	// �X�e�[�W�p�� Unit ��z��ɕύX
	constexpr int MAX_UNITS = 10;
	Unit units[MAX_UNITS];
	// Unit��z��ɂ���̂łǂ��錾���邩�A�V����cpp�t�@�C��������Ă����ŊǗ�����H
	stages[STAGE_UNIT] = &units[0];
	stages[STAGE_UNIT_MOVE] = new UnitMove(units[0]);
	stages[STAGE_NEEDLE] = new Needle();

	GameManagerMain* gameManagers[GAMEMANAGER_ARRAY_SIZE];
	gameManagers[GAMEMANAGER_BACKGROUND] = new Background(loadImages);
	gameManagers[GAMEMANAGER_CAMERA] = new Camera(playerMove);
	gameManagers[GAMEMANAGER_COLLIDER] = new Collider(playerMove, &units[0]);

	// update�݂����Ȃ���
	while (TRUE) {
		// deltaTime���쐬
		nowTime = GetNowCount();

		// deltaTime��0�ɂȂ�Ȃ��悤��max�Ő���
		// nowTime, oldTime���ɒP�ʂ��~���b�̂��߁A1000�Ŋ���
		deltaTime = max((nowTime - oldTime) / 1000.0f, 0.01f);

		// ���̃t���[���̂��߂�oldTime��nowTime����
		oldTime = nowTime;

		// �X�N���[���ɉf���Ă���̂�����
		ClearDrawScreen();


		// ---�������烁�C���̏���---

		// StageMain��PlayerMove�Ƀf���^�^�C�����Z�b�g
		SetDeltaTime(stages[STAGE_MAIN], playerMove, deltaTime);

		// Stage�̍X�V
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Update();

		}

		// Player�̍X�V
		for (int i = 0; i < PLAYER_ARRAY_SIZE; i++) {

			players[i]->Update();

		}

		// GameManager�̍X�V
		for (int i = 0; i < GAMEMANAGER_ARRAY_SIZE; i++) {

			gameManagers[i]->Update();

		}

		// Background�̕`��
		GameManagerDraw(gameManagers[GAMEMANAGER_BACKGROUND]);
		
		// Stage�̕`��
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Display();

		}

		// Player�̕`��
		PlayerDraw(players[PLAYER_DISPLAY]);

		// ESC�L�[�������ꂽ�烋�[�v���甲����(�Q�[�����I��)
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// Windows �V�X�e�����炭�������������
		if (ProcessMessage() == -1) break;

		// ����ʂɕ`�悵�����̂��f��
		ScreenFlip();

	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I�� 
	return 0;
}

/* Unit���R�o���Ǝv���񂾂��ǁA
�o�����Ă��邩�Ƃ����̂�bool�^�ŊǗ����āA
�o�����Ă��Ȃ��ԍ��̎Ⴂ������o��������΂悢�̂ł́H */