#!/bin/bash

rm ./output/main_0x03.exe
x86_64-w64-mingw32-gcc -o ./output/main_0x03.exe ./main/main_0x03.c

sudo rm /media/sf_Shared/main_0x03.exe
sudo cp ./output/main_0x03.exe /media/sf_Shared/main_0x03.exe

echo [*] Done