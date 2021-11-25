#pragma once
#include <list>
#include <memory>
#include "Bug.h"
#include "D2DFramework.h"

class BuggyHouse : public D2DFramework
{
private:
	std::unique_ptr<Actor> mspBackgound;
	std::list<std::unique_ptr<Bug>> mBuglist;

public:
	virtual HRESULT Initialize(
	HINSTANCE hInstance, LPCWSTR title = L"Buggy House",
		UINT width = 1024, UINT height = 768) override;

	virtual void Release() override;
	virtual void Render() override;
};

