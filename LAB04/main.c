#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"


int main(){
    int i = 0;
    int ativo = 0;
    Ponto *gera_pto();
    int x1,x2,y1,y2;
    float distancia;
    Ponto *P;

    while(ativo != 4){
        printf("\n--------Menu--------\n");
        printf(" Digite [1] para criar uma instância de um ponto sem valores:\n");
        printf(" Digite [2] para eliminar um ponto criado:\n");
        printf(" Digite [3] para calcula a distância entre dois pontos:\n");
        printf(" Digite [4] para fechar o programa:\n");

        scanf("%d", &i);
        setbuf(stdin, NULL);
    

    switch(i){
        case 1:
            P = gera_pto();
            if(P == NULL){
                printf("Erro na alocacao dos pontos");
                break;
            }else
                printf("Pontos criados!\n");
                break;
        
        case 2:
            libera_pto(&P);
            if(P == 0)
                printf("Ponto liberado!\n");
                break;

        case 3:
            printf("\nInforme as cordenadas para o primeiro ponto\n");
            scanf("%d %d", &x1, &x2);
            printf("\nInforme as cordenadas para o segundo ponto\n");
            scanf("%d %d", &y1, &y2);
            distancia = distancia_pto(x1,x2,y1,y2);
            printf("A distancia entre os pontos eh de %1.f ", distancia);
            printf("\n");
                break;

        case 4:
            ativo = 4;
            break;

        default:
            printf("\nOpcao invalida, digite um numero de 1 a 4\n");
    }

    }

    return 0;
}
