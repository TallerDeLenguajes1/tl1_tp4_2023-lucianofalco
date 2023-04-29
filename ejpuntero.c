#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reservarUnNumero(int * puntero);
void reservarUnNumeroPDoble(int ** puntero);

int main ()
{
    int * punteroA;
    //reservarUnNumero(punteroA);
    reservarUnNumeroPDoble(&punteroA);
    printf("B - %d", *punteroA); 
    return 0;
}

void reservarUnNumero(int * puntero)
{
    puntero = (int *) malloc(sizeof(int));
    *puntero = 10; 
    printf("A - %d", *puntero); // 11
}


void reservarUnNumeroPDoble(int ** puntero)
{
    *puntero = (int *) malloc(sizeof(int));
    *(*puntero) = 10; 
    printf("A - %d", *(*puntero)); // 11
}