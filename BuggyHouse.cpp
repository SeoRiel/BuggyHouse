#include "BuggyHouse.h"

HRESULT BuggyHouse::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr = D2DFramework::Initialize(hInstance, title, width, height);
	ThrowIfFailed(hr, "D2DFramework::Initialize() Failed");

	mspBackgound = std::make_unique<Actor>(this, L"Data/back.png", 0.0f, 0.0f);

	float x, y;
	RECT rect;
	GetClientRect(mHwnd, &rect);

	for (int i = 0; i < 40; i++)
	{
		mBuglist.push_back(std::make_unique<Bug>(this));
	}

	return S_OK;
}

void BuggyHouse::Release()
{
	for (auto& bug : mBuglist)
	{
		bug.reset();
	}
	mBuglist.clear();
	mspBackgound.reset();

	D2DFramework::Release();
}

void BuggyHouse::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();

	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	mspBackgound->Draw();
	for (auto& bug : mBuglist)
	{
		bug->Draw();
	}

	hr = mspRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}
