#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct Tarea {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
}Tarea;

int main(void)
{
    int cantidad , i  ; 
    Tarea ** tareas ;
    char *buff ;

    buff=(char*)malloc(sizeof(char)*100) ;
    do
    {
        printf("\n\nIngrese la cantidad de tareas a realizar");
        scanf("%d" , &cantidad);
    } while (cantidad < 1);

    tareas = (Tarea**) malloc(sizeof(Tarea*)*cantidad);

    for ( i = 0; i < cantidad; i++) {
        tareas[i] = (Tarea*)malloc(sizeof(Tarea));
    }
    /*Desarrolle una interfaz de consola para cargar las tareas, ingresando su
descripción y duración. Recuerde utilizar reserva de memoria dinámica para la
carga de la descripción.*/
    
    for ( i = 0; i < cantidad; i++)
    {
        tareas[i]->TareaID = i + 1 ;
        printf("\nIngrese la tarea #%i\n" , i+1);
        fflush(stdin);
        gets(buff);
        tareas[i]->Descripcion = (char*)malloc(strlen(buff)+1);
        strcpy(tareas[i]->Descripcion , buff);

        printf("Ingrese la duracion \n");
        fflush(stdin);
        scanf("%d", &tareas[i]->Duracion);
        printf("nuevos cambios");
    }
    
    
    

    
    


    return 0;
}


