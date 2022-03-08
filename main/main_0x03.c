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
		LOG_PRINT("[*] Usage: main_0x03.exe \"DD MMM\"\n");
	}

	else
	{
		stringToDouble(argc[1]);
	}
	
	return 0;
}

// Windows:
// x86_64-w64-mingw32-gcc -o ./output/main_0x03.exe ./main/main_0x03.c
// c:/> main_0x03.exe "26 MAR"

// Linux
// gcc -o ./output/main_0x03 ./main/main_0x03.c
// ~$ .main_0x03 "26 March"