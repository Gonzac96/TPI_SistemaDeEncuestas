#include <stdio.h>
#include <stdlib.h>
#include "encuesta.h"
#include "respuesta.h"

/* ------------ lista dinamica ------------- */
static Respuesta *lista = NULL;

static void push(int idPreg, int idOpt)
{
	Respuesta *n = malloc(sizeof(Respuesta));
	if (!n){ perror("malloc"); exit(1); }
	n->id_pregunta = idPreg;
	n->id_opcion   = idOpt;
	n->siguiente = lista;
	lista = n;
}

/* --------- responder encuesta ------------- */
void responderEncuesta(void)
{
	int n;                         /* siempre 1, pero se mantiene generico */
	const Encuesta *e = obtenerCatalogo(&n);
	
	for (int p=0; p<e[0].num_preguntas; p++){
		const Pregunta *pr = &e[0].preguntas[p];
		printf("\n%d) %s\n", pr->id, pr->texto);
		for (int o=0;o<pr->num_opciones;o++)
			printf("   %d. %s\n", pr->opciones[o].id, pr->opciones[o].texto);
		
		int sel;
		do {
			printf("Seleccione opcion (1-4): ");
			if (scanf("%d",&sel)!=1){ while(getchar()!='\n'); sel=0; }
		} while (sel<1 || sel>4);
		while(getchar()!='\n');
		
		((Encuesta*)e)->preguntas[p].opciones[sel-1].contador++;
		push(pr->id, sel);
	}
	puts("\nGracias. Sus respuestas han sido registradas.");
}

/* ----- ordenar opciones (Bubble Sort) ----- */
static void swap(Opcion *a,Opcion *b){ Opcion t=*a; *a=*b; *b=t; }

static void ordenar(Opcion *v,int n){
	for(int i=0;i<n-1;i++)
		for(int j=0;j<n-1-i;j++)
		if(v[j].contador < v[j+1].contador)
		swap(&v[j],&v[j+1]);
}
	
	/* ---------- mostrar resultados ------------ */
	void mostrarResultados(void)
	{
		int n;
		const Encuesta *e = obtenerCatalogo(&n);
		
		puts("\n=== Resultados encuesta Tecnologia ===");
		for (int p=0;p<e[0].num_preguntas;p++){
			Pregunta pr = e[0].preguntas[p];   /* copia local */
			ordenar(pr.opciones, pr.num_opciones);
			
			printf("\n%d) %s\n", pr.id, pr.texto);
			for (int o=0;o<pr.num_opciones;o++)
				printf("   %-12s : %d\n",
					   pr.opciones[o].texto,
					   pr.opciones[o].contador);
		}
	}
	
