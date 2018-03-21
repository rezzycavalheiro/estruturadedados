#ifndef Pilha_H
#define Pilha_H

struct Pilha
{
    int topo = -1;
    char *dado;
    int MAX;
} p;

Pilha *cria_pilha(int tamanho);

int vazio(Pilha *p);

int cheia(Pilha *p);

int empilha(Pilha *p, char simbolo);

int desempilha(Pilha *p);

char topo(Pilha *p);

#endif
