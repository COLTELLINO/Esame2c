#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atleti.h"

// Funzione per creare un nuovo nodo
Nodo* creaNodo(char* nome_atleta, float tempo) {
    Nodo* nuovoNodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuovoNodo->atleta.nome, nome_atleta);
    nuovoNodo->atleta.tempo = tempo;
    nuovoNodo->prossimo = NULL;
    return nuovoNodo;
}

// Funzione per inserire un atleta nella lista in ordine crescente di tempo
void inserisciAtleta(Nodo** testa, Nodo** nuovoAtleta) {
    // Caso speciale: la lista è vuota o il nuovo atleta ha il tempo più basso
    if (*testa == NULL || (*nuovoAtleta)->atleta.tempo < (*testa)->atleta.tempo) {
        (*nuovoAtleta)->prossimo = *testa;
        *testa = *nuovoAtleta;
    }
    else {
        Nodo* corrente = *testa;
        // Trova il punto di inserimento in ordine crescente di tempo
        while (corrente->prossimo != NULL && corrente->prossimo->atleta.tempo < (*nuovoAtleta)->atleta.tempo) {
            corrente = corrente->prossimo;
        }
        (*nuovoAtleta)->prossimo = corrente->prossimo;
        corrente->prossimo = *nuovoAtleta;
    }
}

// Funzione per stampare la lista degli atleti
void stampaAtleti(Nodo* testa) {
    Nodo* corrente = testa;
    printf("Elenco degli atleti:\n");
    while (corrente != NULL) {
        printf("Nome: %s\n", corrente->atleta.nome);
        printf("Tempo: %.2f\n", corrente->atleta.tempo);
        printf("----------------------\n");
        corrente = corrente->prossimo;
    }
}

// Funzione per liberare la memoria occupata dalla lista
void liberareLista(Nodo* testa) {
    Nodo* corrente = testa;
    while (corrente != NULL) {
        Nodo* successivo = corrente->prossimo;
        free(corrente);
        corrente = successivo;
    }
}