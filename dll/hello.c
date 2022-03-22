#include <stdio.h>
#include <windows.h>

static DWORD __stdcall HelloMsgBox(char* fdwReason)
{
    MessageBox(NULL, fdwReason, "Hello World!", MB_OK);
}

__declspec(dllexport) 
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        OutputDebugString("DLL_PROCESS_ATTACH");
        HelloMsgBox("DLL_PROCESS_ATTACH");
        break;
 
    case DLL_THREAD_ATTACH:
        OutputDebugString("DLL_THREAD_ATTACH");
        HelloMsgBox("DLL_THREAD_ATTACH");
        break;
 
    case DLL_THREAD_DETACH:
        OutputDebugString("DLL_THREAD_DETACH");
        break;
 
    case DLL_PROCESS_DETACH:
        OutputDebugString("DLL_PROCESS_DETACH");
        break;
    }
 
    return TRUE;
}

// x86_64-w64-mingw32-gcc -shared -o ./output/hello.dll ./dll/hello.c
// rundll32.exe hello.dll,DllMain