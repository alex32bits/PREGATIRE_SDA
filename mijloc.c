#include <stdio.h>
#include <stdlib.h>

// Structura nodului listei simplu înl?n?uite
typedef struct nod {
    int val;
    struct nod* urm;
} nod;

// Func?ie pentru a crea un nod nou
nod* creare_nod(int val) {
    nod* p = (nod*)malloc(sizeof(nod));
    if (!p) {
        perror("Eroare la alocarea memoriei");
        exit(EXIT_FAILURE);
    }
    p->val = val;
    p->urm = NULL;
    return p;
}

// Func?ie pentru a ad?uga un nod la finalul listei
nod* adauga_la_final(nod* cap, int val) {
    nod* p = creare_nod(val);
    if (!cap)
        return p;
    nod* temp = cap;
    while (temp->urm)
        temp = temp->urm;
    temp->urm = p;
    return cap;
}

// Func?ie pentru a g?si ?i ?terge nodul din mijloc
nod* sterge_elementul_mijlociu(nod* cap) {
    if (!cap || !cap->urm)
        return NULL; // Lista goal? sau cu un singur element

    nod* lent = cap, * rapid = cap, * prev = NULL;

    while (rapid && rapid->urm) {
        rapid = rapid->urm->urm; // Avanseaz? rapid cu doi pa?i
        prev = lent;            // P?streaz? elementul anterior
        lent = lent->urm;       // Avanseaz? lent cu un pas
    }

    // La finalul buclei, lent este elementul din mijloc
    if (prev) {
        prev->urm = lent->urm;  // Elimin? nodul din mijloc
    }
    else {
        cap = lent->urm; // Dac? nodul din mijloc este capul listei
    }

    free(lent); // Elibereaz? memoria nodului ?ters
    return cap;
}

// Func?ie pentru afi?area listei
void afisare_lista(nod* cap) {
    while (cap) {
        printf("%d -> ", cap->val);
        cap = cap->urm;
    }
    printf("NULL\n");
}

// Program principal
int main() {
    nod* lista = NULL;

    // Construim o list? cu un num?r impar de elemente
    lista = adauga_la_final(lista, 1);
    lista = adauga_la_final(lista, 2);
    lista = adauga_la_final(lista, 3);
    lista = adauga_la_final(lista, 4);
    lista = adauga_la_final(lista, 5);

    printf("Lista ini?ial?:\n");
    afisare_lista(lista);

    // ?tergem elementul din mijloc
    lista = sterge_elementul_mijlociu(lista);

    printf("Lista dup? ?tergerea elementului din mijloc:\n");
    afisare_lista(lista);

    return 0;
}
