#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
    int x1, x2, y1, y2;
    float distancia;
};

/*
    Entrada: nenhuma
    Pré-condição: nenhuma
    Processo: criar um ponto
    Saída: endereço do ponto criado
    Pós Condição: nenhuma
*/

Ponto *gera_pto(){
    Ponto *p;
    p = (Ponto *)malloc(sizeof(Ponto));
    return p;
}

/*
    Entrada: ponteiro pra p, inteiro de x e y
    Pré Condição: ponto estar alocado
    Processo: atribui os valores das coordenadas para x e y
    Saída: 0 falha, 1 se sucesso
    Pós Condição: valores atribuidos
*/

int set_pto(Ponto *p, int X1, int X2, int Y1, int Y2){
    if(p == NULL)
        return 0;

    p -> x1 = X1;
    p -> x2 = X2;
    p -> y1 = Y1;
    p -> y2 = Y2;
    return 1;
}

 /*
    Entrada: Endereço do endereço de um ponto
    Pré-Condição: ponto estar alocado
    Processo: retornar os valores das coordenadas x e y de um ponto
    Saída: 0 se falha, 1 se sucesso
    Pós-Condição: valores retornados
 */

int get_pto(Ponto *p, int *X1, int *X2 ,int *Y1, int *Y2){
    if(p == NULL)
        return 0; // falha
    
    *X1 = p -> x1;
    *X2 = p -> x2;
    *Y1 = p -> y1;
    *Y2 = p -> y2;
    return 1;   // sucesso
}


/*
    Entrada: Endereço do endereço de um ponto
    Pré-Condição: Nenhuma
    Processo: Liberar a memória usada pelo numero racional e limpar o seu endereço
    Saída: Nenhuma
    Pós-Condição: Ponto liberado
*/

void libera_pto(Ponto **p){
    free(*p);
    *p = NULL;
}

/*
    Entrada: coordenadas dos pontos x e y
    Pré-Condição: nenhuma
    Processo: calcular a distancia entre os dois pontos
    Saída: nenhuma
    Pós-Condição: distancia entre os pontos calculada
*/

float distancia_pto(int x1, int x2, int y1, int y2){
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}