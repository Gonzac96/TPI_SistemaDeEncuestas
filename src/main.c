#include <stdio.h>
#include <stdlib.h>
#include "encuesta.h"
#include "respuesta.h"

void menu(void);

int main(void) {
    menu();
    return 0;
}

void menu(void) {
    int opcion;
	initCatalogo();

    do {
		printf("\n+-----------------------------------------+\n");
		printf("|         SISTEMA DE ENCUESTAS            |\n");
		printf("+-----------------------------------------+\n");
		printf("| 1) Responder encuesta Tecnologica       |\n");
		printf("| 2) Mostrar resultados y estadisticas    |\n");
		printf("| 3) Salir                                |\n");
		printf("+-----------------------------------------+\n");
		printf("Seleccione una opcion (1-3): ");
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
                printf("\nSe muestran los resultados y estadisticas de la encuesta\n");
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
