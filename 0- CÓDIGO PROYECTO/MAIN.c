
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "libfuncion-1.h"
#define U 0.036 //Umbral


int main(int argc, char *argv[])
{
    char opcion,caracter[100],volver[7];
    printf("\n********************|| BIENVENIDO AL JUEGO DEL DADO MENTIROSO ||********************\n");
    do
    {
        printf("\n\n  A continuacion se mostraran multiples opciones.\n  Elija la opcion que desee pulsando dicha tecla y posteriormente 'enter':\n");
        printf("\n");
        printf("\tA --> Explicacion del juego DADO MENTIROSO.\n\n\tB --> Jugar contra otro jugador.\n\n\tC --> Jugar contra una IA.\n\n\tD --> Salir del menu.\n\n\n\n");
        scanf(" %c",&opcion);
        printf("\n\n");
        FILE *archivo;
    switch (opcion)
    {

       case 'A':
       case 'a':
           archivo = fopen("reglas_dado_mentiroso.txt","r");

 	    while (feof(archivo) == 0)
 	    {
 		fgets(caracter,100,archivo);
 		printf("%s",caracter);
 	    }
        fclose(archivo);

           printf("\n\n-----| Escriba 'volver' y posteriormente pulse 'enter' para volver al menu anterior |-----\n\n");
           scanf(" %6s", volver);//Una forma un poco "casera" de hacer esperar al programa hasta que la persona pulse "una tecla" (en este caso mediante una palabra).
           break;

       case 'B':
       case 'b':
           printf("Jugador contra jugador\n");
           printf("\n-----| Escriba 'volver' y posteriormente pulse 'enter' para volver al menu anterior |-----\n\n");
           scanf(" %6s", volver);
           break;

       case 'C':
       case 'c':
           printf("Jugar contra una IA\n\n");

           JUGADORIA();

           printf("\n\n-----| Escriba 'volver' y posteriormente pulse 'enter' para volver al menu anterior |-----\n\n");
           scanf(" %6s", volver);
           break;

       case 'D':
       case 'd':
        printf("*************************************| Hasta luego!! |*************************************\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~| Esperemos verle pronto por aqui |~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        break;

       default://Por si la persona se equivoca de tecla para que el menu siga abierto.
        printf("\n--------------------------|  Esta opcion no esta contemplada  |---------------------------\n");
        printf("-----| Escriba 'volver' y posteriormente pulse 'enter' para volver al menu anterior |-----\n\n");
        scanf(" %6s", volver);
        break;


    }
    }
    while((opcion!='d')&&(opcion!='D'));

    return 0;
}


