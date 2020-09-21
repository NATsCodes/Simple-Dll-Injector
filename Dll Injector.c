#include <stdio.h>
#include <Windows.h>

BOOL InjectDLL(DWORD pid, LPCSTR dllpath) {
	HANDLE hProcess, hThread;
	LPVOID BaseAddr, LoadLibraryAaddr;
	DWORD MemSize, ExitCode;
	BOOL Success = FALSE;
	HMODULE hUserDll;

	if (hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, FALSE, pid))
	{
		MemSize = strlen(dllpath) + 1;
		BaseAddr = VirtualAllocEx(hProcess, NULL, MemSize, MEM_COMMIT, PAGE_READWRITE);
		if (BaseAddr != NULL)
		{
			if (WriteProcessMemory(hProcess, BaseAddr, dllpath, MemSize, NULL))
			{
				if (hUserDll = LoadLibrary(TEXT("kernel32.dll")))
				{
					if (LoadLibraryAaddr = GetProcAddress(hUserDll, "LoadLibraryA"))
					{
						if (hThread = CreateRemoteThread(hProcess, NULL, 0, LoadLibraryAaddr, BaseAddr, 0, NULL))
						{
							WaitForSingleObject(hThread, INFINITE);
							if (GetExitCodeThread(hThread, &ExitCode))
							{
								Success = (ExitCode != 0) ? TRUE : FALSE;
							}
							CloseHandle(hThread);
						}
					}
					FreeLibrary(hUserDll);
				}	
			}
			VirtualFreeEx(hProcess, BaseAddr, 0, MEM_RELEASE);
		}
		CloseHandle(hProcess);
	}
	return FALSE;
}

int main(int argc, char* argv[]) {
	InjectDLL(atoi(argv[1]) , argv[2]);

	return 0;
}
