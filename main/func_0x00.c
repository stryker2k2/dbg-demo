#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

// #define LOG_PRINT(fmt, ...) do { 
// 	printf(fmt, ##__VA_ARGS__);
// } while(0)
#define LOG_PRINT(fmt, ...) do {printf(fmt, ##__VA_ARGS__);} while(0)

int stringToDouble(char* date)
{
	double day;
	double year;
	char* month;

	if (!date)
	{
		date = "01 JAN";
	}

	/* Convert date (08 March) to... 
	   day = 01
	   month = JAN	*/
	day = strtod(date, &month);
	LOG_PRINT("[*] strtod for day is: %d\n", (int)day);
	LOG_PRINT("[*] strtod for month is: %s\n", month);

	LOG_PRINT("[*] The MMM-DD of conversion of \"%s\" is:%s %d\n",
		date, month, (int)day);

	return 0;
}

int main(int argv, char* argc[])
{
	if (argv != 2)
	{
		LOG_PRINT("[*] Usage: func_0x00.exe \"DD MMM\"\n");
	}

	else
	{
		double num;
		stringToDouble(argc[1]);
	}
	
	return 0;
}

// Windows:
// x86_64-w64-mingw32-gcc -o ./output/func_0x01.exe ./main/func_0x00.c
// c:/> func_0x00.exe "26 MAR"

// Linux
// gcc -o ./output/func_0x00 ./main/func_0x00.c
// ~$ .func_0x00.exe "26 March"

// Optional Windows Compilation:
// x86_64-w64-mingw32-gcc -Os -fno-toplevel-reorder -fpack-struct=8 -fPIC -fPIE -Iwindows -D_WIN32_WINNT=0x600 -D__USE_MINGW_ANSI_STDIO=0 -o ./output/func_0x00.exe ./main/func_0x00.c