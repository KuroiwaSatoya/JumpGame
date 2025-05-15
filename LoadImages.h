#pragma once

// 画像を読み込むためのクラス
// 同じ画像が複数回読み込まれることを防ぐ
class LoadImages {
public:
	
	LoadImages();

	// プレイヤーの画像
	int playerImage;

	// 背景の画像
	int backgroundImage;
};