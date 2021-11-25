#include "Bug.h"

// 동일한 방향으로 5번(5 픽셀까지 그대로 이동)
// 방향 전환 (45도 단위로 전환)
// 8방향 ( UP, UP & RIGHT, RIGHT, DOWN & RIGHT, ...)


Bug::Bug(D2DFramework* pFramework)
	: Actor(pFramework, L"Data/bug.png")
{
	RECT rect{};
	GetClientRect(pFramework->GetWindowHandle(), &rect);
	mX = static_cast<float>(rand() % (rect.right - rect.left));
	mY = static_cast<float>(rand() % (rect.bottom - rect.top));

	mDir = Direction::UP;
	mSteps = 0;
}

void Bug::Draw()
{
	if (mSteps++ > 10)
	{
		mSteps = 0;

		int dir = static_cast<int>(mDir);
		int count = static_cast<int>(Direction::COUNT);

		// 방향 전환
		dir += (rand() % 3 - 1);
		dir = (dir + count) % count;

		mDir = static_cast<Direction>(dir);
	}

	switch (mDir)
	{
		case Direction::UP:
			mY--;
			break;

		case Direction::UP_RIGHT:
			mY--;
			mX++;
			break;

		case Direction::RIGHT:
			mX++;
			break;

		case Direction::DOWN_RIGHT:
			mY++;
			mX++;
			break;

		case Direction::DOWN:
			mY++;
			break;

		case Direction::DOWN_LEFT:
			mY++;
			mX--;
			break;

		case Direction::LEFT:
			mX--;
			break;

		case Direction::UP_LEFT:
			mY--;
			mX--;
			break;
	}

	Actor::Draw();
}
