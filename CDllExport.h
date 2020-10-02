#pragma once
#define DllExport   __declspec( dllexport )

#include <Windows.h>
#include "Utils/Proxy/Proxy.h"

HRESULT DllExport DirectInputCreate8(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);