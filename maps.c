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

char maps(int modo, int *countm, int *score,int x,int y,int *life, char *map1,char *map2,int xf,int yf,int *countf)
{
    int n, u, z;
    const int vel = 1;
    textcolor(122);
    gotoxy(0,29);
    puts("                                                                                                                        ");
    ///MAP1--------------------------------------------------------------------------------------------------------
    for(n = 0; n < 120; n++)
    {
        gotoxy(0+n,28);///Vai pra posição que vai printar cada caracter do chão
        if(map2[*countm+n] == 35)///Se for 1 #, substitua por um espaço colorido
        {
            textcolor(122);
            puts(" ");
        }
        else
        {
            textcolor(320);
            puts(" ");
        }
        ///OBSTACULOS---------------------------------------------------------------------------------------
        if(map1[*countm+n] == 35)
            for(u = 0; u < 3; u++)
            {
                {
                    textcolor(122);
                    gotoxy(n,27-u);
                    puts(" ");
                    textcolor(0);
                    if(n < 120-vel)
                    {
                        gotoxy(n+vel,27-u);
                        puts(" ");
                    }
                    for(z = 0; z < vel; z++)
                        if(map1[*countm-vel+z] == 35)
                        {
                            gotoxy(z,27-u);
                            puts("  ");
                            break;
                        }
                }
            }
    }
    textcolor(0);///Limpa as cores
    ///VERIFICADOR LAVA
    for(u = 0; u < 7; u++)///CONTADOR DO TAMANHO DO CARRINHO
    {
        if(y == 27 && map2[x+u+*countm] != 35)///VERIFICA SE ALGUMA DAS 7 PARTES DO CARRINHO ESTÁ EM CIMA DA LAVA
        {
            if(*life - 5 > 0)
            {
                *life -= 5;
                break;
            }
            else
                *life = 0;
            break;
        }
    }
    ///CARRINHO E OBSTACULOS
    for(u = 0; u < 7; u++)
    {
        if(y >= 25 && y <= 27 && map1[x+u+*countm] == 35)
        {
            textcolor(0);
            map1[x+u+*countm] = ' ';
            for(n = 0; n <3; n++)
            {
                for(z = 0; z <= vel+2; z++)
                {
                gotoxy(x+3+z,27-n);
                puts(" ");
                }
            }
            if(*life - 20 > 0)
                *life -= 20;
            else
            {
                *life = 0;
                break;
            }
        }
    }
    ///TIRO E OBSTACULOS
    for(u=1; u<=vel+2; u++)
    {
        if(map1[xf+2*(20-*countf)+*countm-u] == 35 && *countf != 0 && yf >= 25)
        {
            textcolor(0);
            map1[xf+2*(20-*countf)+*countm-u] = ' ';
            gotoxy(xf+2*(20-*countf)-2,yf);
            puts("  ");
            for(n=0; n<3; n++)
            {
                gotoxy(xf+2*(20-*countf)-u,27-n);
                printf(" ");
            }
            *countf = 0;
            *score += 20;
            break;
        }
    }
    *countm += vel;///Aumenta o contador do mapa. Quanto maior o numero, maior a velocidade
    *score += modo;
    if(*countm + 120 >= strlen(map2))
        return pause2(*score);
    return 1;
}
