#ifndef Pilha_H
#define Pilha_H

struct Pilha
{
    int topo = -1;
    int *dado;
    int MAX;
    char *simbolo;
} p;

Pilha *cria_pilha(int tamanho);

int vazio(Pilha *p);

int cheia(Pilha *p);

int empilha(Pilha *p, int dado);

int desempilha(Pilha *p);

int topo(Pilha *p);

#endif

/*Implemente do tipo Pilha definindo arquivos Pilha.h e Pilha.cpp. Uma Pilha deve ter a seguinte representação:
Estrutura Pilha

{

            inteiro: topo;   // o índice do elemento no topo da pilha

            inteiro dado[];  // um array para armazenamento de dados que deve ser alocado dinamicamente

            inteiro MAX; // quantidade máxima de elementos

}

As seguintes operações devem ser implementadas:

a) topo(pilha);  // retorna o elemento no topo da pilha

b) vazia(pilha);  // retorna 1 se a pilha está vazia e 0 caso contrário

c) cheia(pilha);  // retorna 1 se a pilha está cheia e 0 caso contrário

d) empilha(pilha, inteiro: elemento)  // coloca o elemento na pilha

e) desempilha(pilha);  // retira e retorna o elemento do topo da pilha

f) cria_pilha(n) // cria e retorna uma pilha capaz de armazenar até n elementos*/
