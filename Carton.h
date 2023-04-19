#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#include "Persona.h"
#include "Lista.h"

struct cartonEstructura;

typedef struct cartonEstructura * Carton;

Carton crearCarton(int vec[], int dni);
void setVector(Carton cart,int vec[8]);
void mostrarCarton(Carton car,Lista lisPersonas);
void comparer(Carton cart, int * vec);



#endif // CARTON_H_INCLUDED
