#include <stdio.h>
#include <SDL2/SDL.h>
#include "2.0- libreria de  funciones.h"

//Función que carga y coloca el fondo.

void crearfondo(SDL_Surface *fondo,SDL_Surface *windowSurface)
{

    fondo = SDL_LoadBMP("IMG/fondo.bmp");//Carga la imagen en el puntero



    if(fondo==NULL)
    {
        printf("ERROR AL CARGAR EL FONDO DEL JUEGO: %s\n", SDL_GetError());
        exit(1);
    }

     SDL_BlitSurface(fondo,NULL,windowSurface,NULL);//Carga la imagen

     SDL_FreeSurface(fondo);
     fondo = NULL;

}

//Función que muestra los dados del jugador.

void tusdados(SDL_Surface *windowSurface, SDL_Rect locdado,int dados_jugador1[],SDL_Window *ventana,SDL_Surface *Dado[5])
{
    int i;

    for(i=0;i<5;i++)
    {
        if(dados_jugador1[i]==1)
            Dado[i]=SDL_LoadBMP("IMG/DADO1.bmp");
        if(dados_jugador1[i]==2)
            Dado[i]=SDL_LoadBMP("IMG/DADO2.bmp");
        if(dados_jugador1[i]==3)
            Dado[i]=SDL_LoadBMP("IMG/DADO3.bmp");
        if(dados_jugador1[i]==4)
            Dado[i]=SDL_LoadBMP("IMG/DADO4.bmp");
        if(dados_jugador1[i]==5)
            Dado[i]=SDL_LoadBMP("IMG/DADO5.bmp");
        if(dados_jugador1[i]==6)
            Dado[i]=SDL_LoadBMP("IMG/DADO6.bmp");
    }

    for(i=0;i<5;i++)
    {
        locdado.x += 50; //Posición x de los dados
        locdado.w = Dado[i]->w; //Definimos el ancho y alto de la imagen
        locdado.h = Dado[i]->h;
        SDL_BlitSurface(Dado[i],NULL,windowSurface,&locdado); //Cargamos las imagenes
        SDL_Delay(200); //Hacemos esperar 0.2 segundos a SDL para despues ejecutar la siguiente funcion
        SDL_UpdateWindowSurface(ventana);//Actualiza la pantalla colocando la imagen cargada
    }

    for(i=0;i<5;i++)
    {
        SDL_FreeSurface(Dado[i]);
        Dado[i] = NULL;
    }

}

//Función para borrar todo lo que haya sobre la mesa.

void mesa(SDL_Surface *windowSurface, SDL_Rect locmesa,SDL_Window *ventana)
{
    SDL_Surface *mesa=NULL;

    mesa = SDL_LoadBMP("IMG/MESA.bmp");
    locmesa.x = 257;
    locmesa.y = 0;
    locmesa.w = mesa->w;
    locmesa.h = mesa->h;
    SDL_BlitSurface(mesa,NULL,windowSurface,&locmesa);
    SDL_UpdateWindowSurface(ventana);

    SDL_FreeSurface(mesa);
    mesa = NULL;
}

//Función para mostrar la pregunta de la cantidad que quiere apostar.

