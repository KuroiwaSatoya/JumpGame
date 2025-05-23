#include "PlayerRun.h"
#include "DxLib.h"

PlayerRun::PlayerRun(PlayerMove& _playerMove) : playerMove(_playerMove) {

    speed = 5;
    
    directionX = 0;

    isGround = true;
}

void PlayerRun::Update() {

    // A、←キーが押されていたら左へ、D、→キーが押されていたら右へ行く。
    // 押されていない、もしくは両方押されていたら動かない
    if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT)) {
        
        if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT)) {

            directionX = 0;

        }
        else {
            directionX -= speed;
        }
        
    } else if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT)) {

        directionX += speed;

    }
    else {
        directionX = 0;
    }

    playerMove.AddDirectionX(directionX);

}