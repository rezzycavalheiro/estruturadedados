#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define inf INFINITY

typedef struct vertice{
    char nome[20];
}Vertice;

typedef struct grafo{
    int tamanho;
    float **matriz;
    Vertice *vertices;
}Grafo;

Grafo* cria_grafo(int tamanho){

Grafo* g = (Grafo*)malloc(sizeof(Grafo)*tamanho);
g->tamanho = tamanho;
g->matriz = (float**)malloc(tamanho * sizeof(float*));

//alocacao de cada uma das linhas da matriz
for(int i = 0; i < tamanho; i++)
		g->matriz[i] = (float*)malloc(tamanho* sizeof(float));

g->vertices = (Vertice*)malloc(sizeof(Vertice)*tamanho);

for(int j = 0; j< tamanho; j++){
    for (int k = 0; k< tamanho; k++){
        g->matriz[j][k] = inf;
    }
}
return g;
}

void cria_adjacencia(Grafo* g, int i, int j, float peso){
   g->matriz[i][j] = peso;

}

void remove_adjacencia(Grafo* g, int i, int j){
    g->matriz[i][j] = inf;
}

int adjacentes(Grafo* g, int i, int* v){
   int quantidade = 0;
   for(int count  = 0; count < g->tamanho; count++){
        if(g->matriz[i][count] != 0){
            v[quantidade] = count;
             quantidade++;
        }
   }

return quantidade;
}

int grafo_vazio(Grafo* g){
    int i, j, quantidade = 0;
    for (i = 0; i < g->tamanho; i++){
        for (j = 0; j < g->tamanho; j++){
            if(g->matriz[i][j] != 0){
                quantidade++;
            }
        }
    }
    if (quantidade == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void seta_informacao(Grafo* g, int i, char* s){
     strcpy(g->vertices[i].nome , s);
}

void imprime(Grafo* g){
    for (int count = 0; count < g->tamanho; count++){
        printf("Vertices: %s\n", g->vertices[count].nome);
    }

    int i, j;
    for(i=0;i<g->tamanho;i++)
    {
       for(j=0;j<g->tamanho;j++)
       {
           printf("%lf\t", g->matriz[i][j]);
       }
       printf("\n");
   }
   printf("\n");
}

void copiaadjacencia(Grafo* g, Grafo* A1, int linha){
    for(int i = 0; i < g->tamanho; ++i){
        A1->matriz[linha][i] = g->matriz[linha][i];
        A1->matriz[i][linha] = g->matriz[linha][i];
    }

}

int TemPerm(int menor_j, int *Perm, int tamanho){
    printf("MENOR J %d\n\n", menor_j);
    for(int i = 0; i < tamanho; ++i){
        printf("%d, ", Perm[i]);
    }
    printf("\n");
    for(int i = 0; i < tamanho; ++i){
        printf("Perm: %d", Perm[i]);
        if(Perm[i] == menor_j){
            printf("negado\n");
            return 1;
        }

    }
     printf("permitido\n");
     return 0;
}

int copiamenoraresta(Grafo* A1, Grafo* A, int *Perm){
    int menor_i = inf;
    int menor_j = inf;
    int menor_peso = inf;
    for(int i = 0; i < A1->tamanho; ++i){
        for(int j = 0; j < A1->tamanho; ++j){
            if(A1->matriz[i][j] < menor_peso){
                menor_peso = A1->matriz[i][j];
                menor_i = i;
                menor_j = j;

            }
        }
    }

    if(menor_i < A1->tamanho){
        if(TemPerm(menor_j, Perm, A->tamanho)){
            printf("entrou aqui\n");
            remove_adjacencia(A1, menor_i, menor_j);
            return -20;
        }
        else{
        A->matriz[menor_i][menor_j] = menor_peso;
        remove_adjacencia(A1, menor_i, menor_j);
        return menor_j;

        }
    }

}

Grafo* PRIM(Grafo* g){
    int v1 = 0;
    int v = 0;
    int j = 1;

    //calcula todos os adjacentes
    int Perm[g->tamanho];
    for(int i = 0; i < g->tamanho; ++i){
        Perm[i] = -30;
    }
    Perm[0] = v;
    Grafo* A = cria_grafo(g->tamanho);
    Grafo* A1 = cria_grafo(g->tamanho);
    while(j < g->tamanho){
        printf("j: %d\n", j);
        //grafo g, grafo A e linha
        copiaadjacencia(g, A1, v);
        v1 = copiamenoraresta(A1, A, Perm);
        while(v1 == -20){
            v1 = copiamenoraresta(A1, A, Perm);
        }
        Perm[j] = v1;
        v = v1;
        j++;
    }
    printf("\n");
    for(int i = 0; i < g->tamanho; ++i){
        printf("%d, ", Perm[i]);
    }
    printf("\n");
    return A;
}

int opcao(void)
{
	int esc;

	printf("Escolha\n");
	printf("2. Cria Adjacencia\n");
	printf("3. Remove Adjacencia\n");
    printf("4. Imprime Grafo\n");
    printf("5. Seta Informacao\n");
    printf("6. PRIM\n");
	printf("Escolha: ");
	scanf("%d", &esc);

	return esc;
}

void opcao_escolhida(Grafo* g,Grafo* prim, int tamanho, int esc)
{

int i = 0;
int j = 0;
char nome[20];
float peso = 0.0;
	switch(esc){

		case 2:
		    system("cls");
		    printf("Digite a linha: ");
		    scanf("%d", &i);
		    printf("Digite a coluna: ");
		    scanf("%d", &j);
		    printf("Digite o peso ");
		    scanf("%f", &peso);
            cria_adjacencia(g,i,j,peso);
			break;

		case 3:
		    system("cls");
		    printf("Digite a linha: ");
		    scanf("%d", &i);
		    printf("Digite a coluna: ");
		    scanf("%d", &j);
            remove_adjacencia(g, i, j);
			break;

		case 4:
		    system("cls");
            imprime(g);
			break;
        case 5:
            system("cls");
            printf("Digite a linha que deseja mudar: ");
            scanf("%d", &i);
            printf("Digite o nome que deseja dar: ");
            scanf("%s", &nome);
            seta_informacao(g, i, nome);
			break;
        case 6:
            system("cls");
            prim = PRIM(g);
            imprime(prim);
			break;

		default:
			printf("Sair!\n");
	}
}

int main(){


int tamanho = 0;
    printf("Infome o tamanho: ");
    scanf("%d", &tamanho);
    Grafo* g = cria_grafo(tamanho);
    Grafo* prim = cria_grafo(tamanho);
    printf("Digite os nomes dos vertices: ");
    printf("\n");
    for(int i = 0; i < tamanho; i++){
        printf("%dº Vertice: ", i);
        scanf("%s", g->vertices[i].nome);
    }
     printf("Grafo criado!\n");

    cria_adjacencia(g,0,1,2);
    cria_adjacencia(g,0,2,6);
    cria_adjacencia(g,0,4,3);
    cria_adjacencia(g,0,5,6);
    cria_adjacencia(g,5,6,1);
    cria_adjacencia(g,5,4,4);
    cria_adjacencia(g,6,7,4);
    cria_adjacencia(g,6,1,2);
    cria_adjacencia(g,1,2,5);
    cria_adjacencia(g,4,7,2);
    cria_adjacencia(g,4,3,1);
    cria_adjacencia(g,3,2,3);
    cria_adjacencia(g,2,7,3);
    prim = PRIM(g);
    imprime(prim);

     /*int esc = 0;
        while (esc != 7){
            esc = opcao();
            opcao_escolhida(g, prim, tamanho, esc);

        }
    */

return 0;
}
