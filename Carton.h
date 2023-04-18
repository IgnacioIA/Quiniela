#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#include "Persona.h"

struct cartonEstructura;

typedef struct cartonEstructura * Carton;

Carton crearCarton();
void setVector(Carton cart,int vec[8]);
void mostrarCarton(Carton car);
void comparer(Carton cart, int * vec);

void * traerPersona(Carton car);

#endif // CARTON_H_INCLUDED
