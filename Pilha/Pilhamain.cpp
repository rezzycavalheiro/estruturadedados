#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

//criando a pilha e alocando
Pilha *cria_pilha(int tamanho)
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->dado = (int*)malloc(sizeof(int)*tamanho);
    p->MAX = tamanho;
    p->topo = -1;
    return p;
};

//funcao que verifica se a pilha esta vazia. Se = -1, retorna true
int vazio(Pilha *p)
{
    if(p->topo == -1)
        {
            printf("Pilha vazia!\n ");
            return 1;
        }
    else
        {
        return 0;
        }
}

//verifica se a pilha atingiu o tamanho MAX
int cheia(Pilha *p)
{
    if(p->topo == p->MAX-1)
        //max - 1 = valor maximo -1
        return 1;
    else
        return 0;
}

//push, ou seja, insere na pilha
//int elemento � o valor que vai ser inserido
int empilha(Pilha* p, int elemento){
    if (cheia(p))
        {
        printf("Pilha cheia\n");
        //return false
        return -1;
        }
    else{
        //faz o topo subir, e coloca o elemento em cima
        p->topo++;
        p->dado[p->topo] = elemento;
        return 1;
        }
}

int desempilha(Pilha *p)
{
    //checa se a pilha est� vazia
    if (vazio(p))
    {
        printf("Pilha Vazia");
        return -1;
    }
    else
    {
        int elemento = p->dado[p->topo];
        //retirando o elemento do topo
        p->topo--;
        return elemento;
    }
}

int topo(Pilha *p)
{
    if(!vazio(p))
    {
        return p->dado[p->topo];
    }
    else
    {
        printf("A lista esta vazia");
        return 0;
    }
    printf("Elemento no topo = %d\n", p->topo);
}

int main()
{
    Pilha *p = cria_pilha(20);
    
    int i;
    for(i=0; i<5; i++)
    {
        empilha(p, 10);
        empilha(p, 16);
        empilha(p, 5);
        empilha(p, 7);
    }
    printf("O elemento do topo eh: %d \n", topo(p));

    return 0;
}
