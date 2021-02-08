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

int jogo(int modo)
{
    //DESCRIÇÃO DE ALGUMAS VARIÁVEIS NO FIM DO CÓDIGO//
    char tecla;
    int countx = 0, county = 0, countf = 0, countj = 0, countm = 0, x1 = 0, y1 = 0, vel = 2, life = 100, score = 0;
    char car1[] = "/||\\__";
    char car2[] = "(/)-(/)";
    char car3[] = "(-)-(-)";
    char car4[] = "(\\)-(\\)";
    char map1a[] = "                              #                            #                           #                         #                         #                                      #                  #                           #                     #                         #                      #                          #            #                              #                    #                            #                     #                        #                 #                                     #                                          #                 #                            #                             #                         #                                    #                     #                                   #                                         #                                           #                    #                              #              #                              ";
    char map1[] = "##########################################       ###############################       #####################################       ##############################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #################################################################################             ###################           ########          ###################                ###################            ####################           ###########################            ########        #########       ########   ###########            ########################     ###########################    ############     #################    #############     #####################     ###########     ########################     ##################       ###############################        ########################    #############   ################   ###############   ######################       ####################       ##################   ############  #################  ############     ###############################################################################################################################################################################################################";
    char map2a[] = "                              #                            #                           #                         #                         #                                      #                  #                           #                     #                         #                      #                          #            #                              #                    #                            #                     #                        #                 #                                     #                                          #                 #                            #                             #                         #                                    #                     #                                   #                                         #                                           #                    #                              #              #                              ";
    char map2[] = "##########################################       ###############################       #####################################       ##############################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #################################################################################             ###################           ########          ###################                ###################            ####################           ###########################            ########        #########       ########   ###########            ########################     ###########################    ############     #################    #############     #####################     ###########     ########################     ##################       ###############################        ########################    #############   ################   ###############   ######################       ####################       ##################   ############  #################  ############     #################";
    char map3a[] = "                              #                            #                           #                         #                         #                                      #                  #                           #                     #                         #                      #                          #            #                              #                    #                            #                     #                        #                 #                                     #                                          #                 #                            #                             #                         #                                    #                     #                                   #                                         #                                           #                    #                              #              #                              ";
    char map3[] = "##########################################       ###############################       #####################################       ##############################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #########################################       #################################################################################             ###################           ########          ###################                ###################            ####################           ###########################            ########        #########       ########   ###########            ########################     ###########################    ############     #################    #############     #####################     ###########     ########################     ##################       ###############################        ########################    #############   ################   ###############   ######################       ####################       ##################   ############  #################  ############     #################";
    while(1)
    {
        ///CHAMA A FUNÇÃO DO CENÁRIO COM O MODO E SEUS RESPECTIVOS MAPAS
        if(modo == 1)
            maps(modo, &countm, &score,countx+3,county+27, &life, map1a,map1,x1,y1,&countf);
        else if(modo == 2)
            maps(modo, &countm, &score,countx+3,county+27, &life, map2a,map2,x1,y1,&countf);
        else if(modo == 3)
            maps(modo, &countm, &score,countx+3,county+27, &life, map3a,map3,x1,y1,&countf);
        ///ESTATUS DO JOGO
        textcolor(11);
        gotoxy(2,1);
        printf("Score: %.i", score);
        gotoxy(16,1);
        printf("Dificuldade: %.i", modo);
        gotoxy(42,1);
        puts("       ");
        gotoxy(35,1);
        printf("Vida: %i/100", life);
        gotoxy(50,1);
        printf("Distancia: %.2fkm", countm * 0.01);
        ///MORRER//----------------------------------------------
        if(life == 0)//SE O CARRINHO MORRER
        {
            if(county < 0)//SE O CARRINHO MORRER NO AR, ELE RETORNA AO CHÃO
            {
                gotoxy(3 + countx, 26 + county);
                puts("       ");
                county++;
            }
            else if(county == 0)//SE O CARRINHO ESTIVER NO CHÃO
            {
                //ANIMAÇÃO DE MORTE
                textcolor(8);
                gotoxy(3+countx,26);
                printf("%c  %c  %c",206,206,206);
                gotoxy(3+countx,27);
                printf("  %c  %c  ", 206,206);
                delay(200);
                gotoxy(3+countx,26);
                printf("  %c  %c  ",206,206);
                gotoxy(3+countx,27);
                printf(" %c     %c", 206,206);
                delay(200);
                gotoxy(3+countx,26);
                printf("    %c    ",206);
                gotoxy(3+countx,27);
                printf("%c     %c ", 206,206);
                delay(200);
                textcolor(15);
                gotoxy(3+countx,26);
                printf("          ");
                gotoxy(3+countx,27);
                printf("          ");
                gotoxy(10+countx,26);
                puts("o");
                delay(150);
                gotoxy(10+countx,26);
                puts(" ");
                gotoxy(12+countx,25);
                puts("o");
                delay(150);
                gotoxy(12+countx,25);
                puts(" ");
                gotoxy(14+countx,26);
                puts("o");
                delay(150);
                gotoxy(14+countx,26);
                puts(" ");
                gotoxy(16+countx,27);
                puts("o");
                delay(150);
                gotoxy(16+countx,27);
                puts(" ");
                gotoxy(18+countx,26);
                puts("o");
                delay(150);
                gotoxy(18+countx,26);
                puts(" ");
                gotoxy(20+countx,27);
                puts("o");
                delay(150);
                gotoxy(20+countx,27);
                puts(" ");
                gotoxy(22+countx,27);
                puts("o");
                delay(150);
                gotoxy(22+countx,27);
                puts(" ");
                gotoxy(24+countx,27);
                puts("o");
                delay(150);
                gotoxy(24+countx,27);
                puts(" ");
                gotoxy(26+countx,27);
                puts("o");
                delay(150);
                gotoxy(26+countx,27);
                puts(" ");
                gotoxy(28+countx,27);
                puts("o");
                pause2(score);//REDIRECIONA PARA A FUNÇÃO "PAUSE2"
                return 1;
            }
        }
        tecla = '|';//"LIMPA" O CACHE DA TECLA PARA EVITAR QUE A MESMA TECLA FIQUE SALVA
        if(kbhit())///VERIFICA SE ALGUMA TECLA ESTÁ PRESSIONADA OU NÃO E PERMITE AO JOGO RODAR MESMO SEM NENHUMA ESTAR
        {
            tecla = getch();//SE ALGUMA TECLA FOR PRESSIONADA, SALVE
        }
        ///ESQUERDA E DIREITA//-----------------------------
        if(tecla == 97 || tecla == 65)
        {
            //APAGA A POSIÇÃO DO CARRINHO ANTES DA MUDANÇA NO X
            gotoxy(3+countx,26+county);
            puts("       ");
            gotoxy(3+countx,27+county);
            puts("       ");
            if(countx > 0)
                countx -= vel;//ALTERA O X DO CARRINHO
        }
        else if(tecla == 100 || tecla == 68)
        {
            //APAGA A POSIÇÃO DO CARRINHO ANTES DA MUDANÇA NO X
            gotoxy(3+countx,26+county);
            puts("       ");
            gotoxy(3+countx,27+county);
            puts("       ");
            if(countx < 105)
                countx = countx + vel;//ALTERA O X DO CARRINHO

        }
        ///FIRE//--------------------------------------------
        if(tecla == 32)
        {
            if(countf == 0)//SE NENHUM TIRO ESTIVER OCORRENDO, PODE ATIRAR NOVAMENTE
            {
                x1 = 8 + countx;//X inicial do tiro
                y1 = county + 27;//Y inicial do tiro
                countf = 20;//CONTADOR DO TIRO COMEÇA EM 20 E VAI ATÉ 0, ISSO HABILITA O TIRO
            }
        }
        ///JUMP//-------------------------------------------
        else if(tecla == 119 || tecla == 87)
        {
            if(county == 0)//SE O CARRINHO ESTIVER NO CHÃO, PODE PULAR NOVAMENTE
            {
                countj = 1;//HABILITA O CONTADOR DO PULO
            }
        }
        ///PAUSE//------------------------------------------
        else if(tecla == 27)
        {
            //system("cls");
            if(pause1() == 0)//REDIRECIONA PARA A FUNÇÃO PAUSE NO MODO 0
                break;
        }
        ///FUNÇÃO FIRE//------------------------------------
        fire(x1,y1,&countf);//RECEBE X,Y E O CONTADOR DO TIRO
        ///FUN플O JUMP//-------------------------------------
        jump(countx+3,&county,&countj);//RECEBE X,Y DO CARRINHO E O CONTADOR DE PULO
        ///IMPRIME O CARRO NA POSIÇÃO COM AS DEVIDAS ALTERA합ES//
        textcolor(9);
        gotoxy(3+countx,26+county);
        puts(car1);//PARTE DE CIMA DO CARRINHO
        gotoxy(3+countx,27+county);
        textcolor(15);
        puts(car2);//MOMENTO 1 DAS RODAS
        delay(15);
        textcolor(15);
        gotoxy(3+countx,27+county);
        puts(car3);//MOMENTO 2 DAS RODAS
        textcolor(15);
        delay(15);
        gotoxy(3+countx,27+county);
        puts(car4);//MOMENTO 3 DAS RODAS
    }

    return 0;
}
///VARIÁVEIS:
//COUNTX E COUNTY SÃO O QUANTO O CARRINHO SE MOVIMENTO EM CADA EIXO, COMEÇANDO NA POSIÇÃO X+3 E Y+27 DA TELA
//COUNTF: CONTADOR DO TIRO
//COUNTJ: CONTADOR DO PULO
//COUNTM: CONTADOR DO MAPA(EQUIVALENTE AOS SEGUNDOS). O CENÁRIO "ANDA" CONFORME AUMENTA
//X1 E Y1 SÃO AS POSIÇÕES INICIAIS DO TIRO, QUE SERÃO AS MESMAS INDEPENDENTE DO CARRINHO SUBIR DESCER OU ANDAR
//VEL: VALOR QUE AUMENTA EM COUNTX(QUANTIDADE DE PIXELS QUE O CARRINHO ANDA POR VEZ)
//LIFE É A VIDA E SCORE É A PONTUAÇÃO
