

// Definizione della struttura dati per un atleta
typedef struct {
    char nome[50];
    float tempo;
} Atleta;

// Definizione della struttura dati per un nodo della lista
typedef struct Nodo {
    Atleta atleta;
    struct Nodo* prossimo;
} Nodo;

// Prototipi delle funzioni
Nodo* creaNodo(char* nome_atleta, float tempo);
void inserisciAtleta(Nodo** testa, Nodo** nuovoAtleta);
void stampaAtleti(Nodo* testa);
void liberareLista(Nodo* testa);