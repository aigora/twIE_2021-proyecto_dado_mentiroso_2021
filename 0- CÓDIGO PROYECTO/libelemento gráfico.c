#include <stdio.h>
#include <SDL2/SDL.h>
#include "libfuncion-1.h"

void crearfondo(SDL_Surface *fondo,SDL_Surface *windowSurface)
{

    fondo = SDL_LoadBMP("fondo.bmp");//Carga la imagen del tablero



    if(fondo==NULL)
    {
        printf("ERROR AL CARGAR EL FONDO DEL JUEGO: %s\n", SDL_GetError());
        exit(1);
    }

     SDL_BlitSurface(fondo,NULL,windowSurface,NULL);

}

void tusdados(SDL_Surface *windowSurface, SDL_Rect locdado,int dados_jugador1[])
{
    int i;
    SDL_Surface *Dado[5]={NULL};

    for(i=0;i<5;i++)
    {
        if(dados_jugador1[i]==1)
            Dado[i]=SDL_LoadBMP("DADO1.bmp");
        if(dados_jugador1[i]==2)
            Dado[i]=SDL_LoadBMP("DADO2.bmp");
        if(dados_jugador1[i]==3)
            Dado[i]=SDL_LoadBMP("DADO3.bmp");
        if(dados_jugador1[i]==4)
            Dado[i]=SDL_LoadBMP("DADO4.bmp");
        if(dados_jugador1[i]==5)
            Dado[i]=SDL_LoadBMP("DADO5.bmp");
        if(dados_jugador1[i]==6)
            Dado[i]=SDL_LoadBMP("DADO6.bmp");
    }
    locdado.y = 640;
    locdado.x = 0;
    for(i=0;i<5;i++)
    {
        locdado.x += 50;
        locdado.w = Dado[i]->w;
        locdado.h = Dado[i]->h;
        SDL_BlitSurface(Dado[i],NULL,windowSurface,&locdado);
    }

}

void mesa(SDL_Surface *windowSurface, SDL_Rect locmesa)
{
    SDL_Surface *mesa;

    mesa = SDL_LoadBMP("MESA.bmp");
    locmesa.x = 256;
    locmesa.y = 0;
    locmesa.w = mesa->w;
    locmesa.h = mesa->h;
    SDL_BlitSurface(mesa,NULL,windowSurface,&locmesa);
}
