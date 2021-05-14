#include <stdio.h>
#include <SDL2/SDL.h>
#include "libreria de  funciones.h"

//Funci�n que carga y coloca el fondo.

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

//Funci�n que muestra los dados del jugador.

void tusdados(SDL_Surface *windowSurface, SDL_Rect locdado,int dados_jugador1[],SDL_Window *ventana)
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
        Sleep(400);
        SDL_UpdateWindowSurface(ventana);
    }

}

//Funci�n para borrar todo lo que haya sobre la mesa.

void mesa(SDL_Surface *windowSurface, SDL_Rect locmesa,SDL_Window *ventana)
{
    SDL_Surface *mesa=NULL;

    mesa = SDL_LoadBMP("MESA.bmp");
    locmesa.x = 257;
    locmesa.y = 0;
    locmesa.w = mesa->w;
    locmesa.h = mesa->h;
    SDL_BlitSurface(mesa,NULL,windowSurface,&locmesa);
    SDL_UpdateWindowSurface(ventana);
}

//Funci�n para mostrar la pregunta de la cantidad que quiere apostar.

void apostarcant(SDL_Surface *windowSurface, SDL_Rect loccant,SDL_Rect loctextocant,SDL_Window *ventana)
{
    int i;
    SDL_Surface *texto=NULL;
    SDL_Surface *cantidad[10]={NULL};

    texto = SDL_LoadBMP("TEXTOCANTIDAD.bmp");

    for(i=0;i<10;i++)
    {
        switch(i)
        {
        case 0:
            cantidad[i] = SDL_LoadBMP("NUM1.bmp");
            break;
        case 1:
            cantidad[i] = SDL_LoadBMP("NUM2.bmp");
            break;
        case 2:
            cantidad[i] = SDL_LoadBMP("NUM3.bmp");
            break;
        case 3:
            cantidad[i] = SDL_LoadBMP("NUM4.bmp");
            break;
        case 4:
            cantidad[i] = SDL_LoadBMP("NUM5.bmp");
            break;
        case 5:
            cantidad[i] = SDL_LoadBMP("NUM6.bmp");
            break;
        case 6:
            cantidad[i] = SDL_LoadBMP("NUM7.bmp");
            break;
        case 7:
            cantidad[i] = SDL_LoadBMP("NUM8.bmp");
            break;
        case 8:
            cantidad[i] = SDL_LoadBMP("NUM9.bmp");
            break;
        case 9:
            cantidad[i] = SDL_LoadBMP("NUM10.bmp");
            break;

        }
    }

    loctextocant.x = 365;
    loctextocant.y = 192;
    loctextocant.w = texto->w;
    loctextocant.h = texto->h;

    SDL_BlitSurface(texto,NULL,windowSurface,&loctextocant);

    loccant.y = 335;
    loccant.x = 310;
    for(i=0;i<10;i++)
    {
        loccant.x += 50;
        loccant.w = cantidad[i]->w;
        loccant.h = cantidad[i]->h;
        SDL_BlitSurface(cantidad[i],NULL,windowSurface,&loccant);
        Sleep(150);
        SDL_UpdateWindowSurface(ventana);
    }



}

//Funci�n para mostrar la pregunta del dado que quiere apostar.

void apostardado(SDL_Surface *windowSurface, SDL_Rect locapdado,SDL_Rect loctextodado,SDL_Window *ventana)
{

    int i;
    SDL_Surface *texto=NULL;
    SDL_Surface *dado[6]={NULL};

    texto = SDL_LoadBMP("TEXTOAPOSTAR.bmp");

    for(i=0;i<10;i++)
    {
        switch(i)
        {
        case 0:
            dado[i] = SDL_LoadBMP("DADO1.bmp");
            break;
        case 1:
            dado[i] = SDL_LoadBMP("DADO2.bmp");
            break;
        case 2:
            dado[i] = SDL_LoadBMP("DADO3.bmp");
            break;
        case 3:
            dado[i] = SDL_LoadBMP("DADO4.bmp");
            break;
        case 4:
            dado[i] = SDL_LoadBMP("DADO5.bmp");
            break;
        case 5:
            dado[i] = SDL_LoadBMP("DADO6.bmp");
            break;

        }
    }

    loctextodado.x = 365;
    loctextodado.y = 192;
    loctextodado.w = texto->w;
    loctextodado.h = texto->h;

    SDL_BlitSurface(texto,NULL,windowSurface,&loctextodado);

    locapdado.y = 335;
    locapdado.x = 410;
    for(i=0;i<6;i++)
    {
        locapdado.x += 50;
        locapdado.w = dado[i]->w;
        locapdado.h = dado[i]->h;
        SDL_BlitSurface(dado[i],NULL,windowSurface,&locapdado);
        Sleep(150);
        SDL_UpdateWindowSurface(ventana);
    }


}

//Funci�n que muestra los botones de mentiroso y apostar.

void aposmenti(SDL_Surface *windowSurface, SDL_Rect locapostar, SDL_Rect locmentiroso, SDL_Window *ventana)
{

    SDL_Surface *texto1=NULL;
    SDL_Surface *texto2=NULL;

    texto1 = SDL_LoadBMP("APOSTAR.bmp");
    texto2 = SDL_LoadBMP("MENTIROSO.bmp");

    locapostar.x = 400;
    locapostar.y = 130;
    locapostar.w = texto1->w;
    locapostar.h = texto2->h;

    locmentiroso.x = 400;
    locmentiroso.y = 440;
    locmentiroso.w = texto1->w;
    locmentiroso.h = texto2->h;

    SDL_BlitSurface(texto1,NULL,windowSurface,&locapostar);
    SDL_BlitSurface(texto2,NULL,windowSurface,&locmentiroso);


    SDL_UpdateWindowSurface(ventana);
}


