#include <stdio.h>
#include <windows.h>

int main(int argv, char* argc[])
{
    HANDLE processHandle;
	PVOID remoteBuffer;
	wchar_t dllPath[] = (L"Z:\\hello.dll");
	int result;
	LPVOID loadLibAddr;
	LPDWORD lpThreadID;
	HANDLE hThread;
	
	LoadLibraryW(dllPath);
	
	processHandle = GetCurrentProcess();
	remoteBuffer = VirtualAllocEx(processHandle, NULL, sizeof dllPath, MEM_COMMIT, PAGE_READWRITE);
	result = WriteProcessMemory(processHandle, remoteBuffer, (LPVOID)dllPath, sizeof dllPath, NULL);
	loadLibAddr = (LPVOID)GetProcAddress(GetModuleHandle("kernel32.dll"), "LoadLibraryA");
	PTHREAD_START_ROUTINE threadStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");
	hThread = CreateThread(NULL, 0, threadStartRoutineAddress, dllPath, 0, NULL);

	WaitForSingleObject(hThread, INFINITE);
	CloseHandle(hThread);
	CloseHandle(processHandle);
	
	return 0;
}

// x86_64-w64-mingw32-gcc -o ./output/main_0x02.exe ./main/main_0x02.c