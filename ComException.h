#pragma once
#include <exception>
#include <Windows.h>
#include <string>
#include <stdio.h>

class com_exception : public std::exception
{
private:
	HRESULT result;
	std::string description;

public:
	com_exception(HRESULT hr) : result{ hr }, description{} {}
	com_exception(HRESULT hr, std::string msg) : result{ hr }, description{ msg } {}
	virtual const char* what() const override
	{
		static char buffer[512];

		if (description.length() == 0)
		{
			sprintf_s(buffer, 128, "Fail with HRESULT of 0x%08X", result);
		}
		else
		{
			sprintf_s(buffer, 128, "Fail with HRESULT of 0x%08X\n\n%s", 
				result, description.c_str());
		}

		return buffer;
	}
};

inline void ThrowIfFailed(HRESULT hr, std::string msg = "")
{
	if (FAILED(hr))
	{
		throw com_exception(hr, msg);
	}
}