void apostarcant(SDL_Surface *windowSurface, SDL_Rect loccant,SDL_Rect loctextocant,SDL_Window *ventana)
{
    int i;
    SDL_Surface *texto=NULL;
    SDL_Surface *cantidad[10]={NULL};

    texto = SDL_LoadBMP("IMG/TEXTOCANTIDAD.bmp");

    for(i=0;i<10;i++)
    {
        switch(i)
        {
        case 0:
            cantidad[i] = SDL_LoadBMP("IMG/NUM1.bmp");
            break;
        case 1:
            cantidad[i] = SDL_LoadBMP("IMG/NUM2.bmp");
            break;
        case 2:
            cantidad[i] = SDL_LoadBMP("IMG/NUM3.bmp");
            break;
        case 3:
            cantidad[i] = SDL_LoadBMP("IMG/NUM4.bmp");
            break;
        case 4:
            cantidad[i] = SDL_LoadBMP("IMG/NUM5.bmp");
            break;
        case 5:
            cantidad[i] = SDL_LoadBMP("IMG/NUM6.bmp");
            break;
        case 6:
            cantidad[i] = SDL_LoadBMP("IMG/NUM7.bmp");
            break;
        case 7:
            cantidad[i] = SDL_LoadBMP("IMG/NUM8.bmp");
            break;
        case 8:
            cantidad[i] = SDL_LoadBMP("IMG/NUM9.bmp");
            break;
        case 9:
            cantidad[i] = SDL_LoadBMP("IMG/NUM10.bmp");
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

    SDL_FreeSurface(texto);

    texto = NULL;

    for(i=0;i<10;i++)
    {
        SDL_FreeSurface(cantidad[i]);
        cantidad[i]=NULL;
    }


}

//Función para mostrar la pregunta del dado que quiere apostar.

void apostardado(SDL_Surface *windowSurface, SDL_Rect locapdado,SDL_Rect loctextodado,SDL_Window *ventana)
{

    int i;
    SDL_Surface *texto=NULL;
    SDL_Surface *dado[6]={NULL};

    texto = SDL_LoadBMP("IMG/TEXTOAPOSTAR.bmp");

    for(i=0;i<10;i++)
    {
        switch(i)
        {
        case 0:
            dado[i] = SDL_LoadBMP("IMG/DADO1.bmp");
            break;
        case 1:
            dado[i] = SDL_LoadBMP("IMG/DADO2.bmp");
            break;
        case 2:
            dado[i] = SDL_LoadBMP("IMG/DADO3.bmp");
            break;
        case 3:
            dado[i] = SDL_LoadBMP("IMG/DADO4.bmp");
            break;
        case 4:
            dado[i] = SDL_LoadBMP("IMG/DADO5.bmp");
            break;
        case 5:
            dado[i] = SDL_LoadBMP("IMG/DADO6.bmp");
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

    SDL_FreeSurface(texto);
    texto = NULL;


    for(i=0;i<5;i++)
    {
        SDL_FreeSurface(dado[i]);
        dado[i] = NULL;
    }


}

//Función que muestra los botones de mentiroso y apostar.

void aposmenti(SDL_Surface *windowSurface, SDL_Rect locapostar, SDL_Rect locmentiroso, SDL_Window *ventana)
{

    SDL_Surface *texto1=NULL;
    SDL_Surface *texto2=NULL;

    texto1 = SDL_LoadBMP("IMG/APOSTAR.bmp");
    texto2 = SDL_LoadBMP("IMG/MENTIROSO.bmp");

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

    SDL_FreeSurface(texto1);
    texto1=NULL;
    SDL_FreeSurface(texto2);
    texto2=NULL;
}

//Dos funciones que muestran el fondo de victoria o derrota tras termianar el juego.
//Estas funciones están acompañadas de un botón de salida para el jugador.

void victoria(SDL_Surface *fondo, SDL_Surface *windowSurface,SDL_Window *ventana)
{
    SDL_Surface *salir;
    SDL_Rect locsalir;

    fondo = SDL_LoadBMP("IMG/VICTORIA.bmp");
    salir = SDL_LoadBMP("IMG/SALIR.bmp");

    locsalir.x = 958;
    locsalir.y = 560;
    locsalir.w = salir->w;
    locsalir.h = salir->h;

    SDL_BlitSurface(fondo,NULL,windowSurface,NULL);
    SDL_UpdateWindowSurface(ventana);
    SDL_BlitSurface(salir,NULL,windowSurface,&locsalir);
    SDL_UpdateWindowSurface(ventana);

    SDL_FreeSurface(salir);
    salir = NULL;


}


void derrota(SDL_Surface *fondo, SDL_Surface *windowSurface,SDL_Window *ventana)
{
    SDL_Surface *salir;
    SDL_Rect locsalir;

    fondo = SDL_LoadBMP("IMG/DERROTA.bmp");
    salir = SDL_LoadBMP("IMG/SALIR.bmp");

    locsalir.x = 958;
    locsalir.y = 560;
    locsalir.w = salir->w;
    locsalir.h = salir->h;

    SDL_BlitSurface(fondo,NULL,windowSurface,NULL);
    SDL_UpdateWindowSurface(ventana);
    SDL_BlitSurface(salir,NULL,windowSurface,&locsalir);
    SDL_UpdateWindowSurface(ventana);

    SDL_FreeSurface(salir);
    salir = NULL;

}


//Muestra el mensaje cuando la IA te llame mentiroso.

void mentiroso(SDL_Surface *fondo, SDL_Surface *windowSurface,SDL_Window *ventana, int h)
{
    if(h==0)
        fondo = SDL_LoadBMP("IMG/MENTIROSOIA.bmp");
    if(h==1)
        fondo = SDL_LoadBMP("IMG/MENTIROSOTU.bmp");

    if(fondo==NULL)
    {
        printf("ERROR AL CARGAR EL FONDO DEL JUEGO: %s\n", SDL_GetError());
        exit(1);
    }

     SDL_BlitSurface(fondo,NULL,windowSurface,NULL);
     SDL_UpdateWindowSurface(ventana);
     Sleep(3000);

}

//Carga las imágenes de los dados de la ia y los muestra en pantalla

void dadosia(SDL_Surface *windowSurface,int dados_jugador2[], SDL_Surface *Dadoia[5],SDL_Rect locdadoia, SDL_Window *ventana)
{

    int i;

    locdadoia.y = 500;
    locdadoia.x = 435;

    for(i=0;i<5;i++)
    {
        if(dados_jugador2[i]==1)
            Dadoia[i]=SDL_LoadBMP("IMG/DADO1+.bmp");
        if(dados_jugador2[i]==2)
            Dadoia[i]=SDL_LoadBMP("IMG/DADO2+.bmp");
        if(dados_jugador2[i]==3)
            Dadoia[i]=SDL_LoadBMP("IMG/DADO3+.bmp");
        if(dados_jugador2[i]==4)
            Dadoia[i]=SDL_LoadBMP("IMG/DADO4+.bmp");
        if(dados_jugador2[i]==5)
            Dadoia[i]=SDL_LoadBMP("IMG/DADO5+.bmp");
        if(dados_jugador2[i]==6)
            Dadoia[i]=SDL_LoadBMP("IMG/DADO6+.bmp");
    }

    for(i=0;i<5;i++)
    {
        locdadoia.x += 50;
        locdadoia.w = Dadoia[i]->w;
        locdadoia.h = Dadoia[i]->h;
        SDL_BlitSurface(Dadoia[i],NULL,windowSurface,&locdadoia);
        SDL_UpdateWindowSurface(ventana);
    }

    for(i=0;i<5;i++)
    {
        SDL_FreeSurface(Dadoia[i]);
        Dadoia[i] = NULL;
    }


}

//Muestra los dados que ha apostado la ia en pantalla

void apostaria(SDL_Surface *windowSurface,int cantidad_apostada, int num_dado_apostado, SDL_Rect locapuestaia,SDL_Rect loctextoapuestaia, SDL_Window *ventana)
{
    SDL_Surface *dadoapuesta;
    SDL_Surface *texto;
    int i;

    if(num_dado_apostado==1)
        dadoapuesta = SDL_LoadBMP("IMG/DADO1+.bmp");
    if(num_dado_apostado==2)
        dadoapuesta = SDL_LoadBMP("IMG/DADO2+.bmp");
    if(num_dado_apostado==3)
        dadoapuesta = SDL_LoadBMP("IMG/DADO3+.bmp");
    if(num_dado_apostado==4)
        dadoapuesta = SDL_LoadBMP("IMG/DADO4+.bmp");
    if(num_dado_apostado==5)
        dadoapuesta = SDL_LoadBMP("IMG/DADO5+.bmp");
    if(num_dado_apostado==6)
        dadoapuesta = SDL_LoadBMP("IMG/DADO6+.bmp");


    texto = SDL_LoadBMP("IMG/APUESTAIA.bmp");

    loctextoapuestaia.x = 370;
    loctextoapuestaia.y = 280;
    loctextoapuestaia.w = texto->w;
    loctextoapuestaia.h = texto->h;

    SDL_BlitSurface(texto,NULL,windowSurface,&loctextoapuestaia);
    SDL_UpdateWindowSurface(ventana);

    locapuestaia.x = 425;
    locapuestaia.y = 360;
    locapuestaia.w = dadoapuesta->w;
    locapuestaia.h = dadoapuesta->h;

    for(i=0;i<cantidad_apostada;i++)
    {
        locapuestaia.x += 50;
        SDL_BlitSurface(dadoapuesta,NULL,windowSurface,&locapuestaia);
        SDL_UpdateWindowSurface(ventana);
        SDL_Delay(400);

    }

    SDL_FreeSurface(dadoapuesta);
    dadoapuesta = NULL;

    SDL_FreeSurface(texto);
    texto = NULL;

}

//Muestra los dados del jugador en el apartado del historial

int histodados(SDL_Surface *windowSurface,int cantidad_apostada,int num_dado_apostado,SDL_Rect lochistodado,SDL_Window *ventana)
{
    SDL_Surface *dadoapuesta;

    int i;

    if(num_dado_apostado==1)
        dadoapuesta = SDL_LoadBMP("IMG/DADO1.bmp");
    if(num_dado_apostado==2)
        dadoapuesta = SDL_LoadBMP("IMG/DADO2.bmp");
    if(num_dado_apostado==3)
        dadoapuesta = SDL_LoadBMP("IMG/DADO3.bmp");
    if(num_dado_apostado==4)
        dadoapuesta = SDL_LoadBMP("IMG/DADO4.bmp");
    if(num_dado_apostado==5)
        dadoapuesta = SDL_LoadBMP("IMG/DADO5.bmp");
    if(num_dado_apostado==6)
        dadoapuesta = SDL_LoadBMP("IMG/DADO6.bmp");

    lochistodado.x = -30;
    lochistodado.y += 50;
    lochistodado.w = dadoapuesta->w;
    lochistodado.h = dadoapuesta->h;

    for(i=0;i<cantidad_apostada;i++)
    {

        lochistodado.x += 40;
        if((lochistodado.x+37)>=250)//Si los dados se colocan fuera de los margenes del recuadro
                                    //los que se encuentren fuera se colocaran debajo de los primeros colocados
        {
            lochistodado.x = 20;
            lochistodado.y += 50;
        }



        SDL_BlitSurface(dadoapuesta,NULL,windowSurface,&lochistodado);
        SDL_UpdateWindowSurface(ventana);
        SDL_Delay(400);

    }

    SDL_FreeSurface(dadoapuesta);
    dadoapuesta = NULL;

 return lochistodado.y;
}

//Muestra los dados de la ia en el apartado del historial

int histodadosia(SDL_Surface *windowSurface,int cantidad_apostada,int num_dado_apostado,SDL_Rect lochistodadoia,SDL_Window *ventana)
{
    SDL_Surface *dadoapuesta;

    int i;

    if(num_dado_apostado==1)
        dadoapuesta = SDL_LoadBMP("IMG/DADO1+.bmp");
    if(num_dado_apostado==2)
        dadoapuesta = SDL_LoadBMP("IMG/DADO2+.bmp");
    if(num_dado_apostado==3)
        dadoapuesta = SDL_LoadBMP("IMG/DADO3+.bmp");
    if(num_dado_apostado==4)
        dadoapuesta = SDL_LoadBMP("IMG/DADO4+.bmp");
    if(num_dado_apostado==5)
        dadoapuesta = SDL_LoadBMP("IMG/DADO5+.bmp");
    if(num_dado_apostado==6)
        dadoapuesta = SDL_LoadBMP("IMG/DADO6+.bmp");

    lochistodadoia.x = 925;
    lochistodadoia.y += 50;
    lochistodadoia.w = dadoapuesta->w;
    lochistodadoia.h = dadoapuesta->h;

    for(i=0;i<cantidad_apostada;i++)
    {

        lochistodadoia.x += 40;
        if((lochistodadoia.x+37)>=1200)
        {
            lochistodadoia.x = 965;
            lochistodadoia.y += 50;
        }



        SDL_BlitSurface(dadoapuesta,NULL,windowSurface,&lochistodadoia);
        SDL_UpdateWindowSurface(ventana);
        SDL_Delay(400);

    }

    SDL_FreeSurface(dadoapuesta);
    dadoapuesta = NULL;

    return lochistodadoia.y;
}
