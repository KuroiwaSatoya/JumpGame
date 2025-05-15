#include "Collider.h"
#include <cmath>
#include <algorithm>

using namespace std;

Collider::Collider(PlayerMove& _playerMove, PlayerJump& _playerJump, Unit* _units) : playerMove(_playerMove), playerJump(_playerJump){

	units = _units;

	unitCount = 10;

    playerPosition = _playerMove.GetPosition();

    lastPlayerPosition = playerPosition; // PlayerMoveに持たせるのもあり

    unitPosition = _units->GetPosition();

    playerSize = _playerMove.GetImageSize();
}

    //// 各ユニットとプレイヤーの当たり判定をチェック
    //for (int i = 0; i < unitCount; i++) {
    //    unitPosition = units[i].GetPosition();
    //    unitSize = units[i].GetSize();

    //    // 当たり判定
    //    if (playerPosition.x < unitPosition.x + unitSize.x &&
    //        playerPosition.x + playerSize.x > unitPosition.x &&
    //        playerPosition.y < unitPosition.y + unitSize.y &&
    //        playerPosition.y + playerSize.y > unitPosition.y) {
    //        
    //        HandleCollisions(&units[i]);
    //    }
    //    else {
    //        HandleNoCollisions();
    //    }
    //}

void Collider::Update() {

    // 前回の位置を保存
    lastPlayerPosition = playerPosition;

    // 現在位置を更新
    playerPosition = playerMove.GetPosition();
    unitPosition = units->GetPosition();
    unitSize = units->GetSize();
    playerSize = playerMove.GetImageSize(); // 要らないが念のため

    // 矩形の当たり判定
    if (playerPosition.x < unitPosition.x + unitSize.x &&
        playerPosition.x + playerSize.x > unitPosition.x &&
        playerPosition.y < unitPosition.y + unitSize.y &&
        playerPosition.y + playerSize.y > unitPosition.y) {

        // UnitとPlayerがどれだけめり込んでいるかを算出
        float overlapX = min(playerPosition.x + playerSize.x, unitPosition.x + unitSize.x) - max(playerPosition.x, unitPosition.x);
        float overlapY = min(playerPosition.y + playerSize.y, unitPosition.y + unitSize.y) - max(playerPosition.y, unitPosition.y);

        // 上下でめり込んでいたら
        if (overlapY < overlapX) {
            // 中心のY座標を比較し、PlayerがUnitの上にいるのか下にいるのか判定
            if (playerPosition.y + playerSize.y / 2 < unitPosition.y + unitSize.y / 2) {
                HitFeet(units);
            }
            else {
                HitHead(units);
            }
        }
        else {
            // 同じように左にいるか右にいるか判定
            if (playerPosition.x + playerSize.x / 2 < unitPosition.x + unitSize.x / 2) {
                HitRight(units);
            }
            else {
                HitLeft(units);
            }
        }
    }
    // これ後で消す
    else if (playerPosition.y > 718 - playerSize.y) {

        // PlayerのisGroundをtrueにする
        playerMove.SetIsGround(true);

    }
    else {
        HandleNoCollisions();
    }
}



// 当たった場合の処理 足からぶつけた
void Collider::HitFeet(Unit* _unit) {
    
    // PlayerのisGroundをtrueにする
    playerMove.SetIsGround(true);

    // PlayerがUnitにめり込まないようにY座標を調整
    playerMove.SetPositionY(unitPosition.y - playerSize.y);

}

// 頭をぶつけた場合
void Collider::HitHead(Unit* _unit) {

    // PlayerがUnitより上に行かないようにY座標を調整
    playerMove.SetPositionY(unitPosition.y + unitSize.y);

    playerJump.StopJump();

    playerMove.SetIsGround(false);

}

// 体の右側がぶつかった場合
void Collider::HitRight(Unit* _unit) {

    playerMove.SetPositionX(unitPosition.x - playerSize.x);

}

// 左側がぶつかった場合
void Collider::HitLeft(Unit* _unit) {

    playerMove.SetPositionX(unitPosition.x + unitSize.x);

}

// 当たってない場合の処理
void Collider::HandleNoCollisions() {

    playerMove.SetIsGround(false);

}