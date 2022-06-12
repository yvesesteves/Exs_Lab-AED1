#include <stdio.h>
#include <stdlib.h>
#include "sequencial_n_ord.h"
#define MAX 20


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

Lista* criar_lista(){
    Lista *lst;
    lst = (Lista *)malloc(sizeof(struct lista));

    if(lst != NULL)
        lst -> Fim = 0;     // lista vazia

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
    if(lst->Fim == 0)
        return 1;   // lista vazia
    else
        return 0;   // lista não vazia
}

/*
    Entrada: recebe endereço da lista
    Pré Condição: nenhuma
    Processo: verificar se a lista está cheia
    Saída: 1 se lista cheia // 0 se não
    Pós Condição: nenhuma
*/

int lista_cheia(Lista *lst){
    if(lst->Fim == MAX)
        return 1;   // lista cheia
    else
        return 0;   // lista não cheia
}

/*
    Entrada: recebe endereço da lista e um elem a ser inserado
    Pré Condição: lista não estar cheia
    Processo: inserir o elemento em um dos extremos
    Saída: 1 se sucesso // 0 se falha
    Pós Condição: a lista da entrada com um elem a mais
*/

int insere_elem(Lista *lst, int elem){
    if(lst == NULL || lista_cheia(lst) == 1)
        return 0;   // falha ao inserir elem
    
    lst -> num[lst->Fim] = elem;    // insere elemento
    lst->Fim++;     // avança ao fim
        return 1;

}

/*
    Entrada: endereço da lista e o elem a ser removido 
    Pré Condição: lista não estar vazia
    Processo: percorrer a lista a partir do primeiro elem até o
        elem desejado ou até o fim da lista e se o elem for encontrado, remover-o da lista
    Saída: 1 se sucesso // 0 falha
    Pós Condição: lista com 1 elem removido
*/

int remove_elem(Lista *lst, int elem){
    if(lst == NULL || lista_vazia(lst) == 1)
        return 0;   // falha
    int i, Aux = 0;

    // Percorrimento até achar o elem ou final da lista
    while(Aux < lst->Fim && lst->num[Aux] != elem)
        Aux++;
    if(Aux == lst->Fim) //Final de lista (elem nao existe)
        return 0;

    for(i = Aux+1; i < lst->Fim; i++)   // deslocamento a esq do sucessor ate o final da lista
        lst->num[i-1] = lst->num[i];

    lst->Fim--; // decremento do campo fim
        return 1;  // sucesso, elemento removido

}

/*
    Entrada: endereço da lista
    Pré Condição: a lista nao deve estar vazia e deve estar alocada
    Processo: percorre a lista e a imprime
    Saída: nenhuma
    Pós Condição: nenhuma
*/




void obtem_valor_elem(Lista *lst){
    if(lst == NULL || lista_vazia(lst))
        printf("\nA lista esta vazia ou nao esta alocada");
    else{
        int aux;
        for(aux = 0; aux < MAX; aux++)
            if(lst->num[aux] != '\0')
                printf("%d\n", lst->num[aux]);
    }

}
