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

int main()
{
    int modo;
    system("color a");
    while(1)
    {
        textcolor(11);
        //puts("\e[?25l");//TROCA ISSO
        cursor(0);
        system("MODE con: cols=130 lines=31");
        menu(&modo);
        jogo(modo);
    }
    return 0;
}
