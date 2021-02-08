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
#include "ranking.h"

int menu(int *modo)
{
    char tecla;
    int count = 0;
    while(1)
    {
        system("cls");
        while(1)
        {
            gotoxy(32, 4);
            puts("##### ##### ##### ##  #   ####  #   # #####  #####  #   #");
            gotoxy(32,5);
            puts("# # # #   # #   # ##  #   #   # #   # #      #       # #");
            gotoxy(32,6);
            puts("# # # #   # #   # # # #   ####  #   # #  ##  #  ##    #");
            gotoxy(32,7);
            puts("# # # #   # #   # #  ##   #   # #   # #   #  #   #    #");
            gotoxy(32,8);
            puts("# # # ##### ##### #  ##   ####  ##### #####  #####    #");
            //--------------------------------------------------------------------------------------------------
            gotoxy(54,12+count*2);
            puts(">");
            gotoxy(59,12);
            puts("JOGAR");
            gotoxy(57,14);
            puts("COMO JOGAR");
            gotoxy(58,16);
            puts("RANKING");
            gotoxy(58,18);
            puts("CREDITOS");
            gotoxy(56,20);
            puts("SAIR DO JOGO");
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
                count == 0 ? count = 4 : count--;
            }
            else if(tecla == 80 || tecla == 83 || tecla == 115)
            {
                gotoxy(54,12+count*2);
                puts(" ");
                count == 4 ? count = 0 : count++;
            }
            else if(tecla == 13)
            {
                system("cls");
                break;
            }
        }
        //JOGAR//
        switch (count)
        {
        case 0:
        {
            gotoxy(4,6);
            puts("DIFICULDADE");
            gotoxy(4,8);
            puts("[1]FACIL");
            gotoxy(4,10);
            puts("[2]NORMAL");
            gotoxy(4,12);
            puts("[3]DIFICIL");
            gotoxy(2,29);
            puts("VOLTAR(ESC)");
            do
            {
                tecla = getch();
            }
            while(tecla != 49 && tecla != 50 && tecla != 51 && tecla != 27);
            if(tecla == 49)
            {
                system("cls");
                return *modo = 1;

            }
            if(tecla == 50)
            {
                system("cls");
                return *modo = 2;

            }
            if(tecla == 51)
            {
                system("cls");
                return *modo = 3;

            }
            else if(tecla == 27)
            {
                break;
            }
            break;
        }
        //COMO JOGAR//
        case 1:
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
            break;
        }
        //RANKING//
        case 2:
        {
            showranking();
            gotoxy(3,2);
            puts("Ranking");
            gotoxy(4,8);
            puts("Nome\t\tScore");
            gotoxy(1,10);
            puts("1. ");
            gotoxy(1,11);
            puts("2. ");
            gotoxy(1,12);
            puts("3. ");
            gotoxy(1,13);
            puts("4. ");
            gotoxy(1,14);
            puts("5. ");
            gotoxy(2,29);
            puts("VOLTAR(ESC)");
            do
            {
                tecla = getch();
            }
            while(tecla != 27);
            count = 0;//CORRIGE UM BUG QUE A SETA VAI PARA O CANTO DA TELA, NÃO SEI POR QUE
            break;
        }
        //CREDITOS//
        case 3:
        {
            gotoxy(52,4);
            puts("ALBERTO MOURA");
            gotoxy(50,6);
            puts("FERNANDA DE PINHO");
            gotoxy(51,8);
            puts(" GEORGE VIEIRA");
            gotoxy(55,10);
            puts(" ERICK");
            gotoxy(51,22);
            puts("PROJETO DE LPI");
            gotoxy(53,24);
            puts("MOON BUGGY");
            gotoxy(2,29);
            puts("VOLTAR(ESC)");
            do
            {
                tecla = getch();
            }
            while(tecla != 27);
            break;
        }
        //SAIR DO JOGO//
        case 4:
        {
            exit(0);
        }
        }
    }
    return 0;
}
