#ifndef ENCUESTA_H
#define ENCUESTA_H

/* --- constantes --- */
#define MAX_ENCUESTAS  1
#define MAX_PREGUNTAS 10
#define MAX_OPCIONES   4
#define TXT_LEN       100

/* --- estructuras --- */
typedef struct {
	int  id;
	char texto[TXT_LEN];
	int  contador;
} Opcion;

typedef struct {
	int    id;
	char   texto[TXT_LEN];
	int    num_opciones;
	Opcion opciones[MAX_OPCIONES];
} Pregunta;

typedef struct {
	int       id;
	char      titulo[TXT_LEN];
	int       num_preguntas;
	Pregunta  preguntas[MAX_PREGUNTAS];
} Encuesta;

/* --- prototipos --- */
void  initCatalogo(void);
const Encuesta* obtenerCatalogo(int *n);

#endif
