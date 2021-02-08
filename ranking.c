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

typedef struct player
{
    char nome[10];
    int score;
    int pos;
} JOGADORES;

void saveranking(int score)
{
    int n =0,c, d;
    JOGADORES jogador[n];
    FILE *ponteiro;
    gotoxy(78,12);
    puts("> Digite seu nome:");
    gotoxy(97,12);
    scanf("%s",&jogador[n].nome);
    jogador[n].score = score;
    ///ADICIONA O NOVO JOGADOR NA FILE
    ponteiro = fopen("ranking.txt","ab");
    fwrite(&jogador[n],sizeof(JOGADORES),1,ponteiro);
    fclose(ponteiro);
    ///LER OS JOGADORES
    ponteiro = fopen("ranking.txt","rb");
    while(fread(&jogador[n],sizeof(JOGADORES),1,ponteiro)!=NULL)
    {
        n++;
    }
    fclose(ponteiro);
    ///ORDENA OS JOGADORES
    for(c = 0; c < n; c++)
    {
        jogador[c].pos = n;
        for(d=0; d<n; d++)
        {
            if(jogador[c].score > jogador[d].score)
                jogador[c].pos -= 1;
        }
    }
    ///IMPRIME NA FILE, EM ORDEM
    ponteiro = fopen("ranking.txt","wb+");
    for(d = 1; d <= n; d++)
    {
        for(c = 0; c < n; c++)
        {
            if(jogador[c].pos == d)
            {
                fwrite(&jogador[c],sizeof(JOGADORES),1,ponteiro);
            }
        }
    }
    fclose(ponteiro);
}
///EXIBIR DO RANKING---------------------------------------------------------------------
void showranking()
{
    int n = 0,x = 0;
    JOGADORES jogador[n];
    FILE *ponteiro;
    ponteiro = fopen("ranking.txt","rb");
    while(fread(&jogador[n],sizeof(JOGADORES),1,ponteiro)!=NULL)
    {
        gotoxy(4,10+x++);
        printf("%.10s\t\t%i",jogador[n].nome,jogador[n].score);
        n++;
    }
    fclose(ponteiro);
}
