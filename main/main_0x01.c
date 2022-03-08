#include <stdio.h>
#include <windows.h>

int main(int argv, char* argc[])
{
    HINSTANCE hinst;
    BOOL result;

    hinst = LoadLibraryA("hello.dll");
    result = FreeLibrary(hinst);
}

// x86_64-w64-mingw32-gcc -o ./output/main_0x01.exe ./main/main_0x01.c