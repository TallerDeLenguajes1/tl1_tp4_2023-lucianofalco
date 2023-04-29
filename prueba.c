#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct persona{
    int edad ; 
    char *nombre;
    float medida ; 
    char letra ; 
}persona ; 

int main(int argc, char const *argv[])
{
    int tamaño ;
    persona * a ; 
    tamaño = sizeof(a); 
    printf("%d", tamaño);
    return 0;
}
