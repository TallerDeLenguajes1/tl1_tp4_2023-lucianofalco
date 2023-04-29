#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct  Tarea{
int TareaID; //Numerado en ciclo iterativo
char *Descripcion;
int Duracion; // entre 10 – 100
}Tarea;

int cantidad ();
void AsignarTareas(Tarea **tarea , int Cantidad);
void IniciarNull(Tarea** tarea , int cantidad);
void MostrarTareas(Tarea** tarea , int Cantidad);
void ListarTareasRealizadas(Tarea **tareaPendiente , int cantidad , Tarea **tareaRealizada);

int main(int argc, char const *argv[])
{   
    int n ; 
    n=cantidad();
    Tarea ** TareaRealizada = (Tarea**) malloc(sizeof(Tarea*)*n);;
    Tarea ** TareaPendiente = (Tarea**) malloc(sizeof(Tarea*)*n);
    AsignarTareas(TareaPendiente , n);
    ListarTareasRealizadas(TareaPendiente , n , TareaRealizada);

    return 0;
}

void ListarTareasRealizadas(Tarea **tareaPendiente , int cantidad , Tarea **tareaRealizada){
    int opcion, contadorrealizadas= 0 , contadorPendientes= 0  ; 
    printf("\nMarque 1 si realizo la tarea, de lo cotrario marque 2\n");
    for (int i = 0; i < cantidad; i++)
    {
        do
        {
            printf("\nTarea ID[%d] , Descripcion: %s\n" , tareaPendiente[i]->TareaID , tareaPendiente[i]->Descripcion);
            scanf("%d" , &opcion);
        } while (opcion != 1 && opcion != 2);
        
        if (opcion == 1)
        {
            printf("Opcion 1: Realizo la tarea \n");
            tareaRealizada[i] = (Tarea*)malloc(sizeof(Tarea));
            tareaRealizada[i] = tareaPendiente[i];
            tareaPendiente[i] = NULL ; 
            contadorrealizadas++; 
        }
        contadorPendientes = i ; 
    }
    printf("Tareas pendientes: [%d] \n" , contadorPendientes);
    MostrarTareas(tareaPendiente ,cantidad);
    printf("Tareas realiadas [%d]\n" , contadorrealizadas);
    MostrarTareas(tareaRealizada , cantidad);
    
}

void MostrarTareas(Tarea** tarea, int Cantidad){
    printf("Las tareas Ingresada son : \n");
    for (int i = 0; i < Cantidad; i++) {
        if (tarea != NULL)
        {
        printf("\nEl id de la tarea es : %d \n", tarea[i]->TareaID);
        printf("La descripcion de la tarea es : %s \n", tarea[i]->Descripcion);
        printf("El tiempo de la tarea es : %d\n", tarea[i]->Duracion);
        printf("\n");
        }     
    }
}
void IniciarNull(Tarea **tarea , int cantidad){
    for ( int i = 0; i < cantidad ; i++)
    {
        tarea[i]=NULL;
    }
}
void AsignarTareas(Tarea ** tarea , int Cantidad){
    
    char buff[100];
    int tiempo;
    printf("\n Asignar tareas\n");
    for (int i = 0; i < Cantidad; i++) {
        tarea[i] = (Tarea*)malloc(sizeof(Tarea));
        tarea[i]->TareaID = i+1;
        printf("Ingrese La descripcion de la tarea[%d]: \n" , tarea[i]->TareaID);
        fflush(stdin);
        gets(buff);
        tarea[i]->Descripcion = malloc(sizeof(char) * (strlen(buff) + 1));
        strcpy(tarea[i]->Descripcion, buff);
        printf("\nIngrese la duracion de la tarea\n");
        scanf("%d", &tiempo);
        tarea[i]->Duracion = tiempo;
       // MostrarTareas(tarea , Cantidad);
    }
}

int cantidad (){
    int N = 0 ; 
    printf("\nIngrese la cantidad de tareas a realizar\n");
    do{    
        scanf("%d" , &N);
    } while (N < 1);

    return N ; 
}

void MemoriaATareas(int Cantidad , Tarea** tarea){
    tarea = (Tarea**)malloc(sizeof(Tarea*) * Cantidad);
    if (tarea == NULL) {
        printf("\n No se pudo asignar memoria\n");
        exit(0);
    }

    for (int i = 0; i < Cantidad; i++) {
        tarea[i] = (Tarea*)malloc(sizeof(Tarea));
    }
}