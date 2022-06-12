#include <stdio.h>
#include <stdlib.h>
#include "sequencial_n_ord.h"

int main()
{
    int i;
    int ativo = 0;
    Lista *lst;
    int elem;

    while(ativo != 7){
        printf("\n--------Menu--------\n");
        printf(" Digite [1] para criar uma lista\n");
        printf(" Digite [2] para verificar se a lista esta vazia\n");
        printf(" Digite [3] para verificar se a lista esta cheia\n");
        printf(" Digite [4] inserir um elemento\n");
        printf(" Digite [5] para excluir um elemento\n");
        printf(" Digite [6] para imprimir a lista\n");
        printf(" Digite [7] para sair\n");
        printf(" Opcao: ");
        scanf("%d", &i);
        setbuf(stdin, NULL);

        switch(i){
            case 1:
                lst = criar_lista();
                printf("Lista criada!");
            break;

            case 2:
                if(lista_vazia(lst) == 1){ 
                printf("\n\n A lista esta vazia\n");
                break;
                }else
                    printf("A lista nao esta vazia\n");
                break;

            case 3:
            if(lista_cheia(lst) == 1){
                printf("\n\n A lista esta cheia\n");
                break;
            }else
                printf("A lista nao está cheia\n");
            break;

            case 4:
                scanf("%d", &elem);
                insere_elem(lst, elem);
                printf("\n\n Elemento inserido!\n");
                if(lst == NULL)
                    printf("Erro ao inserir elemento\n");
                break;

            case 5:
                scanf("%d", &elem);
                remove_elem(lst, elem);
                printf("\n\n Elemento removido!\n");
                break;

            case 6:
                obtem_valor_elem(lst);
                break;

            case 7:
                ativo = 7;
                break;


            default:
				printf("\n\n Opcao invalida, digite um numero de 1 a 7\n");
        }

    }
    return 0;
}
