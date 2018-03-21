#include<stdio.h>

int main()
{

int vetor1[30], vetor2[30], vetor_final[60];
int i, j, k, n1, n2;

printf("\nAviso : Eh necessario o vetor ja estar ordenado por ordem crescente");

printf("\n Entre com o numero de elementos do Vetor 1:");
scanf("%d", &n1);

for (i = 0; i < n1; i++)
    {
        scanf("%d", &vetor1[i]);
    }

printf("\nEntre com o numero de elementos do Vetor 2 :");
scanf("%d", &n2);

for (i = 0; i < n2; i++)
    {
    scanf("%d", &vetor2[i]);
    }

i = 0;
j = 0;
k = 0;


 //Começa o algoritmo de Merging
 //O algoritmo divide para ganhar, ele vai separando e comparando
 //os ambos lados para saber quem é maior que quem e inseirndo o vetor

 while (i < n1 && j < n2)
 {
    if (vetor1[i] <= vetor2[j])
    {
        vetor_final[k] = vetor1[i];
        i++;
        k++;
    }
    else
    {
        vetor_final[k] = vetor2[j];
        k++;
        j++;
    }
 }

 /* Alguns elementos na matriz 'arr1' ainda permanecem
 onde como o array 'arr2' está esgotado */

 while (i < n1)
    {
        vetor_final[k] = vetor1[i];
        i++;
        k++;
    }

 /* Alguns elementos na matriz 'arr2' ainda permanecem
 onde como o array 'arr1' está esgotado */

 while (j < n2)
    {
        vetor_final[k] = vetor2[j];
        k++;
        j++;
    }

//Mostra o vetor resultado da fusão entre os dois
printf("\nO vetor final é :");
for (i = 0; i < n1 + n2; i++)
    {
     printf("%d ", vetor_final[i]);
    }

 return (0);

}
