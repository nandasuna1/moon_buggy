#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "jogo.h"
#include "funcoesdojogo.h"
#include "funcoesconsole.h"
#include "pause.h"
#include "maps.h"
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

void fire(int x, int y, int *countf)
{
    const int v = 2;
    if(*countf != 0)
    {
        if(*countf > 1)
        {
            textcolor(12);
            gotoxy(x+(v*(20-*countf)),y);
            puts("=>");
            textcolor(15);
            gotoxy(x+(v*(20-*countf))+1,y);
            puts(">");
        }
        if(*countf < 20)
        {
            gotoxy(x+v*(19-*countf),y);
            puts("  ");
        }
        *countf -= 1;
        textcolor(11);
    }
}

void jump(int x, int *county, int *countj)
{
    if(*countj != 0 )
    {
        gotoxy(x,*county+26);
        puts("       ");
        gotoxy(x,*county+27);
        puts("       ");
        if(*countj >= 1 && *countj <= 7)
            *county -= 1;
        else if(*countj >= 9 && *countj <= 15)
            *county += 1;

        if(*countj < 15)
            *countj += 1;
        else
            *countj = 0;
    }
}

void quebrar()
{



}
