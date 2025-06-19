#ifndef RESPUESTA_H
#define RESPUESTA_H

typedef struct Respuesta {
	int id_pregunta;
	int id_opcion_seleccionada;
	struct Respuesta *siguiente;
} Respuesta;

// Prototipos de funciones
void registrarRespuestas();
void mostrarResultadosOrdenados();

#endif
