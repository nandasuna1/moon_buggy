#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "jogo.h"
#include "funcoesdojogo.h"
#include "funcoesconsole.h"
#include "pause.h"
#include "maps.h"
#include <conio.h>
#include <time.h>
#include <windows.h>

void delay(unsigned int ms)
{
    int tempo;
    tempo = ms + clock();
    while (tempo > clock());
}

void gotoxy(int x, int y)
{
   //  printf("%c[%d;%df", 0x1B, y, x);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int textcolor(int color)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    return 0;
}

void cursor(int flag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CURSORINFO;
    GetConsoleCursorInfo(out,&CURSORINFO);
    CURSORINFO.bVisible = flag;
    SetConsoleCursorInfo(out,&CURSORINFO);
    //puts("\e[?25l");
}
