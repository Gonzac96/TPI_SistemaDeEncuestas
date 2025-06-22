#include <stdio.h>
#include <stdlib.h>
#include "encuesta.h"
#include "respuesta.h"

int main() {
    menu();
    return 0;
}

void menu(void) {
    int opcion;
	initCatalogo();

    do {
        printf("\n--- Sistema de Encuestas ---\n");
        printf("1. Responder encuesta de Tecnologia\n");
        printf("2. Mostrar resultados\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
		if (scanf("%d", &opcion) != 1) {
			while (getchar()!='\n'); 
			continue; 
		}
		
        switch (opcion) {
            case 1:
                printf("\nHa elegido responder la encuesta\n");
                responderEncuesta();
                break;
            case 2:
                printf("\nMostrar resultados\n");
                mostrarResultados();
                break;
            case 3:
                printf("\nSalida exitosa del programa\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 3);
}
