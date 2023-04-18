#include "Persona.h"
#include "Interfaz.h"
#include "Carton.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bienvenida(Lista lisPersonas){
printf("***************Quiniela***************\n");
printf("Porfavor ingrese su nombre: \n");

char nombre[20];
scanf("%s",&nombre);
fflush(stdin);
system("CLS");
printf("***************Quiniela***************\n");
printf("Porfavor ingrese su DNI: \n");
int dni=0;
scanf("%i",&dni);
fflush(stdin);
system("CLS");


Persona p1 = crearPersona(nombre,dni);
insertarInicio(lisPersonas,&p1);
};

menu(Lista lisPersonas,Lista lisCartones){

     Persona p= *( (Persona*)obtenerPrimerDato(lisPersonas));
  int n, opcion;

    do
    {
        system("CLS");
        printf("***************Quiniela***************\n");
        printf( "\n   1. Comprar carton." );
        printf( "\n   2. Mostrar cartones." );
        printf( "\n   3. Comparar cartones." );
        printf( "\n   4. Salir." );
        printf( "\n\n   Introduzca opcion (1-4): ");

        scanf( "%d", &opcion );

        /* Inicio del anidamiento */

        switch ( opcion )
        {
            case 1:
                    comprarCarton(p,lisCartones);
                    break;

            case 2:
                    mostrarCartonesComprados(lisCartones);
                    break;


            case 3:
                    compararCartones(lisCartones);
                    break;
         }

         /* Fin del anidamiento */

    } while ( opcion != 4 );
}


void comprarCarton(Persona p,Lista lisCartones){
    int numero=0;
    int nCarton[8];
    system("CLS");
    printf("***************Quiniela***************\n");
    printf("Elija los 8 numeros de su carton \n");
    for(int i=0; i<8;i++){
        printf("\n%d numero: ",i);
        scanf("%d",&numero);
        nCarton[i]=numero;
    }

    Carton cart= crearCarton(nCarton,p);
    insertarInicio(lisCartones,&cart);


    printf("\n");
    system("pause");
};

void mostrarCartonesComprados(Lista lisCartones){
    //Variables

    //Logica
    system("CLS");
    printf("***************Quiniela***************\n");


    for(int i=0;i<obtenerTamanio(lisCartones);i++){

        Carton cart= *( (Carton*)obtenerDato(lisCartones,i));
        mostrarCarton(cart);
    }

printf("\n");
system("pause");
};

void compararCartones(Lista lisCartones){
    //Variables
    int randon=0;
    int vect[8];
    vect[8];
    //Logica
    system("CLS");
    printf("***************Quiniela***************\n");

    if(obtenerTamanio(lisCartones)==0){
        printf("Primero debe comprar una carton \n\n");
        system("pause");
        return;

    }

    vectorCargado(vect);
    printf("Carton Ganador:\n");
    for(int i=0;i<8;i++){
        printf("%d ",vect[i]);
    }
    printf("\n******************************\n");



    for(int i=0;i<obtenerTamanio(lisCartones);i++){

        Carton cart= *( (Carton*)obtenerDato(lisCartones,i));
        mostrarCarton(cart);
        comparer(cart,vect);

    }

liberarlista(lisCartones);

printf("\n");
system("pause");
};




void vectorCargado(int * vec){

int numero=0;
 srand(time(NULL)); //Generamos numero aleatorio en base al tiempo

for(int i=0;i<8;i++){

    numero=rand() % 11; //Le indicamos que el numero será entre 0-10
    vec[i]=numero;
}


};
