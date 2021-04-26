#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include "libfuncion-1.h"
#define U 0.036 //Umbral

int main()
{
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
        printf("Escribe la cantidad que apuestas\n");
        printf("(Debe estar comprendido entre 1 y 10).\n");
        scanf(" %i", &cantidad_apostada);
    }while ((cantidad_apostada < 1) || (cantidad_apostada > 10));

    do
    {
        printf("Escribe el numero de dado que apuestas\n");
        printf("(Debe estar comprendido entre 1 y 6).\n");
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

    return 0;
}

