#include "Carton.h"
#include <stdlib.h>
#include <string.h>

struct cartonEstructura{
int vec[8];
int dni;
};

Carton crearCarton(int vec[], int dni){

    Carton car = malloc(sizeof(struct cartonEstructura));


    car->dni = dni;
    for(int i=0; i<8;i++){
    car->vec[i] = vec[i];
}
return car;
};

void mostrarCarton(Carton car,Lista lisPersonas){

Persona p= *( (Persona*)obtenerPrimerDato(lisPersonas));
mostrarPersona(p);

printf("\n********************** \n");
printf("Su carton: \n");

for(int i=0; i<8;i++){
    printf("  %d",car->vec[i]);
}
printf("\n********************** \n");
}


void comparer(Carton cart, int * vec){
    int r=0;
    for(int i=0;i<8;i++){
        if(cart->vec[i]==vec[i]){
            r=r+1;
        }
    }

    switch ( r )
        {
            case 5:
                    printf("\n USTED GANO $50");
                    break;

            case 6:
                    printf("\n USTED GANO $500");
                    break;


            case 7:
                    printf("\n USTED GANO $20.000");
                    break;

            case 8:
                    printf("\n USTED GANO $11.000.000");
                    break;
         }

         if(r < 5 || r > 8){
            printf("SIGA PARTICIPANDO");
         }

}


