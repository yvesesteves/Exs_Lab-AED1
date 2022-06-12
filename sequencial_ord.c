#include <stdio.h> 
#include <stdlib.h>
#include "sequencial_ord.h"

#define MAX 20 // tamanho máximo
struct lista{
    int num[MAX];
    int Fim;
};

/*
    Entrada: nenhuma
    Pré Condição: nenhuma
    Processo: colocar a lista na condição de vazia
    Saída: retorna a lista criada
    Pós Condição: criada uma lista vazia
*/
Lista* criar_lista()
{
    Lista *lst;
    lst = (Lista*) malloc(sizeof(struct lista));
    
    if(lst!=NULL)
        lst->Fim=0;
    

    return lst;
} 

/*
    Entrada: recebe endereço da lista
    Pré Condição: nenhuma
    Processo: verificar se a lista esta vazia
    Saída: 1 - lista vazia // 0 - lista não vazia
    Pós Condição: nenhuma
*/
int lista_vazia(Lista *lst){
    if(lst->Fim==0)
        return 1; // Lista vazia
    else
        return 0; // Lista não vazia
}

/*
    Entrada: recebe endereço da lista
    Pré Condição: nenhuma
    Processo: verificar se a lista está cheia
    Saída: 1 se lista cheia // 0 se não
    Pós Condição: nenhuma
*/
int lista_cheia (Lista *lst){
    if (lst->Fim == MAX)
        return 1; // Lista cheia
    else
        return 0; // Lista não está cheia
}

/*
    Entrada: recebe endereço da lista e um elem a ser inserado
    Pré Condição: lista não estar cheia
    Processo: percorrer a lista a partir do primeiro elem, encontrar a posiçao correta
                que o elem sera inserido de forma a garantir a ordenação
    Saída: 1 se sucesso // 0 se falha
    Pós Condição: a lista da entrada com um elem a mais
*/

int insere_elem(Lista *lst,int elem){
    if(lst ==NULL|| lista_cheia(lst)==1)
        return 0;
    
    //trata lista vazia ou elemento >= último da lista
    if(lista_vazia(lst) ==1 || elem >= lst-> num[lst->Fim-1]){
        lst-> num[lst->Fim]= elem;
    }
    else { 
        int i,aux=0;
        while (elem>=lst->num[aux])//percorrimento
            aux++;

        for(i=lst -> Fim; i > aux;i--)//deslocamento
            lst -> num[i]= lst->num[i-1];
        lst ->num[aux]=elem;//inclui o elemento na lista    
    }
    lst -> Fim++;// Avança o Fim
    return 1;
}

/*
    Entrada: endereço da lista e o elem a ser removido 
    Pré Condição: lista não estar vazia
    Processo: percorrer a lista a partir do primeiro elem ate encontrar o elem a ser removido
                ou chegar a um elem maior. Se encontrar o elem, remove-o, se encontrar um elem 
                maior é porque o elem nao pertence a lista
    Saída: 1 se sucesso // 0 falha
    Pós Condição: lista com 1 elem removido
*/

int remove_elem(Lista *lst,int elem){
    if(lst==NULL|| lista_vazia(lst)==1|| elem< lst ->num[0]|| elem>=lst ->num[lst->Fim-1])
        return 0; // falha 
    
    int i,Aux = 0;
    
    // Pecorrimento até achar o elem ou nó maior,ou final de lista
    while (Aux < lst ->Fim && lst ->num[Aux]<elem)
    Aux++;

    if (Aux ==lst->Fim || lst ->num[Aux]> elem)//(não existe elemento)
        return 0; // falha 

    //deslocamento à esq. do sucessor até o final da lista
    for (i= Aux + 1;i<lst->Fim;i++)
        lst -> num[i-1] = lst ->num[i];
    
    lst ->Fim --;// decremento do campo fim
    return 1; // sucesso

    
}

/*
    Entrada: endereço da lista
    Pré Condição: a lista nao deve estar vazia e deve estar alocada
    Processo: percorre a lista e a imprime
    Saída: nenhuma
    Pós Condição: nenhuma
*/

int obtem_valor_elem(Lista *lst){
    // Pecorrimento até o final da lista
    int Aux = 0;
    if(lst==NULL)
        return 0; // falha 
    while (Aux < lst ->Fim){

        printf("%d", lst->num[Aux]);
        Aux++;
    }
    return 1;
}