#ifndef SEQUENCIALNORD_H_INCLUDED
#define SEQUENCIALNORD_H_INCLUDED


typedef struct lista Lista;
Lista* criar_lista();
int lista_vazia(Lista *lst);
int lista_cheia(Lista *lst);
int insere_elem(Lista *lst, int elem);
int remove_elem(Lista *lst, int elem);
void obtem_valor_elem(Lista *lst);


#endif