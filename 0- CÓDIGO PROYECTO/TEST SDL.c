/**<
#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declara un puntero

    SDL_Init(SDL_INIT_VIDEO);              // Inicializa SDL2

    // Crea una aplicaci�n "ventana" con las siguientes caracter�sticas:
    window = SDL_CreateWindow(
        "COMPROBACION DE SDL",                  // T�tulo de la ventana emergente
        SDL_WINDOWPOS_UNDEFINED,           // Inicializa posici�n x
        SDL_WINDOWPOS_UNDEFINED,           // Inicializa posici�n x
        1200,                               // Anchura en pixels
        700,                               // Altura en pixels
        SDL_WINDOW_OPENGL                  // flags
    );

    // Comprobamos la creaci�n de la ventana
    if (window == NULL) {
        // En el caso de no pode crearse esta muestra un mensaje de error
        printf("No se puedo crear la ventana: %s\n", SDL_GetError());
        return 1;
    }



    SDL_Delay(3000);  // Pausa la ejecucion durante 3000 milisegundos

    // Cierra y elimina/destruye la ventana
    SDL_DestroyWindow(window);

    // Limpia los residuos
    SDL_Quit();
    return 0;
}

  */
