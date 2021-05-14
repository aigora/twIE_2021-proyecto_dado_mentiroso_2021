#include "3.0- libreria de  funciones.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define U 0.036 //Umbral

int randomizer() //Con esto consigo los dados de una manera aleatoria
{
    //numero aleatorio entre 1 y 6
    return rand() % 6 + 1;
}

//Función para imprimir el vector.
void imprime(int v[], int n)
{
  int i;
  for(i = 0; i < n; i++)
    printf("%d\t",v[i]);
}

//Función para identificar.
int identificador(int conta[], int n, int num_apostado)
{
    int c;
    switch(num_apostado)
    {
    case 1:
        c = conta[0];
        break;
    case 2:
        c = conta[1];
        break;
    case 3:
        c = conta[2];
        break;
    case 4:
        c = conta[3];
        break;
    case 5:
        c = conta[4];
        break;
    case 6:
        c = conta[5];
        break;
    }
    return c;
}

//Función para calcular la probabiliad binomial que será utilizada por la IA.
float Prop_binomial(float Exito, float Fracaso, int k, int n)
{
    return pow(Exito, k) * pow(Fracaso, n - k) * numComb(n, k);
}

//Función para realizar la combinatoria.
int numComb(int n, int k)
{
    return fact(n)/(fact(n - k) * fact(k));
}

//Función para realizar los factoriales.
int fact(int x)
{
  int res;
  if (x > 1)
    res = x * fact(x - 1);
  else
    res = 1;
  return res;
}

