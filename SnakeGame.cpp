#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

void gotoxy(short int x, short int y, string z){
    COORD pos={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
    cout << z;
}

int main()
{
    cout << "Hello Snake!";
    return 0;
}