#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
#include "Lista.h"

void bienvenida(Lista lisPersonas);
void menu(Lista lisPersonas,Lista lisCartones);
void comprarCarton(Persona p,Lista lisCartones);
void mostrarCartonesComprados(Lista lisCartones);
void compararCartones(Lista lisCartones);


#endif // INTERFAZ_H_INCLUDED
