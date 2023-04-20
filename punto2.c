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
        int contador ; 
    Tarea ** tareaspendientes ;
    Tarea **tareasRealizadas;
    char *buff ;

    buff=(char*)malloc(sizeof(char)*100) ;
    do
    {
        printf("\n\nIngrese la cantidad de tareas a realizar");
        scanf("%d" , &cantidad);
    } while (cantidad < 1);

    tareaspendientes = (Tarea**) malloc(sizeof(Tarea*)*cantidad);
    tareasRealizadas = (Tarea**) malloc(sizeof(Tarea*)*cantidad);
    

    for ( i = 0; i < cantidad; i++) {
        tareaspendientes[i]=NULL;
        tareasRealizadas[i]=NULL;
        tareaspendientes[i] = (Tarea*)malloc(sizeof(Tarea));
    }
    /*Desarrolle una interfaz de consola para cargar las tareas, ingresando su
descripción y duración. Recuerde utilizar reserva de memoria dinámica para la
carga de la descripción.*/
    
    for ( i = 0; i < cantidad; i++)
    {
        tareaspendientes[i]->TareaID = i + 1 ;
        printf("\nIngrese la tarea #%i\n" , i+1);
        fflush(stdin);
        gets(buff);
        tareaspendientes[i]->Descripcion = (char*)malloc(strlen(buff)+1);
        strcpy(tareaspendientes[i]->Descripcion , buff);

        printf("Ingrese la duracion \n");
        fflush(stdin);
        scanf("%d", &tareaspendientes[i]->Duracion);
    }
    
    /*4. Una vez cargada todas las tareas. Irá listando de a una las tareas y
preguntando si se realizó o no la misma. Si la respuesta es Si tiene que
“mover” dicha tarea a otro arreglo denominado tareas realizadas que tendrá el
mismo tamaño que el anterior. Una vez movida la tarea ese casillero del vector
tiene que apuntar a null. Como se muestra en la gráfica a continuación.*/
    contador = 0 ;

    for ( i = 0; i < cantidad; i++)
    {
        int desicion ; 
        printf("\nPresione 1) si realizo la area y presione 2) si no realizo aun la tarea , '%s'\n", tareaspendientes[i]->Descripcion);
        printf("Duracion: %d\n",tareaspendientes[i]->Duracion);
        scanf("%d" , &desicion);
        if (desicion==1)
        {
            tareasRealizadas[i]=tareaspendientes[i];
            tareaspendientes[i]=NULL;
        }       
    }
    
    printf("\nTareas realizadas:\n");
    for ( i = 0; i < cantidad ; i++)
    {
        if (tareasRealizadas[i] != NULL)
        {
            printf("Tarea #%i , %s\n" , i+1 ,tareasRealizadas[i]->Descripcion);
            contador = contador+1 ; 
        }
    }
    printf("\nLas tareas realizadas son: %i\n" , contador);
    
    printf("\ntareas pendientes");
    contador = 0 ;

    for (i = 0; i < cantidad; i++)
    {
        if (tareaspendientes[i] != NULL)
        {
            printf("Tarea #%i , %s\n" , i+1 ,tareaspendientes[i]->Descripcion);
            contador = contador+1 ; 
        }
        
        printf("Tarea #%i , %s\n" , i+1 ,tareaspendientes[i]->Descripcion);
        contador = contador+1 ;     
    }
    printf("\nLas tareas realizadas son  %d \n " , contador);
    return 0;
}


