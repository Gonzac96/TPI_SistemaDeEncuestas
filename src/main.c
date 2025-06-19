#include <stdio.h>
#include <stdlib.h>

#include "encuesta.h"
#include "respuesta.h"

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion;

    do {
        printf("\n--- Sistema de Encuestas ---\n");
        printf("1. Crear encuesta\n");
        printf("2. Responder encuesta\n");
        printf("3. Mostrar resultados\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("\nCrear encuesta\n");
                crearEncuesta();
                break;
            case 2:
                printf("\nResponder encuesta\n");
                registrarRespuestas();
                break;
            case 3:
                printf("\nMostrar resultados\n");
                mostrarResultadosOrdenados();
                break;
            case 4:
                printf("\nSalida exitosa del programa\n");
                break;
            default:
                printf("\nOpcion no valida. Intente de nuevo.\n");
        }
    } while (opcion != 4);
}
