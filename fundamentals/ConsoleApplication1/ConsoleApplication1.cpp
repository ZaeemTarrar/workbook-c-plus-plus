#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <conio.h>
#include<dos.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<iomanip>
#include <string>
#include<string.h>
#include <stddef.h>
#include <cstdlib>
#include <chrono>
#include <thread>
#include<fstream>
#include<math.h>
#include<time.h>
#include <MMSystem.h>

#include "Animal.h"
#include "Helper.h"

using namespace std;

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo); cursorInfo.bVisible = showFlag; SetConsoleCursorInfo(out, &cursorInfo);
}

void InitialProgramConfigurations() {
    system("color 70");
    ShowConsoleCursor(false);
    Helper::CustomConsoleWindowSizeAndPos(500, 500, false); 
    Helper::Sound4();
}

int main(int argc, char* argv[])
{
    InitialProgramConfigurations();

    cin.ignore();

    system("cls");

    return 0;
}