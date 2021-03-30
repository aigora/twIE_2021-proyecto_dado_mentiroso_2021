#include<stdio.h>

int main()
{
    char opcion;
    printf("\n****************BIENVENIDO AL JUEGO DEL DADO MENTIROSO****************\n");
    do
    {
        printf("\n  A continuacion se mostraran multiples opciones, elija la opcion que desee pulsando dicha tecla:\n");
        printf("\tA-->Si desea conocer las reglas del juego\n\tB-->Si desea jugar contra otro jugador\n\tC-->Si desea jugar contra una IA\n\tD-->Si desea salir del menu\n");
        scanf(" %c",&opcion);
    switch (opcion)
    {

       case 'A':
       case 'a':
           printf("Reglas \n");
           break;

       case 'B':
       case 'b':
           printf("opcion B \n");
           break;

       case 'C':
       case 'c':
           printf("opcion C\n");
           break;

    }
    }
    while((opcion=='A')||(opcion=='B')||(opcion=='a')||(opcion=='b')||(opcion=='C')||(opcion=='c'));

    return 0;
}
