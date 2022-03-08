#include <stdio.h>
#include <windows.h>

int main(int argv, char* argc[])
{
    HANDLE processHandle;
	PVOID remoteBuffer;
	wchar_t dllPath[] = (L"Z:\\hello.dll");
	
	processHandle = GetCurrentProcess();
	remoteBuffer = VirtualAllocEx(processHandle, NULL, sizeof dllPath, MEM_COMMIT, PAGE_READWRITE);	
	WriteProcessMemory(processHandle, remoteBuffer, (LPVOID)dllPath, sizeof dllPath, NULL);
	PTHREAD_START_ROUTINE threatStartRoutineAddress = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandle(TEXT("Kernel32")), "LoadLibraryW");
	CreateRemoteThread(processHandle, NULL, 0, threatStartRoutineAddress, remoteBuffer, 0, NULL);
	CloseHandle(processHandle); 
	
	return 0;
}

// x86_64-w64-mingw32-gcc -o ./output/main_0x02.exe ./main/main_0x02.c