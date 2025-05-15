#include "Collider.h"

Collider::Collider(PlayerMove& _playerMove, Unit* _units) : playerMove(_playerMove){

	units = _units;

	unitCount = 10;

    playerPosition = _playerMove.GetPosition();

    unitPosition = _units->GetPosition();

    playerSize = _playerMove.GetImageSize();
}

void Collider::Update() {
    // プレイヤーの位置を更新
    playerPosition = playerMove.GetPosition();

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

    unitPosition = units->GetPosition();
    unitSize = units->GetSize();

    // unitとplayerの当たり判定
    if (playerPosition.x < unitPosition.x + unitSize.x &&
        playerPosition.x + playerSize.x > unitPosition.x &&
        playerPosition.y < unitPosition.y + unitSize.y &&
        playerPosition.y + playerSize.y > unitPosition.y) {

        // playerが上昇中なら当たり判定を変更
        if (playerMove.GetLastDirectionY() < 0) {

            HitHead(units);

        }
        else {
            HitFeet(units);
        }
    }
    else {
        HandleNoCollisions();
    }

    if (playerPosition.y > 1279) {

        // PlayerのisGroundをtrueにする
        playerMove.SetIsGround(true);

    }
}



// 当たった場合の処理
void Collider::HitFeet(Unit* unit) {
    
    // PlayerのisGroundをtrueにする
    playerMove.SetIsGround(true);

    // PlayerがUnitにめり込まないようにY座標を調整
    playerMove.SetPositionY(unitPosition.y - playerSize.y);

}

void Collider::HitHead(Unit* unit) {

    // PlayerのisGroundをfalseにする
    playerMove.SetIsGround(false);

    // PlayerがUnitより上に行かないようにY座標を調整
    playerMove.SetPositionY(unitPosition.y + unitSize.y);

}

// 当たってない場合の処理
void Collider::HandleNoCollisions() {

    playerMove.SetIsGround(false);

}