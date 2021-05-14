#include<stdio.h>
#include<SDL2/SDL.h>

//FUNCIONES MENU

int JUGADORIA(); //Llama al código del juego

//FUNCIONES JUEGO

int randomizer();
void imprime(int v[], int n);
int identificador(int conta[], int n, int num_apostado);
int fact(int x);
int numComb(int n, int k);
float Prop_binomial(float Exito, float Fracaso, int k, int n);

//FUNCIONES ELEMENTO GRAFICO

void crearfondo(SDL_Surface *fondo,SDL_Surface *windowSurface);
void tusdados(SDL_Surface *windowSurface, SDL_Rect locdado,int dados_jugador1[],SDL_Window *ventana,SDL_Surface *Dado[5]);
void mesa(SDL_Surface *windowSurface, SDL_Rect locmesa,SDL_Window *ventana);
void apostarcant(SDL_Surface *windowSurface, SDL_Rect loccant,SDL_Rect loctextocant,SDL_Window *ventana);
void apostardado(SDL_Surface *windowSurface, SDL_Rect locapdado,SDL_Rect loctextodado,SDL_Window *ventana);
void aposmenti(SDL_Surface *windowSurface, SDL_Rect locapostar, SDL_Rect locmentiroso,SDL_Window *ventana);
void victoria(SDL_Surface *fondo, SDL_Surface *windowSurface,SDL_Window *ventana);
void derrota(SDL_Surface *fondo, SDL_Surface *windowSurface,SDL_Window *ventana);
void mentiroso(SDL_Surface *fondo, SDL_Surface *windowSurface,SDL_Window *ventana, int h);
void todosdados(SDL_Surface *windowSurface,int dados_jugador1[],int dados_jugador2[], SDL_Surface *Dado[5], SDL_Surface *dadosia[5],SDL_Rect locdado,SDL_Rect locdadoia,SDL_Window *ventana);
