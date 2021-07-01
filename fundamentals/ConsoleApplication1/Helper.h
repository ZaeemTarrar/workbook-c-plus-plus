#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include <MMSystem.h>
#include <stddef.h>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

class Helper
{

	private:
		enum colors {
			BLACK = 0, RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, GREY,
			LIGHTGREY, LIGHTRED, LIGHTGREEN, LIGHTYELLOW, LIGHTBLUE,
			LIGHTPURPLE, LIGHTCYAN, WHITE, DEFAULT
		};

	public:
		Helper() {
			cout << "Helper Created !" << endl;
		}
        static void Sound1() {
            try {
                bool played = PlaySound(TEXT("Sounds\\beep-1.mp3"), NULL, SND_FILENAME | SND_ASYNC);
                cout << "Played: " << played;
            }
            catch (exception error) {
                cout << "Error";
            }
        }
        static void Sound2() {
            cout << "\a";
        }
        static void Sound3() {
            cout << "\7";
        }
        static void Sound4() {
            Beep(1000, 1000);
        }
		static void COLOR(string text = "", int k = 15) {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, k);
			cout << k << "\b\b\b" << text << "\n";
		}
		static void Wait(int seconds) {
			cout.flush();
			this_thread::sleep_for(chrono::milliseconds(seconds * 1000));
		}
		static void gotoxy(short x, short y)
		{
			COORD pos = { x, y };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		}
		static void CustomConsoleWindowSizeAndPos(int x, int y, bool details) {
            int screenWidth = GetSystemMetrics(SM_CXSCREEN);
            int screenHeight = GetSystemMetrics(SM_CYSCREEN);
            if (details) {
                cout << "Screen Width: " << screenWidth << endl;
                cout << "Screen Height: " << screenHeight << endl;
            }
            HWND console = GetConsoleWindow();
            RECT ConsoleRect;
            GetWindowRect(console, &ConsoleRect);
            if (details) {
                cout << "Console Left: " << ConsoleRect.left << endl;
                cout << "Console Right: " << ConsoleRect.right << endl;
                cout << "Console Top: " << ConsoleRect.top << endl;
                cout << "Console Bottom: " << ConsoleRect.bottom << endl;
            }
            int centerX = screenWidth / 2;
            int centerY = screenHeight / 2;
            if (details) {
                cout << "Screen Center X: " << centerX << endl;
                cout << "Screen Center Y: " << centerY << endl;
            }
            int consoleWidth = ConsoleRect.right - ConsoleRect.left;
            int consoleHeight = ConsoleRect.bottom - ConsoleRect.top;
            if (details) {
                cout << "Console Width: " << consoleWidth << endl;
                cout << "Console Height: " << consoleHeight << endl;
            }
            if (details) {
                cout << "Custom Width: " << x << endl;
                cout << "Custom Height: " << y << endl;
            }
            MoveWindow(console, centerX - (x / 2), centerY - (y / 2), x, y, TRUE);
        }
};

