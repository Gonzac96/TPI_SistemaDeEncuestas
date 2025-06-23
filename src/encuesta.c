#include <stdio.h>
#include <string.h>
#include "encuesta.h"

/* ==== catálogo fijo (1 encuesta) ==== */
static Encuesta catalogo[MAX_ENCUESTAS];
static int      catalogo_cargado = 0;

/* Macro para cargar una pregunta (4 opciones) */
#define P(q,text,o1,o2,o3,o4)                                      \
do {                                                           \
catalogo[0].preguntas[q].id = (q)+1;                       \
strcpy(catalogo[0].preguntas[q].texto, (text));            \
catalogo[0].preguntas[q].num_opciones = 4;                 \
strcpy(catalogo[0].preguntas[q].opciones[0].texto, (o1));  \
strcpy(catalogo[0].preguntas[q].opciones[1].texto, (o2));  \
strcpy(catalogo[0].preguntas[q].opciones[2].texto, (o3));  \
strcpy(catalogo[0].preguntas[q].opciones[3].texto, (o4));  \
for (int _i=0; _i<4; _i++){                                \
catalogo[0].preguntas[q].opciones[_i].id = _i+1;       \
catalogo[0].preguntas[q].opciones[_i].contador = 0;    \
}                                                          \
} while (0)

/* Carga única del catálogo */
void initCatalogo(void)
{
	if (catalogo_cargado) return;
	
	catalogo[0].id = 1;
	strcpy(catalogo[0].titulo, "Tecnologia");
	catalogo[0].num_preguntas = 10;
	
	P(0,"Sistema operativo principal",
	  "Windows","macOS","Linux","Otro");
	P(1,"Horas de uso de smartphone al dia",
	  "< 1 h","1-3 h","3-6 h","> 6 h");
	P(2,"Dispositivo principal de trabajo/estudio",
	  "Desktop","Laptop","Tablet","Smartphone");
	P(3,"Uso de almacenamiento en la nube",
	  "Nunca","Ocasional","Frecuente","Constante");
	P(4,"Navegador web principal",
	  "Chrome","Firefox","Edge","Otro");
	P(5,"Lenguaje de programacion favorito",
	  "Python","JavaScript","C/C++","Otro");
	P(6,"Cual es tu principal preocupacion respecto a la tecnologia?",
	  "Privacidad y seguridad de datos","Dependencia o exceso de uso","Obsolencia programada","Impacto ambiental");
	P(7,"Red social que usas mas",
	  "Facebook","Instagram","X/Twitter","TikTok");
	P(8,"Modalidad de compra de tecnologia",
	  "Online","Tienda fisica","Ambos","No suelo comprar");
	P(9,"Que tan familiarizado/a estas con la inteligencia artificial (IA)?",
	  "Demasiado, soy un experto","Bastante, la uso frecuentemente","Algo, pero no la uso mucho","No tengo idea que es");
	
	catalogo_cargado = 1;
}

/* acceso de solo lectura al catálogo */
const Encuesta* obtenerCatalogo(int *n)
{
	*n = MAX_ENCUESTAS; //se devuelve la cantidad
	return catalogo; 	//y el puntero apunta al array
}

/* =========================================================
	BÚSQUEDA BINARIA de pregunta por id dentro de una encuesta
   ========================================================= */
const Pregunta* buscarPreguntaPorId(const Encuesta *enc, int id)
{
	int low = 0, high = enc->num_preguntas - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int midId = enc->preguntas[mid].id;
		if (midId == id)      return &enc->preguntas[mid];
		else if (midId < id)  low  = mid + 1;
		else                  high = mid - 1;
	}
	return NULL;               /* no encontrada */
}
