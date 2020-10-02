#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <string>

namespace Cosa
{
	class CProxy
	{
	public:
		typedef HRESULT(*t_DirectInput8Create)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);

	private:
		t_DirectInput8Create oDirectInput8Create;
		HMODULE hModD8;

		bool Init();

	public:
		CProxy();
		~CProxy();

		HRESULT Call(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);
		bool IsInit();
		bool Destruct();
	};
}