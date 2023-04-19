#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "Carton.h"
#include "Lista.h"


struct PersonaEstructura;

typedef struct PersonaEstructura * Persona;

Persona crearPersona(char  n[20], int p);

void mostrarPersona(Persona p);

int getDni(Persona p);


#endif // PERSONA_H_INCLUDED
