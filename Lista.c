#include "lista.h"
#include <stdlib.h>
#include <string.h>


struct NodoE {
    void * data;
    Nodo proximo;
};

struct listaE{
    Nodo primero;
    Nodo ultimo;
    int tamanio;
    int tamDelDatoEnBytes;
};


///Constructor del nodo
Nodo crearNodo (Lista lista, void *data) {
    Nodo temp =  malloc(sizeof (struct NodoE));

    //if (!temp) return FALSE;

    temp->data = malloc(lista->tamDelDatoEnBytes);

    if (!temp->data) {
        free(temp);
        return temp;
    }

   ///Analizar
    memcpy(temp->data, data, lista->tamDelDatoEnBytes);

    return temp;
}


///Constructor de la lista
Lista crearLista( int tamDelDatoEnBytes) {

    Lista lista = malloc(sizeof(struct listaE));



    lista->primero = lista->ultimo = NULL;
    lista->tamanio = 0;
    lista->tamDelDatoEnBytes = tamDelDatoEnBytes;

    return lista;
}


//lista vacia
int estaVacia ( Lista lista) {
    if (!lista)
        return TRUE;
    return (lista->tamanio == 0);
}



int obtenerTamanio ( Lista lista) {
    if (!lista)
        return -1;
    return lista->tamanio;
}

void* obtenerDato (Lista lista, int pos) {
    if (!lista || pos < 0 || lista->tamanio <= 0 || pos >= lista->tamanio)
        return NULL;

    if (pos == 0)
        return lista->primero->data;

    if (pos == lista->tamanio - 1)
        return lista->ultimo->data;

    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }

    return f->proximo->data;
}

void *obtenerPrimerDato( Lista lista) {
    if (!lista)
        return NULL;
    return lista->primero->data;
}

void *obtenerUltimoDato( Lista lista) {
    if (!lista)
        return NULL;
    return lista->ultimo->data;
}


int obtenerDatoEnParametro ( Lista lista, int pos, void *backup) {
    if (!lista || pos < 0 || lista->tamanio <= 0 || pos >= lista->tamanio) // lista vazia ou posição nula
        return FALSE;

    if (pos == 0) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        return TRUE;
    }

    if (pos == lista->tamanio - 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        return TRUE;
    }

    Nodo f;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }

    memcpy(backup, f->proximo->data, lista->tamDelDatoEnBytes);
    return TRUE;
}

int insertarInicio (Lista lista, void *data) {
    Nodo temp;
    if (!(temp = crearNodo(lista, data)))
        return FALSE;

    if (lista->tamanio == 0) {
        lista->primero = lista->ultimo = temp;
        temp->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    }

    temp->proximo = lista->primero;
    lista->primero = temp;
    lista->tamanio++;

    return TRUE;
}

int insertarFinal (Lista lista, void *data) {
    Nodo temp;
    if (!(temp = crearNodo(lista, data)))
        return FALSE;

    if (lista->tamanio == 0) {
        lista->primero = lista->ultimo = temp;
        temp->proximo = NULL;
        lista->tamanio++;
        return TRUE;
    } else {
        lista->ultimo->proximo = temp;
        lista->ultimo = temp;
        lista->ultimo->proximo = NULL;
    }

    lista->tamanio++;
    return TRUE;
}

int removerInicio (Lista lista, void *backup) {
	if (lista->tamanio == 0)
		return FALSE;
    else if (lista->tamanio == 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        liberarlista(lista); // Portanto, apenas limpe a lista!
    } else {
        Nodo proximoCpy = lista->primero->proximo;
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);

        free(lista->primero->data);
        free(lista->primero);
        lista->primero = proximoCpy;
        lista->tamanio--;
    }
    return TRUE;
}

int removerFinal (Lista lista, void *backup) {
    if (!lista)
        return FALSE;

    // Se a lista tiver apenas 1 elemento
    if (lista->tamanio == 1) {
        memcpy(backup, lista->primero->data, lista->tamDelDatoEnBytes);
        liberarlista(lista);
    }
    // A lista possui mais de um elemento
    else {
        Nodo f = NULL, ultimo = NULL;
        memcpy(backup, lista->ultimo->data, lista->tamDelDatoEnBytes);

        // Percorre a lista até encontrar o penúltimo elemento da lista
        for (f = lista->primero; f != lista->ultimo; f = f->proximo)
            ultimo = f;

        // Nesse momento 'ultimo' aponta para o penúltimo elemeto da lista

        free(lista->ultimo->data); // Remove o dado do último elemento
        free(lista->ultimo); // Remove o último elemento
        lista->ultimo = ultimo; // Agora o último elemento se torna 'ultimo'
        lista->ultimo->proximo = NULL; // Portanto ultimo->proximo deve ser NULL
        lista->tamanio--;
    }
    return TRUE;
}

int insertar (Lista lista, void *data, int pos) {

    if (!lista || pos < 0 || pos > lista->tamanio) // lista nula ou posição inválida
        return FALSE;

    if (pos == 0) // Insere na primeira posição
        return insertarInicio(lista, data);

    if (pos == lista->tamanio) // Insere na última posição
        return removerFinal(lista, data);

    // Insere no meio

    Nodo f = NULL;
    for ( int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }
    // Nesse momento 'f' aponta para a posição anterior à que será inserido o elemento

    Nodo temp;
    if (!(temp = crearNodo(lista, data)))
        return FALSE;

    temp->proximo = f->proximo;
    f->proximo = temp;
    lista->tamanio++;
    return TRUE;
}

int remover (Lista lista, int pos, void *backup) {

    if (!lista || lista->tamanio<= 0 || pos < 0 || pos >= lista->tamanio) // lista vazia ou nula ou posição inválida
        return FALSE;

    // Remove da última posição
    if (pos == lista->tamanio - 1)
        return removerFinal(lista, backup);

    // O usiário deseja remover um elemento do início
    if (pos == 0)
        return removerInicio(lista, backup);

    // Remover algum elemento no MEIO da lista
    Nodo f = NULL, proximoCpy;
    for (int i = 0; i < pos; i++) {
        if (i == 0)
            f = lista->primero;
        else
            f = f->proximo;
    }
    // Nesse momento 'f' aponta para o elemento anterior ao que será removido

    proximoCpy = f->proximo->proximo; // 'proximoCpy' aponta para o elemento posterior ao que será removido
    memcpy(backup, f->proximo->data, lista->tamDelDatoEnBytes);

    free(f->proximo->data); // Remove o VALOR do elemento (Célula) entre 'f' e 'proximoCpy', que pertence justamente o elemento que o usuário deseja remover
    free(f->proximo); // Remove o ELEMENTO entre 'f' e 'proximoCpy', que é justamente o elemento que o usuário deseja remover
    f->proximo = proximoCpy; // Portanto lique 'f' em 'proximoCpy'
    lista->tamanio--;
    return TRUE;
}

void liberarlista (Lista lista) {
    if (!lista || lista->tamanio <= 0 || lista->primero == NULL)
        return;

    // 'curr' iniciará apontando para o primeiro elemento da lista e proximo para o segundo
    // (que pode ser nulo caso a lista possua apenas um elemento)

    Nodo proximo;
    for ( Nodo p = lista->primero; p != NULL;) {
        proximo = p->proximo;
        free(p->data);
        free(p);
        p = proximo;
    }

    lista->primero = NULL;
    lista->ultimo = NULL;
    lista->tamanio= 0;
}
