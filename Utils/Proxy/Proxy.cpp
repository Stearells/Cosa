#include "Proxy.h"

bool Cosa::CProxy::Init()
{
    TCHAR sysDir[MAX_PATH];
    UINT res = GetWindowsDirectory(sysDir, MAX_PATH);

    if (!res)
        return false;

    strcat((CHAR *)&sysDir[0], "dinput8.dll");

    this->hModD8 = LoadLibrary(sysDir);

    if (!this->hModD8)
        return false;

    FARPROC fp = GetProcAddress(this->hModD8, "DirectInput8Create");

    if (!fp)
        return false;

    this->oDirectInput8Create = (t_DirectInput8Create)fp;

    return true;
}

Cosa::CProxy::CProxy()
{
    this->oDirectInput8Create = nullptr;
    this->hModD8 = nullptr;

    this->Init();
}

Cosa::CProxy::~CProxy()
{
    this->Destruct();
}

HRESULT Cosa::CProxy::Call(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
    if (oDirectInput8Create)
    {
        HRESULT res = oDirectInput8Create(hinst, dwVersion, riidltf, ppvOut, punkOuter);
        return res;
    }

    return 0;
}

bool Cosa::CProxy::IsInit()
{
    if (this->oDirectInput8Create)
        return true;
    return false;
}

bool Cosa::CProxy::Destruct()
{
    if (this->hModD8)
        FreeLibrary(this->hModD8);
    this->oDirectInput8Create = nullptr;

    return false;
}
