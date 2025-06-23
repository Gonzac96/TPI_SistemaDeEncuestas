#include <stdio.h>
#include <stdlib.h>
#include "encuesta.h"
#include "respuesta.h"

/* ------------ lista enlazada de todas las respuestas ---------- */
static Respuesta *lista = NULL;

static void push(int idPreg, int idOpt) {
	Respuesta *n = malloc(sizeof(Respuesta));
	if (!n){ perror("malloc"); exit(1); }
	n->id_pregunta = idPreg;
	n->id_opcion   = idOpt;
	n->siguiente = lista;
	lista = n;
}

/* ====== algoritmo de ORDENACIÓN (Bubble Sort) ====== */
static void swap(Opcion *a, Opcion *b){
	Opcion t=*a; *a=*b; *b=t; 
}

static void ordenarPorFrecuencia(Opcion *v,int n){
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
		if(v[j].contador < v[j+1].contador)
		swap(&v[j],&v[j+1]);
}
	
	/* --------------- responder encuesta ---------------- */
void responderEncuesta(void) {
	int dummy;                       /* sólo 1 encuesta, pero mantenemos la API */
	const Encuesta *enc = obtenerCatalogo(&dummy);   /* enc apunta al catálogo */
		
	for (int id = 1; id <= enc->num_preguntas; id++) {
		/* búsqueda binaria de la pregunta por id */
		const Pregunta *pr = buscarPreguntaPorId(enc, id);
			
		printf("\n%d) %s\n", pr->id, pr->texto);
		for (int o=0;o<pr->num_opciones;o++) {
			printf("   %d. %s\n", pr->opciones[o].id, pr->opciones[o].texto);
		}
		int sel;
		do {
			printf("Seleccione opcion (1-%d): ", pr->num_opciones);
			if (scanf("%d",&sel)!=1) {
				while(getchar()!='\n');
				sel=0;
			}
		} while (sel<1 || sel>pr->num_opciones);
		while(getchar()!='\n');
			
		/* incrementa contador (en el catálogo “const” se hace cast) */
		((Encuesta*)enc)->preguntas[id-1].opciones[sel-1].contador++;
		push(id, sel);
	}
	printf("\nGracias. Sus respuestas han sido registradas.\n");
}
	
/* --------------- mostrar resultados ---------------- */
void mostrarResultados(void) {
	int dummy;
	const Encuesta *enc = obtenerCatalogo(&dummy);
	
	printf("\n============ Resultados de la encuesta ============");
		
	for (int p = 0; p < enc->num_preguntas; p++) {
		
		/* copia local para ordenar sin tocar el catálogo */
		Pregunta pr = enc->preguntas[p];
		ordenarPorFrecuencia(pr.opciones, pr.num_opciones);
		
		/* total de votos */
		int total = 0;
		for (int i = 0; i < pr.num_opciones; i++)
			total += pr.opciones[i].contador;
		
		printf("\n%d) %s  (total = %d)\n", pr.id, pr.texto, total);
		
		for (int o = 0; o < pr.num_opciones; o++)
			printf("   %-12s : %3d votos (%.1f%%)\n",
				   pr.opciones[o].texto,
				   pr.opciones[o].contador,
				   total ? pr.opciones[o].contador * 100.0 / total : 0.0);
		
		/* ------- MODA -------- */
		if (total == 0) {
			puts("   >> Sin votos aun.");
			continue;
		}
		
		int   modaCnt = pr.opciones[0].contador;      /* mayor frecuencia */
		double modaPct = modaCnt * 100.0 / total;
		
		/* contar cuántas opciones empatan con la moda */
		int numModas = 0;
		while (numModas < pr.num_opciones &&
			   pr.opciones[numModas].contador == modaCnt)
			numModas++;
		
		/* imprimir todas las modas separadas por “ / ” */
		printf("   >> Moda%s: ", numModas > 1 ? "s" : "");
		for (int i = 0; i < numModas; i++) {
			printf("\"%s\"", pr.opciones[i].texto);
			if (i < numModas - 1) printf(" / ");
		}
		printf(" -> %d votos (%.1f%%)\n", modaCnt, modaPct);
	}
}
