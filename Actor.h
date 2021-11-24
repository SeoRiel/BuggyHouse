#pragma once

#include "D2DFramework.h"

class Actor
{
protected:
	// Actor Class는 D2DFramework에 상속되지 않아야함
	D2DFramework* mpFramework;
	ID2D1Bitmap* mpBitmap;

	float mX;
	float mY;
	float mOpacity;

public:
	// 기본 생성자를 허용하지 않음
	Actor() = delete;
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity = 1.0f);
	virtual ~Actor();

private:
	HRESULT LoadWICImage(LPCWSTR filename);
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw();
	void SetPosition(float x, float y) { mX = x; mY = y; }
	void SetOpacity(float o) { mOpacity = 0; }

};