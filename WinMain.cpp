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

	// 画面モードの設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_DEPTH);

	// ウィンドウモードの設定
	ChangeWindowMode(TRUE);

	// 画面比率を変えられるかどうか
	SetWindowSizeChangeEnableFlag(TRUE);

	// DXライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

// deltaTimeのセット
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

// プログラムの開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	srand(time(nullptr));

	InitDX();

	// デルタタイムの管理
	float oldTime = GetNowCount();
	float nowTime = 0;
	float deltaTime = 0;

	// 各クラスのインスタンスを生成するための列挙型を作る
	// 順番は、Updateを発動させる順
	enum GameManagerClassName {
		GAMEMANAGER_BACKGROUND,
		GAMEMANAGER_CAMERA,
		GAMEMANAGER_COLLIDER,
		GAMEMANAGER_ARRAY_SIZE // これで配列のサイズを取得
	};

	enum StageClassName {
		STAGE_UNIT_MOVE,
		STAGE_UNIT,
		STAGE_NEEDLE,
		STAGE_MAIN,
		STAGE_ARRAY_SIZE // これで配列のサイズを取得
	};

	enum PlayerClassName {
		PLAYER_RUN,
		PLAYER_JUMP,
		PLAYER_GRAVITY,
		PLAYER_MOVE,
		PLAYER_DISPLAY,
		PLAYER_ARRAY_SIZE // これで配列のサイズを取得
	};

	// 各クラスのインスタンスの生成
	LoadImages loadImages;

	// castして入れてもいいかも←なぜか同じインスタンスを持たない
	PlayerMain* players[PLAYER_ARRAY_SIZE];
	PlayerMove playerMove;
	players[PLAYER_MOVE] = &playerMove;
	players[PLAYER_RUN] = new PlayerRun(playerMove);
	players[PLAYER_JUMP] = new PlayerJump(playerMove);
	players[PLAYER_GRAVITY] = new PlayerGravity(playerMove);
	players[PLAYER_DISPLAY] = new PlayerDisplay(loadImages, playerMove);

	StageMain* stages[STAGE_ARRAY_SIZE];
	stages[STAGE_MAIN] = new StageMain();
	// ステージ用の Unit を配列に変更
	constexpr int MAX_UNITS = 10;
	Unit units[MAX_UNITS];
	// Unitを配列にするのでどう宣言するか、新たにcppファイルを作ってそこで管理する？
	stages[STAGE_UNIT] = &units[0];
	stages[STAGE_UNIT_MOVE] = new UnitMove(units[0]);
	stages[STAGE_NEEDLE] = new Needle();

	GameManagerMain* gameManagers[GAMEMANAGER_ARRAY_SIZE];
	gameManagers[GAMEMANAGER_BACKGROUND] = new Background(loadImages);
	gameManagers[GAMEMANAGER_CAMERA] = new Camera(playerMove);
	gameManagers[GAMEMANAGER_COLLIDER] = new Collider(playerMove, &units[0]);

	// updateみたいなもの
	while (TRUE) {
		// deltaTimeを作成
		nowTime = GetNowCount();

		// deltaTimeが0にならないようにmaxで制御
		// nowTime, oldTime共に単位がミリ秒のため、1000で割る
		deltaTime = max((nowTime - oldTime) / 1000.0f, 0.01f);

		// 次のフレームのためにoldTimeにnowTimeを代入
		oldTime = nowTime;

		// スクリーンに映ってるものを消す
		ClearDrawScreen();


		// ---ここからメインの処理---

		// StageMainとPlayerMoveにデルタタイムをセット
		SetDeltaTime(stages[STAGE_MAIN], playerMove, deltaTime);

		// Stageの更新
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Update();

		}

		// Playerの更新
		for (int i = 0; i < PLAYER_ARRAY_SIZE; i++) {

			players[i]->Update();

		}

		// GameManagerの更新
		for (int i = 0; i < GAMEMANAGER_ARRAY_SIZE; i++) {

			gameManagers[i]->Update();

		}

		// Backgroundの描画
		GameManagerDraw(gameManagers[GAMEMANAGER_BACKGROUND]);
		
		// Stageの描画
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Display();

		}

		// Playerの描画
		PlayerDraw(players[PLAYER_DISPLAY]);

		// ESCキーが押されたらループから抜ける(ゲームを終了)
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// Windows システムからくる情報を処理する
		if (ProcessMessage() == -1) break;

		// 裏画面に描画したものを映す
		ScreenFlip();

	}

	// DXライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了 
	return 0;
}

/* Unitを沢山出すと思うんだけど、
出現しているかというのをbool型で管理して、
出現していない番号の若い順から出現させればよいのでは？ */