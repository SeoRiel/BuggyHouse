#include <Windows.h>
#include "BuggyHouse.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	int ret{ 0 };

	try
	{
		BuggyHouse myFramework;

		if (SUCCEEDED(myFramework.Initialize(hInstance)))
		{
			ret = myFramework.GameLoop();
		}

	}
	catch (com_exception& e)
	{
		static wchar_t wstr[128]{};
		size_t length;

		mbstowcs_s(&length, wstr, e.what(), 128);

		D2DFramework::ShowErrorMsg(wstr);
	}

	return ret;
}