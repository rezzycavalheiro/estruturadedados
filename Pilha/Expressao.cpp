#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Algebrica.h"

//criando a pilha e alocando
Pilha *cria_pilha(int tamanho)
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->dado = (char*)malloc(sizeof(char)*tamanho);
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
//int elemento é o valor que vai ser inserido
int empilha(Pilha* p, char elemento){
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
    //checa se a pilha está vazia
    if (vazio(p))
    {
        printf("Pilha Vazia");
        return -1;
    }
    else
    {
        char elemento = p->dado[p->topo];
        //retirando o elemento do topo
        p->topo--;
        return elemento;
    }
}

char topo(Pilha *p)
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
    //printf("Elemento no topo = %d\n", p->topo);
}


int main()
{
    Pilha *p = cria_pilha(20);

    char expressao[30];
    printf("Expressao: ");
    scanf("%s", &expressao);
    //printf("%s \n", expressao);

    /*int i;
    for(i=0; i<5; i++)
    {
        empilha(p, 10);
        empilha(p, 16);
        empilha(p, 5);
        //empilha(p, 7);
    }
    printf("O elemento do topo eh: %d \n", topo(p));
    */

    int j, n;
    for(j=0; j<30; j++)
    {
        if (expressao[j] == '(' || expressao[j] == '{' || expressao[j] == '[')
        {
            empilha(p, expressao[j]);
        }
    }
    for(n=30; n>0; n--)
    {
        if(expressao[n] == ')' || expressao[n] == '}' || expressao[n] == ']')
        {
            if ((expressao[n] == '}' && topo(p) == '{') || (expressao[n] == ']' && topo(p) == '[')
            || (expressao[n] == ')' && topo(p) == '('))
            {
            desempilha(p);
            }
        }
    }

    if(vazio(p))
    {
        printf("Funcao valida! \n");
        return 1;
    }
    else if (!(vazio(p)))
    {
        printf("O elemento do topo eh: %c \n Funcao invalida.", topo(p));
        return 0;
    }

    //return 0;
}
