#include "CDllExport.h"


Cosa::CProxy* proxy;

HRESULT DllExport DirectInputCreate8(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	static bool init = false;

	if (!init)
	{
		init = true;
		proxy = new Cosa::CProxy();

		if (!proxy->IsInit())
		{
			MessageBox(NULL, L"Can not initialize proxy.", L"Fatal Error.", MB_ICONERROR);
			ExitProcess(0);
		}
	}

	return proxy->Call(hinst, dwVersion, riidltf, ppvOut, punkOuter);
}
