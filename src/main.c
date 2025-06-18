#include <stdio.h>
#include <stdlib.h>

//#include <encuesta.h>
//#include <respuesta.h>

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
        printf("Seleccione una opci�n: \n");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Crear encuesta\n");
                // Aquí se llamaría a la función para crear una encuesta
                break;
            case 2:
                printf("Responder encuesta\n");
                // Aquí se llamaría a la función para responder una encuesta
                break;
            case 3:
                printf("Mostrar resultados\n");
                // Aquí se llamaría a la función para mostrar los resultados de las encuestas
                break;
            case 4:
                printf("Salida exitosa del programa\n");
                break;
            default:
                printf("Opci�n no v�lida. Intente de nuevo.\n");
        }
    } while (opcion != 4);


}
