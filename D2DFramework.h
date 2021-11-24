#pragma once

#include <d2d1.h>
#include <wincodec.h>
#include <wrl/client.h>
#include "ComException.h"

class D2DFramework
{
private:
	const LPCWSTR WND_CLASS_NAME{ L"MyWindowClass" };

protected:
	HWND mHwnd{};
	Microsoft::WRL::ComPtr<ID2D1Factory> mspD2D1Factory{};
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> mspRenderTarget{};

public:
	HWND GetWindowHandle() { return mHwnd; }
	ID2D1Factory* GetD2DFactory() { return mspD2D1Factory.Get(); }
	ID2D1HwndRenderTarget* GetRenderTarget() { return mspRenderTarget.Get(); }

protected:
	HRESULT InitiailzeWindow(HINSTANCE hInstance, LPCWSTR title, 
		UINT width, UINT height);

	HRESULT InitializeD2D();

	virtual HRESULT CreateDeviceResources();

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"MyFramework", 
		UINT width = 1024, UINT height = 768);
	virtual void Release();
	virtual int GameLoop();
	virtual void Render();

	static void ShowErrorMsg(LPCWSTR msg, LPCWSTR title = L"Error");

public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, 
		WPARAM wParam, LPARAM lParam);

};