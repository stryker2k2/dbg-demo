#!/bin/bash

rm ./output/*

x86_64-w64-mingw32-gcc -shared -o ./output/hello.dll ./dll/hello.c
x86_64-w64-mingw32-gcc -o ./output/main_0x00.exe ./main/main_0x00.c
x86_64-w64-mingw32-gcc -o ./output/main_0x01.exe ./main/main_0x01.c
x86_64-w64-mingw32-gcc -o ./output/main_0x02.exe ./main/main_0x02.c
x86_64-w64-mingw32-gcc -o ./output/func_0x00.exe ./main/func_0x00.c

sudo rm /media/sf_Shared/*.exe
sudo rm /media/sf_Shared/*.dll
sudo cp ./output/*.exe /media/sf_Shared
sudo cp ./output/*.dll /media/sf_Shared

echo [*] Done