#include<stdio.h>
#include<SDL2/SDL.h>

//Estructura ranking
typedef struct {

char APODO[50];
int turno;

}ranking;



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
void dadosia(SDL_Surface *windowSurface,int dados_jugador2[],SDL_Surface *dadosia[5],SDL_Rect locdadoia,SDL_Window *ventana);
void apostaria(SDL_Surface *windowSurface,int cantidad_apostada, int num_dado_apostado, SDL_Rect locapuestaia,SDL_Rect loctextoapuestaia, SDL_Window *ventana);
int histodados(SDL_Surface *windowSurface,int cantidad_apostada,int num_dado_apostado,SDL_Rect lochistodado,SDL_Window *ventana);
int histodadosia(SDL_Surface *windowSurface,int cantidad_apostada,int num_dado_apostado,SDL_Rect lochistodadoia,SDL_Window *ventana);


