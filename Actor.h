#pragma once

#include "D2DFramework.h"

class Actor
{
protected:
	// Actor Class�� D2DFramework�� ��ӵ��� �ʾƾ���
	D2DFramework* mpFramework;
	ID2D1Bitmap* mpBitmap;

	float mX;
	float mY;
	float mOpacity;

public:
	// �⺻ �����ڸ� ������� ����
	Actor() = delete;
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity = 1.0f);
	virtual ~Actor();

private:
	HRESULT LoadWICImage(LPCWSTR filename);
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw();
	D2D_VECTOR_2F GetPosition() { return { mX, mY }; };
	void SetPosition(D2D_VECTOR_2F& pos) { mX = pos.x; mY = pos.y; }
	void SetPosition(float x, float y) { mX = x; mY = y; }
	void SetOpacity(float o) { mOpacity = 0; }

};