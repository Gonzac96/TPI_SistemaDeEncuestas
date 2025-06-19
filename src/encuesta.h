#ifndef ENCUESTA_H
#define ENCUESTA_H

typedef struct {
	int id;         
	char texto[100]; 
	int contador;    
} Opcion;

typedef struct {
	int id;         
	char texto[200];       
	Opcion *opciones;      
	int num_opciones;      
} Pregunta;

typedef struct {
	int id;  
	char titulo[100];     
	Pregunta *preguntas;   
	int num_preguntas;    
} Encuesta;

// Prototipos de funciones (a implementar en encuesta.c)
void crearEncuesta();
void mostrarEncuestas();
void guardarEncuesta(Encuesta *e);
Encuesta *cargarEncuesta(int *cantidad);

#endif
