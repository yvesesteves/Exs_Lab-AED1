#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

typedef struct ponto Ponto;

Ponto *gera_pto();
int set_pto(Ponto *p, int X1, int X2, int Y1, int Y2);
int get_pto(Ponto *p, int *X1, int *X2 ,int *Y1, int *Y2);
void libera_pto(Ponto **p);
float distancia_pto(int x1, int x2, int y1, int y2);

#endif 
