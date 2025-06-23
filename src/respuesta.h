#ifndef RESPUESTA_H
#define RESPUESTA_H

typedef struct Respuesta {
	int id_pregunta;
	int id_opcion;
	struct Respuesta *siguiente;
} Respuesta;


void responderEncuesta(void); //Donde se resgistran respuestas
void mostrarResultados(void); //Muestra resultados con estadisticas + ordenacion

#endif
