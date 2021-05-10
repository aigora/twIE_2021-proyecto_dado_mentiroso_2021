
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "libfuncion-JUEGO.h"
#define U 0.036 //Umbral


int main()
{
    char opcion,volver[7];
    printf("\n********************|| BIENVENIDO AL JUEGO DEL DADO MENTIROSO ||********************\n");
    do
    {
        printf("\n\n  A continuacion se mostraran multiples opciones.\n  Elija la opcion que desee pulsando dicha tecla y posteriormente 'enter':\n");
        printf("\n");
        printf("\tA --> Explicacion del juego DADO MENTIROSO.\n\n\tB --> Jugar contra otro jugador.\n\n\tC --> Jugar contra una IA.\n\n\tD --> Salir del menu.\n\n\n\n");
        scanf(" %c",&opcion);
        printf("\n\n");

    switch (opcion)
    {

       case 'A':
       case 'a':
           printf("\nEl juego del dado mentiroso es un juego de apuestas donde cada jugador tiene 5 dados y un cubilete.\n\
Al comenzar, todos los jugadores agitan los dados dentro del cubilete y lo posan sobre la mesa boca abajo\n\
para no revelar tus dados a los demas jugadores. Un jugador puede mirar sus dados, pero no los de los demas.\n\
El juego consiste en apostar una cantidad de dados especifica de un numero, es decir, si es un juego de dos personas,\n\
tu puedes decir que hay cuatro dados con el numero tres entre los diez dados totales.\n\
El juego es en si un bucle de apuestas cada vez mas grandes hasta llegar a un suceso muy improbable.\n\
Cuando un jugador considere que la apuesta realizada por el jugador anterior es falsa,\n\
este podra llamarle mentiroso y se tendran que revelar los dados de todos los jugadores.\n\
Si el acusador tuvo razon, gana la partida, pero si se da el caso de que el acusador no tuvo razon al llamarle mentiroso\
(porque si hay de verdad dicha cantidad de dados) el acusador pierde.\n\
\nY eso es todo, mucha suerte!!\n");//Se han añadido mediante un printf simple, posteriormente se añadiran como fichero.
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

