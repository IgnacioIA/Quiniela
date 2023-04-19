#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>


struct PersonaEstructura{

    char nombre[20];
    int DNI;
};



Persona crearPersona(char  n[20], int p){

    Persona persona = malloc(sizeof(struct PersonaEstructura));

    strcpy(persona->nombre, n);
    persona->DNI = p;

    return persona;
};

void mostrarPersona(Persona p){

    printf("\n----------------PERSONA--------------\n");
    printf("NOMBRE:  %s     DNI:  %d\n\n", p->nombre, p->DNI);

};

int getDni(Persona p){
    return p->DNI;
}


