#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atleti.h"



int main() {
    Nodo* listaAtleti = NULL;

    // Creazione dei nodi atleta
    Nodo* nuovoAtleta1 = creaNodo("Mario Rossi", 10.75);
    Nodo* nuovoAtleta2 = creaNodo("Luigi Bianchi", 10.65);
    Nodo* nuovoAtleta3 = creaNodo("Giovanni Verdi", 10.80);

    // Inserimento degli atleti nella lista
    inserisciAtleta(&listaAtleti, &nuovoAtleta1);
    inserisciAtleta(&listaAtleti, &nuovoAtleta2);
    inserisciAtleta(&listaAtleti, &nuovoAtleta3);

    // Stampa degli atleti
    stampaAtleti(listaAtleti);

    // Liberazione della memoria
    liberareLista(listaAtleti);

    return 0;
}
