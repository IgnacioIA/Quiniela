#include <stdio.h>
#include <stdlib.h>
#include "Persona.h"
#include "Carton.h"
#include "Interfaz.h"

void mostrarLista (Lista lista) {
    for ( int i = 0; i < obtenerTamanio(lista); ++i) {



        Persona p = *( (Persona*) obtenerDato(lista, i) );
		//printf("%d ", x);
		mostrarPersona(p);
    }
    printf("\n");
}
/*
void carga(int * vec){

int numero=0;
srand(time(NULL));
for(int i=0;i<8;i++){
     //Generamos numero aleatorio en base al tiempo
    numero=rand() % 11; //Le indicamos que el numero será entre 0-10
    printf("%d  ",numero);
    vec[i]=numero;
}


};*/


int main()
{




    Lista lisPersonas= crearLista(sizeof(Persona));
    Lista lisCartones= crearLista(sizeof(Carton));
    bienvenida(lisPersonas);
    mostrarLista(lisPersonas);
    system("pause");
    menu(lisPersonas,lisCartones);




    return 0;
}
