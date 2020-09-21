#include <stdio.h>
#include <Windows.h>

BOOLEAN WINAPI DllMain(HINSTANCE hDllHandle, DWORD fdwReason, LPVOID lpvReserved) {

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		MessageBoxA(NULL, "Im Loaded!!", "Im Loaded!", NULL);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	default:
		break;
	}

	return TRUE;
}
