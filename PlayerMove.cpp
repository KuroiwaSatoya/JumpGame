#include "PlayerMove.h"

PlayerMove::PlayerMove() {

	position = Vector2(600, 300);

	deltaTime = 0.01;

	isGround = false;
}

void PlayerMove::Update() {

	// direction.x,yÇ…çáÇÌÇπÇƒç¿ïWÇïœçX
	if (direction.x <= 0 && position.x > SCREEN_ORIGIN) {

		position.x += direction.x * deltaTime;

	}
	else if(position.x <= SCREEN_ORIGIN) {

		position.x = SCREEN_ORIGIN;

	}

	if (direction.x >= 0 && position.x < SCREEN_WIDTH - imageSize.x) {

		position.x += direction.x * deltaTime;

	}
	else if(position.x >= SCREEN_WIDTH - imageSize.x) {

		position.x = SCREEN_WIDTH - imageSize.x;

	}

	if (direction.y <= 0 && position.y > SCREEN_ORIGIN) {

		position.y += direction.y * deltaTime;

	}
	else if(position.y <= SCREEN_ORIGIN) {

		position.y = SCREEN_ORIGIN;

	}

	if (direction.y >= 0 && position.y < SCREEN_HEIGHT - imageSize.y) {

		position.y += direction.y * deltaTime;

	}
	else if(position.y >= SCREEN_HEIGHT - imageSize.y) {

		position.y = SCREEN_HEIGHT - imageSize.y;
	}

	direction = lastDirection;

	direction.x = 0;
	direction.y = 0;

}