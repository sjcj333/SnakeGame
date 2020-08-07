#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <queue>
#include <cstdlib>
#include <ctime>

using namespace std;

#define mapWidth 40
#define mapHeight 21

#define DRKEY 224

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

/*
ºó °ø°£: 0
¹ì: ¡á 1
¸Ê Å×µÎ¸®: ¡à 2
»ç°ú: ¡Ý 3
*/

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y, string z, int color=15)
{
    COORD Pos;
    Pos.X = x*2;
    Pos.Y = y;
    setColor(color);
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
    cout << z;
}

int map[mapHeight][mapWidth] = {
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}
};

int snake[mapHeight][mapWidth] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int tails;
int snakeDr;
int beforeDr;
int appleCrash;
int appleX=1;
int appleY=1;
int speed;
int start;

queue<int> snakePosX;
queue<int> snakePosY;

void gameInit(){
    for (int i=0; i<mapHeight; i++){
        for (int j=0; j<mapWidth; j++){
            snake[i][j] = 0;
        }
    }
    while (!snakePosX.empty() && !snakePosY.empty()){
        snakePosX.pop();
        snakePosY.pop();
    }
    tails = 4;
    snakePosX.push(20); snakePosX.push(20); snakePosX.push(20); snakePosX.push(20);
    snakePosY.push(6); snakePosY.push(7); snakePosY.push(8); snakePosY.push(9);
    snakeDr = DOWN;
    beforeDr=DOWN;
    appleCrash = 1;
    start  = 1;
    speed = 100;
}

void setSnakeDr(){
    if (kbhit()){
        int press = _getch();
        if (press=DRKEY){
            press = _getch();
            if ((press==UP&&beforeDr!=DOWN) || (press==DOWN&&beforeDr!=UP) ||
            (press==LEFT&&beforeDr!=RIGHT) || (press==RIGHT&&beforeDr!=LEFT)){
                switch(press){
                    case UP: snakeDr = UP; beforeDr = UP; break;
                    case DOWN: snakeDr = DOWN; beforeDr = DOWN; break;
                    case LEFT: snakeDr = LEFT; beforeDr = LEFT; break;
                    case RIGHT: snakeDr = RIGHT; beforeDr = RIGHT; break;
                }
            }
        }
    }
}

void drawMap(){
    for (int j=0; j<mapHeight; j++){
        for (int i=0; i<mapWidth; i++){
            if (map[j][i]==2){
                gotoxy(i, j, "¡à", 15);
            }
        }   
    }
}

void drawSnake(){
    for (int j=0; j<mapHeight; j++){
        for (int i=0; i<mapWidth; i++){
            if (snake[j][i]==1){
                gotoxy(i, j, "¡á", 10);
            }
        }   
    }
}

void drawApple(){
    for (int j=0; j<mapHeight; j++){
        for (int i=0; i<mapWidth; i++){
            if (map[j][i]==3){
                gotoxy(i, j, "¡Ý", 12);
            }
        }   
    }
}

void addTails(){
    switch(snakeDr){
        case UP: snakePosX.push(snakePosX.back()); snakePosY.push(snakePosY.back()-1); break;
        case DOWN: snakePosX.push(snakePosX.back()); snakePosY.push(snakePosY.back()+1); break;
        case RIGHT: snakePosX.push(snakePosX.back()+1); snakePosY.push(snakePosY.back()); break;
        case LEFT: snakePosX.push(snakePosX.back()-1); snakePosY.push(snakePosY.back()); break;
    }
    tails++;
}

void moveSnake(){
    if (!appleCrash){
        snake[snakePosY.front()][snakePosX.front()]=0;
        gotoxy(snakePosX.front(), snakePosY.front(), " ");
        if (snakeDr == UP){
            snakePosY.push(snakePosY.back()-1);
            snakePosX.push(snakePosX.back());
        }
        else if (snakeDr == DOWN){
            snakePosY.push(snakePosY.back()+1);
            snakePosX.push(snakePosX.back());
        }
        else if (snakeDr == LEFT){
            snakePosX.push(snakePosX.back()-1);
            snakePosY.push(snakePosY.back());
        }
        else if (snakeDr == RIGHT){
            snakePosX.push(snakePosX.back()+1);
            snakePosY.push(snakePosY.back());
        }
        snakePosX.pop();
        snakePosY.pop();
    }
    else if (appleCrash){
        if (!start){addTails();}
        else{start=0;}
    }
}

void addSnake(){
    queue<int> snakeX;
    queue<int> snakeY;
    while (!snakePosX.empty()){
        snake[snakePosY.front()][snakePosX.front()] = 1;
        snakeX.push(snakePosX.front());
        snakeY.push(snakePosY.front());
        snakePosX.pop();
        snakePosY.pop();
    }
    while (!snakeX.empty()){
        snakePosX.push(snakeX.front());
        snakePosY.push(snakeY.front());
        snakeX.pop();
        snakeY.pop();
    }
}

int snakeCrash(){
    queue<int> snakeXX;
    queue<int> snakeYY;
    int snakeX[tails];
    int snakeY[tails];
    for (int i=0; i<tails; i++){
        for (int j=0; j<tails; j++){
            if (snakePosX.front() == snakeX[j] && snakePosY.front() == snakeY[j]){
                appleCrash = 0;
                return 1;
            }
        }
        snakeX[i] = snakePosX.front();
        snakeY[i] = snakePosY.front();
        snakeXX.push(snakePosX.front());
        snakeYY.push(snakePosY.front());
        snakePosX.pop();
        snakePosY.pop();
    }
    while (!snakeXX.empty()){
        snakePosX.push(snakeXX.front());
        snakePosY.push(snakeYY.front());
        snakeXX.pop();
        snakeYY.pop();
    }

    if (map[snakePosY.back()][snakePosX.back()]==2){
        appleCrash = 0;
        return 1;
    }
    else if (map[snakePosY.back()][snakePosX.back()]==3){
        appleCrash = 1;
        return 0;
    }
    else{
        appleCrash = 0;
        return 0;
    }
}

void addApple(){
    if (appleCrash){
        map[appleY][appleX] = 0;
        while(1){
            appleX = rand()%mapWidth-1;
            appleY = rand()%mapHeight-1;
            if (map[appleY][appleX] != 2 && snake[appleY][appleX] != 1){
                map[appleY][appleX] = 3;
                break;
            }
        }
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    gameInit(); start  = 0;
    drawMap();
    while (1)
    {
        setSnakeDr();
        addSnake();
        addApple();
        if(snakeCrash()){break;}
        drawApple();
        drawSnake();
        moveSnake();
        Sleep(speed);
    }
    _getch();
    return 0;
}