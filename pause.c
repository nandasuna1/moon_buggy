#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "jogo.h"
#include "funcoesdojogo.h"
#include "funcoesconsole.h"
#include <conio.h>
#include <time.h>
#include "ranking.h"

int pause1()
{
    char tecla;
    int count = 0;
    while(1)
    {
        //system("cls");
        while(1)
        {
            textcolor(11);
            gotoxy(54,12+count*2);
            puts(">");
            gotoxy(57,12);
            puts("RETOMAR JOGO");
            gotoxy(58,14);
            puts("COMO JOGAR");
            gotoxy(56,16);
            puts("IR PARA O MENU");
            delay(50);
            do
            {
                tecla = getch();
            }
            while(tecla != 72 && tecla != 80 && tecla != 27 && tecla != 13 && tecla != 87 && tecla != 119 && tecla != 83 && tecla != 115);
            if(tecla == 72 || tecla == 87 || tecla == 119)
            {
                gotoxy(54,12+count*2);
                puts(" ");
                count == 0 ? count = 2 : count--;
            }
            else if(tecla == 80 || tecla == 83 || tecla == 115)
            {
                gotoxy(54,12+count*2);
                puts(" ");
                count == 2 ? count = 0 : count++;
            }
            else if(tecla == 27)
            {
                system("cls");
                return 1;
            }
            else if(tecla == 13)
            {
                system("cls");
                break;
            }
        }
        //RETOMAR JOGO//------------------------------
        if(count == 0)
        {
            system("cls");
            return 1;
        }
        //COMO JOGAR//--------------------------------
        else if(count == 1)
        {
            gotoxy(2,4);
            puts("CONTROLES DO JOGO");
            gotoxy(2,6);
            puts("A - ANDAR PARA ESQUERDA");
            gotoxy(2,8);
            puts("D - ANDAR PARA DIREITA");
            gotoxy(2,10);
            puts("W - PULAR");
            gotoxy(2,12);
            puts("ESPACE BAR - ATIRAR");
            gotoxy(2,14);
            puts("ESC - MENU/PAUSE");
            gotoxy(2,29);
            puts("VOLTAR(ESC)");
            do
            {
                tecla = getch();
            }
            while(tecla != 27);
            system("cls");
            return 1;
        }
        //IR PARA O MENU//----------------------
        else if(count == 2)
        {
            system("cls");
            return 0;
        }
    }
}
int pause2(int score)
{
    int count = 0;
    char tecla;
    while(1)
    {
        textcolor(11);
        gotoxy(54,12+count*2);
        puts(">");
        gotoxy(57,12);
        puts("SALVAR RANKING");
        gotoxy(57,14);
        puts("IR PARA O MENU");
        gotoxy(57,16);
        puts("     SAIR");
        delay(50);
        do
        {
            tecla = getch();
        }
        while(tecla != 72 && tecla != 80 && tecla != 13 && tecla != 87 && tecla != 119 && tecla != 83 && tecla != 115);
        if(tecla == 72 || tecla == 87 || tecla == 119)
        {
            gotoxy(54,12+count*2);
            puts(" ");
            count == 0 ? count = 2 : count--;
        }
        else if(tecla == 80 || tecla == 83 || tecla == 115)
        {
            gotoxy(54,12+count*2);
            puts(" ");
            count == 2 ? count = 0 : count++;
        }
        else if(tecla == 13)
        {
            break;
        }
    }
    //SALVAR RAKING//------------------------------
    if(count == 0)
    {
        saveranking(score);
        return 0;
    }
    //IR PARA O MENU//--------------------------------
    else if(count == 1)
        return 0;
    //SAIR//----------------------------
    else if(count == 2)
        exit(0);
    return 1;
}
