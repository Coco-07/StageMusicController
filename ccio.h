/*
* ccio.h
* Coco07
* 2020.10.30
*/

#define cprintf(_c_COLOR,...) \
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(_c_COLOR)), \
	printf(__VA_ARGS__), \
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(DEFAULT_COLOR))

#define cprintfex(_c_COLOR,_c_x,_c_y,...) \
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(_c_COLOR)), \
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){_c_y,_c_x}), \
	printf(__VA_ARGS__), \
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),(DEFAULT_COLOR))

#ifndef CONSOLE_H
#define CONSOLE_H

#include <windows.h>
#include <stdio.h>

const int RED = FOREGROUND_RED;
const int GREEN = FOREGROUND_GREEN;
const int BLUE = FOREGROUND_BLUE;
const int WHITE = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE;
const int YELLOW = FOREGROUND_RED|FOREGROUND_GREEN;
const int BRED = BACKGROUND_RED;
const int BGREEN = BACKGROUND_GREEN;
const int BBLUE = BACKGROUND_BLUE;
const int BWHITE = BACKGROUND_RED|BACKGROUND_GREEN|BACKGROUND_BLUE;
const int BYELLOW = BACKGROUND_RED|BACKGROUND_GREEN;
const int FI = FOREGROUND_INTENSITY;
const int BI = BACKGROUND_INTENSITY;
const int DEFAULT_COLOR = FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE;

#endif
