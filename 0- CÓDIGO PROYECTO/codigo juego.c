#include "libreria de  funciones.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#define U 0.036 //Umbral
#define altu 700 //Altura de la ventana
#define anchu 1200 //Anchura de la ventana


int JUGADORIA()
{
    //Variables del funcionamiento del juego
    int i,j;
    int dados_jugador1[5];
    int dados_jugador2[5];
    int contador_dados_IA[6] = {0};
    int num_dado_apostado = 0;
    int cantidad_apostada = 0;
    int cantidad_de_la_IA_del_dadoapostado; //si yo, usuario, he apostado un 5, la maquina utiliza esta variable para saber cuantos 5 tiene
    float Prop_exito = 1.0/6.0;
    float Prop_fracaso = 5.0/6.0;
    float Binomial = 0;
    int c, k;
    int n = 5;
    int x = 1;
    float vector[12];
    int h=3;
    char letra = 'c';
    int t = 0, aux = 0;
    int comprobador = 0;

    //Variables relacionadas con el ratón/cursor
        bool on = 1;
        int rx,ry;
        Uint32 inicio;




    //Variables parte gráfica
    SDL_Window *ventana=NULL;
    SDL_Surface *Dado[5]={NULL};
    SDL_Surface *Dadoia[5]={NULL};
    SDL_Surface *fondo=NULL;
    SDL_Surface *histodadosjug[10]={NULL};
    SDL_Surface *histodadosia[10]={NULL};
    SDL_Surface *windowSurface=NULL;

    //Los SDL_Rect son un tipo de estructura de SDL la cual define la posición (x,y) además de definir el ancho (w) y altura (h) de la imagen.
    SDL_Rect locdado;
    SDL_Rect locdadoia;
    SDL_Rect locmesa;
    SDL_Rect loccant;
    SDL_Rect locapdado;
    SDL_Rect loctextocant;
    SDL_Rect loctextodado;
    SDL_Rect locapostar;
    SDL_Rect locmentiroso;




    if(SDL_Init(SDL_INIT_EVERYTHING)<0)//Comprobamos que SDL se inicia correctamente
    {
        printf("ERROR AL INICIAR LA LIBERIA DE SDL2\n");
        exit(-1);
    }

    //Abrimos la ventana que vamos a usar
    ventana = SDL_CreateWindow("DADO MENTIROSO",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               anchu, altu,
                               SDL_WINDOW_ALLOW_HIGHDPI);

    windowSurface = SDL_GetWindowSurface(ventana);
    if(ventana==NULL)//Comprobamos que se abre correctamente la ventana
    {
        printf("ERROR AL ABRIR LA VENTANA EMERGENTE\n");
        exit(-1);
    }

    SDL_Event windowEvent;



    //Genera semilla aleatoria
    srand(time(NULL));

    for(i = 0; i < 5; i++)
        dados_jugador1[i] = randomizer();

    for(i = 0; i < 5; i++)
        dados_jugador2[i] = randomizer();

     crearfondo(fondo,windowSurface);//Carga el fondo de la ventana
     SDL_UpdateWindowSurface(ventana);//Actualiza ventana con el fondo

     tusdados(windowSurface, locdado, dados_jugador1,ventana,Dado);//Carga los dados del jugador
     SDL_UpdateWindowSurface(ventana);//Actualiza ventana con los dados del jugador (Por si acaso no se actualizó antes)



    //imprime(dados_jugador1, 5);
    //printf("\n\n");

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
    //printf("\n\n");

    do
    {
        imprime(dados_jugador1, 5);
        printf("\n");
        Binomial = 0;
        if(t != 0){
        printf("Escribe una M para llamar mentiroso o C para seguir apostando.\n");
        aposmenti(windowSurface,locapostar,locmentiroso,ventana);

        while(on)
        {
            SDL_UpdateWindowSurface(ventana);
            inicio = SDL_GetTicks();
            while(SDL_PollEvent(&windowEvent))
            {
                switch(windowEvent.type)
                {
                case SDL_QUIT:
                    on = 0;
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    rx = windowEvent.button.x;
                    ry = windowEvent.button.y;
                    if(((rx>=400)&&(rx<=800))&&((ry>=130)&&(ry<=255)))
                        letra = 'C';
                    if(((rx>=400)&&(rx<=800))&&((ry>=440)&&(ry<=565)))
                        letra = 'M';
                    on = 0;
                    break;
                }
            }
        }
        on = 1;

        //scanf(" %c", &letra);
        mesa(windowSurface,locmesa,ventana);

        }


        switch(letra)
        {
        case 'C':
        case 'c':
            t += 1;
            do
            {
                printf("Escribe la cantidad que apuestas\n");
                printf("(Debe estar comprendido entre %i y 10).\n", x);
                apostarcant(windowSurface,loccant,loctextocant,ventana);
        while(on)
            {
                SDL_UpdateWindowSurface(ventana);
                inicio = SDL_GetTicks();
                while(SDL_PollEvent(&windowEvent))
                {
                    switch(windowEvent.type)
                    {
                    case SDL_QUIT:
                        on = 0;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        rx = windowEvent.button.x;
                        ry = windowEvent.button.y;
                        if(((rx>=360)&&(rx<=397))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 1;
                        if(((rx>=410)&&(rx<=447))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 2;
                        if(((rx>=460)&&(rx<=497))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 3;
                        if(((rx>=510)&&(rx<=547))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 4;
                        if(((rx>=560)&&(rx<=597))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 5;
                        if(((rx>=610)&&(rx<=647))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 6;
                        if(((rx>=660)&&(rx<=697))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 7;
                        if(((rx>=710)&&(rx<=747))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 8;
                        if(((rx>=760)&&(rx<=797))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 9;
                        if(((rx>=810)&&(rx<=847))&&((ry>=335)&&(ry<=372)))
                            cantidad_apostada = 10;
                        on = 0;
                        break;
                    }
                }
            }
            on=1;
            printf("%i\n",cantidad_apostada);


                //scanf(" %i", &cantidad_apostada);
                mesa(windowSurface,locmesa,ventana);
            }while ((cantidad_apostada < x) || (cantidad_apostada > 10));

            do
            {
                printf("Escribe el numero de dado que apuestas\n");
                printf("(Debe estar comprendido entre 1 y 6).\n");
                apostardado(windowSurface,locapdado,loctextodado,ventana);
        while(on)
            {
                SDL_UpdateWindowSurface(ventana);
                inicio = SDL_GetTicks();
                while(SDL_PollEvent(&windowEvent))
                {
                    switch(windowEvent.type)
                    {
                    case SDL_QUIT:
                        on = 0;
                        break;
                    case SDL_MOUSEBUTTONDOWN:
                        rx = windowEvent.button.x;
                        ry = windowEvent.button.y;
                        if(((rx>=460)&&(rx<=497))&&((ry>=335)&&(ry<=372)))
                        {
                            num_dado_apostado = 1;
                            on=0;
                        }
                        if(((rx>=510)&&(rx<=547))&&((ry>=335)&&(ry<=372)))
                        {
                            num_dado_apostado = 2;
                            on=0;
                        }

                        if(((rx>=560)&&(rx<=597))&&((ry>=335)&&(ry<=372)))
                        {
                            num_dado_apostado = 3;
                            on=0;
                        }

                        if(((rx>=610)&&(rx<=647))&&((ry>=335)&&(ry<=372)))
                        {
                            num_dado_apostado = 4;
                            on=0;
                        }

                        if(((rx>=660)&&(rx<=697))&&((ry>=335)&&(ry<=372)))
                        {
                            num_dado_apostado = 5;
                            on=0;
                        }

                        if(((rx>=710)&&(rx<=747))&&((ry>=335)&&(ry<=372)))
                        {
                           num_dado_apostado = 6;
                           on=0;
                        }
                        if((rx<=460)&&(rx>=497)&&(rx<=510)&&(rx>=547)&&(rx<=560)&&(rx>=597)&&(rx<=610)&&(rx>=647)&&(rx<=660)&&(rx>=697)&&(rx<=710)&&(rx>=747)&&(ry>=335)&&(ry<=372))
                        {
                            on = 1;
                        }

                        break;
                    }
                }
            }
                printf("%i\n",num_dado_apostado);

            on = 1;

                //scanf(" %i", &num_dado_apostado);
                mesa(windowSurface,locmesa,ventana);
            }while ((num_dado_apostado < 1) || (num_dado_apostado > 6));


            cantidad_de_la_IA_del_dadoapostado = identificador(contador_dados_IA, 6, num_dado_apostado);
            printf("\n\n");


            x = cantidad_apostada;
            c = cantidad_apostada - cantidad_de_la_IA_del_dadoapostado;
            //Si se da el caso de que c sigue siendo mayor que 5, se usa esto para volver la formula a una binomial de 10 dados
            if(c >= 5)
            {
                c = cantidad_apostada;
                n = 10;
            }

            for (i = c; i < n; i++)
            {
                Binomial += Prop_binomial(Prop_exito, Prop_fracaso, i, n);
            }


            if(Binomial < U)
            {
                printf("Mentiroso!!\n");
                imprime(dados_jugador1, 5);
                printf("\n");
                imprime(dados_jugador2, 5);
                printf("\n");

                h=0;

                mentiroso(fondo,windowSurface,ventana,h);

                for(i = 0; i < n; i++)
                {
                    if(num_dado_apostado == dados_jugador1[i])
                    comprobador++;
                }
                for(i = 0; i < n; i++)
                {
                    if(num_dado_apostado == dados_jugador2[i])
                    comprobador++;
                }
              //  printf("%i\n", comprobador);
                if(comprobador < cantidad_apostada)
                {
                    printf("Eres un mentiroso!\n");
                    printf("PERDISTE!\n");

                    derrota(fondo,windowSurface,ventana);
                    todosdados(windowSurface,dados_jugador1,dados_jugador2,Dado,Dadoia,locdado,locdadoia,ventana);
                }
                else
                {
                    printf("La IA es mentirosa\n");
                    printf("GANASTE!!!");

                    victoria(fondo,windowSurface,ventana);
                    todosdados(windowSurface,dados_jugador1,dados_jugador2,Dado,Dadoia,locdado,locdadoia,ventana);
                }
                aux = 1;
            }
            //imprime(dados_jugador2, 5);
            else if(Binomial > U)
            {
                n = 5;
                t += 1;
                x = cantidad_apostada;

                vector[0] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[0], n);
                vector[1] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[0] + 1, n);
                vector[2] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[1], n);
                vector[3] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[1] + 1, n);
                vector[4] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[2], n);
                vector[5] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[2] + 1, n);
                vector[6] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[3], n);
                vector[7] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[3] + 1, n);
                vector[8] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[4], n);
                vector[9] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[4] + 1, n);
                vector[10] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[5], n);
                vector[11] = Prop_binomial(Prop_exito, Prop_fracaso, cantidad_apostada - contador_dados_IA[5] + 1, n);

                // con esto hago que la probabilidad de la apuesta que el usuario a realizado previamente sea cero.
                //así restrijo al ordenador de utilizar esa apuesta
                switch(num_dado_apostado)
                {
                case 1:
                    vector[0] = 0;
                    break;
                case 2:
                    vector[2] = 0;
                    break;
                case 3:
                    vector[4] = 0;
                    break;
                case 4:
                    vector[6] = 0;
                    break;
                case 5:
                    vector[8] = 0;
                    break;
                case 6:
                    vector[10] = 0;
                    break;
                }

                //En estas siguientes lineas lo que hago es comparar los resultados que del calculo binomial
                //Lo hago asi porque yo utilizo la posicion del vector para determinar que numero y que cantidad apostara
                //el ordenador
                if (vector[0] >= vector[1] && vector[0] >= vector[2] && vector[0] >= vector[3] && vector[0] >= vector[4] && vector[0] >= vector[5] && vector[0] >= vector[6] && vector[0] >= vector[7] && vector[0] >= vector[8] && vector[0] >= vector[9] && vector[0] >= vector[10] && vector[0] >= vector[11])
                {
                    num_dado_apostado = 1;

                }
                else if (vector[1] >= vector[0] && vector[1] >= vector[2] && vector[1] >= vector[3] && vector[1] >= vector[4] && vector[1] >= vector[5] && vector[1] >= vector[6] && vector[1] >= vector[7] && vector[1] >= vector[8] && vector[1] >= vector[9] && vector[1] >= vector[10] && vector[1] >= vector[11])
                {
                    num_dado_apostado = 1;
                    cantidad_apostada += 1;
                }
                else if (vector[2] >= vector[0] && vector[2] >= vector[1] && vector[2] >= vector[3] && vector[2] >= vector[4] && vector[2] >= vector[5] && vector[2] >= vector[6] && vector[2] >= vector[7] && vector[2] >= vector[8] && vector[2] >= vector[9] && vector[2] >= vector[10] && vector[2] >= vector[11])
                {
                    num_dado_apostado = 2;
                }

                else if (vector[3] >= vector[0] && vector[3] >= vector[1] && vector[3] >= vector[2] && vector[3] >= vector[4] && vector[3] >= vector[5] && vector[3] >= vector[6] && vector[3] >= vector[7] && vector[3] >= vector[8] && vector[3] >= vector[9] && vector[3] >= vector[10] && vector[3] >= vector[11])
                {
                    num_dado_apostado = 2;
                    cantidad_apostada += 1;
                }
                else if (vector[4] >= vector[0] && vector[4] >= vector[1] && vector[4] >= vector[2] && vector[4] >= vector[3] && vector[4] >= vector[5] && vector[4] >= vector[6] && vector[4] >= vector[7] && vector[4] >= vector[8] && vector[4] >= vector[9] && vector[4] >= vector[10] && vector[4] >= vector[11])
                    num_dado_apostado = 3;
                else if (vector[5] >= vector[0] && vector[5] >= vector[1] && vector[5] >= vector[2] && vector[5] >= vector[3] && vector[5] >= vector[4] && vector[5] >= vector[6] && vector[5] >= vector[7] && vector[5] >= vector[8] && vector[5] >= vector[9] && vector[5] >= vector[10] && vector[5] >= vector[11])
                {
                    num_dado_apostado = 3;
                    cantidad_apostada += 1;
                }
                else if (vector[6] >= vector[0] && vector[6] >= vector[1] && vector[6] >= vector[2] && vector[6] >= vector[3] && vector[6] >= vector[4] && vector[6] >= vector[5] && vector[6] >= vector[7] && vector[6] >= vector[8] && vector[6] >= vector[9] && vector[6] >= vector[10] && vector[6] >= vector[11])
                    num_dado_apostado = 4;
                else if (vector[7] >= vector[0] && vector[7] >= vector[1] && vector[7] >= vector[2] && vector[7] >= vector[3] && vector[7] >= vector[4] && vector[7] >= vector[5] && vector[7] >= vector[6] && vector[7] >= vector[8] && vector[7] >= vector[9] && vector[7] >= vector[10] && vector[7] >= vector[11])
                {
                    num_dado_apostado = 4;
                    cantidad_apostada += 1;
                }
                else if (vector[8] >= vector[0] && vector[8] >= vector[1] && vector[8] >= vector[2] && vector[8] >= vector[3] && vector[8] >= vector[4] && vector[8] >= vector[5] && vector[8] >= vector[6] && vector[8] >= vector[7] && vector[8] >= vector[9] && vector[8] >= vector[10] && vector[8] >= vector[11])
                    num_dado_apostado = 5;
                else if (vector[9] >= vector[0] && vector[9] >= vector[1] && vector[9] >= vector[2] && vector[9] >= vector[3] && vector[9] >= vector[4] && vector[9] >= vector[5] && vector[9] >= vector[6] && vector[9] >= vector[7] && vector[9] >= vector[8] && vector[9] >= vector[10] && vector[9] >= vector[11])
                {
                    num_dado_apostado = 5;
                    cantidad_apostada += 1;
                }
                else if (vector[10] >= vector[0] && vector[10] >= vector[1] && vector[10] >= vector[2] && vector[10] >= vector[3] && vector[10] >= vector[4] && vector[10] >= vector[5] && vector[10] >= vector[6] && vector[10] >= vector[7] && vector[10] >= vector[8] && vector[10] >= vector[9] && vector[10] >= vector[11])
                    num_dado_apostado = 6;
                else if (vector[11] >= vector[0] && vector[11] >= vector[1] && vector[11] >= vector[2] && vector[11] >= vector[3] && vector[11] >= vector[4] && vector[11] >= vector[5] && vector[11] >= vector[6] && vector[11] >= vector[7] && vector[11] >= vector[8] && vector[11] >= vector[9] && vector[11] >= vector[10])
                {
                    num_dado_apostado = 6;
                    cantidad_apostada += 1;
                }

                //printf("\n\n");
                //printf("%i\n", num_dado_apostado);
                //printf("%i\n", cantidad_apostada);
                printf("El programa te esta apostando %i veces el dado %i", cantidad_apostada, num_dado_apostado);
                printf("\n\n");
                }
               break;
          case 'm':
          case 'M':
            printf("Mentiroso!!\n");
            imprime(dados_jugador1, 5);
            printf("\n");
            imprime(dados_jugador2, 5);
            printf("\n\n");

            h=1;

            mentiroso(fondo,windowSurface,ventana,h);

            for(i = 0; i < n; i++)
            {
                if(num_dado_apostado == dados_jugador1[i])
                comprobador++;
            }
            for(i = 0; i < n; i++)
            {
                if(num_dado_apostado == dados_jugador2[i])
                comprobador++;
            }
            //printf("%i\n", comprobador);

            if(comprobador < cantidad_apostada)
            {
                printf("Tuviste razon!!\n");
                printf("GANASTE!!!\n");

                victoria(fondo,windowSurface,ventana);
                todosdados(windowSurface,dados_jugador1,dados_jugador2,Dado,Dadoia,locdado,locdadoia,ventana);

            }
            else
            {
                printf("La IA no es mentirosa...\n");
                printf("PERDISTE!\n");


                derrota(fondo,windowSurface,ventana);
                todosdados(windowSurface,dados_jugador1,dados_jugador2,Dado,Dadoia,locdado,locdadoia,ventana);
            }
            aux = 1;
            break;



          }

    }while(aux == 0);

    Sleep(5000);

    SDL_QUIT;
    SDL_DestroyWindow(ventana);

    //printf("\n");
    //printf("%i\n", cantidad_apostada);
    //printf("%i\n", num_dado_apostado);
    //printf("%i\n", t);

    return t;
}
