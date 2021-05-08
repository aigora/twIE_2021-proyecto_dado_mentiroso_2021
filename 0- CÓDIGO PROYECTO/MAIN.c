
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "libfuncion-1.h"
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



            int i;
            int dados_jugador1[5];
            int dados_jugador2[5];
            int contador_dados_IA[6] = {0};
            int num_dado_apostado;
            int cantidad_apostada;
            int cantidad_de_la_IA_del_dadoapostado; //si yo, usuario, he apostado un 5, la maquina utiliza esta variable para saber cuantos 5 tiene
            float Prop_exito = 1.0/6.0;
            float Prop_fracaso = 5.0/6.0;
            float Binomial;
            int c;
            int n = 5;

            //Genera semilla aleatoria
            srand(time(NULL));

            for(i = 0; i < 5; i++)
                dados_jugador1[i] = randomizer();

            for(i = 0; i < 5; i++)
                dados_jugador2[i] = randomizer();

            printf("Los dados con los qque usted jugara seran:\n");
            printf("\n");

            imprime(dados_jugador1, 5);
            printf("\n\n");


            //Este bucle contabiliza en un nuevo vector(contador_dados_IA) la cantidad de cada numero de dados que le ha tocado a la IA
            for(i = 0; i < 5; i++)
            {
            switch(dados_jugador2[i])
                {
                case 1:
                    contador_dados_IA[0] += 1;
                    break;
                case 2:
                    contador_dados_IA[1] += 1;
                    break;
                case 3:
                    contador_dados_IA[2] += 1;
                    break;
                case 4:
                    contador_dados_IA[3] += 1;
                    break;
                case 5:
                    contador_dados_IA[4] += 1;
                    break;
                case 6:
                    contador_dados_IA[5] += 1;
                    break;
                }
            }
            //imprime(contador_dados_IA, 6);
            printf("\n\n");

            do
            {
                printf("\nEscribe la cantidad que apuestas\n");
                printf("(Debe estar comprendido entre 1 y 10).\n");
                printf("\n");
                scanf(" %i", &cantidad_apostada);
            }while ((cantidad_apostada < 1) || (cantidad_apostada > 10));

            do
            {
                printf("\nEscribe el numero de dado que apuestas\n");
                printf("(Debe estar comprendido entre 1 y 6).\n");
                printf("\n");
                scanf(" %i", &num_dado_apostado);
            }while ((num_dado_apostado < 1) || (num_dado_apostado > 6));

            cantidad_de_la_IA_del_dadoapostado = identificador(contador_dados_IA, 6, num_dado_apostado);
            printf("\n\n");
            //printf("%i", cantidad_de_la_IA_del_dadoapostado);
            printf("\n\n");


            c = cantidad_apostada - cantidad_de_la_IA_del_dadoapostado;
            //Si se da el caso de que c sigue siendo mayor que 5, se usa esto para volver a una binomial entre 10 dados
            if(c >= 5)
            {
                c = cantidad_apostada;
                n = 10;
            }

            for (i = c; i < n; i++)
            {
                Binomial += Prop_binomial(Prop_exito, Prop_fracaso, i, n);
            }
            printf("La probabilidad de que la apuesta realizada exista es de:\n");
            printf("%f\n", Binomial);

            if(Binomial < U)
            {
                printf("Mentiroso!!\n");
            }
            imprime(dados_jugador2, 5);


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
