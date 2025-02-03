#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produs {
    int cod;
    struct produs* urm;
}produs;

typedef struct magazin {
    char nume[20];
    struct produs* ls;
    struct magazin* lp;
}magazin;

produs* new_produs(int cod)
{
    produs* p = (produs*)malloc(1 * sizeof(produs));
    if (p == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->cod = cod;
    p->urm = NULL;
    return p;
}

produs* adauga_produs(int cod, produs* lista)
{
    produs* p = new_produs(cod);

    if (lista == NULL)
        return p;
    if (p->cod < lista->cod)
    {
        p->urm = lista;
        lista = p;
        return lista;
    }
    produs* q;
    for (q = lista; q->urm != NULL; q = q->urm)
    {
        if (q->urm->cod > p->cod)
        {
            p->urm = q->urm;
            q->urm = p;
            return lista;
        }
    }
    q->urm = p;
    return lista;
}

magazin* new_magazin(char nume[20])
{
    magazin* p = (magazin*)malloc(1 * sizeof(magazin));
    if (p == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    strcpy(p->nume, nume);
    p->ls = NULL;
    p->lp = NULL;
    return p;

}

magazin* adauga_magazin(char nume[20], magazin* lista)
{
    magazin* p = new_magazin(nume);
    p->lp = lista;
    lista = p;
    return lista;
}

void afisare(magazin* lista)
{
    for (magazin* i = lista; i != NULL; i = i->lp)
    {
        printf("magazin:%s produse: ", i->nume);
        for (produs* j = i->ls; j != NULL; j = j->urm)
            printf(" %3d ", j->cod);
        printf("\n");
    }
    printf("\n");
}

magazin* adauga(magazin* lista, char nume[20], int cod)
{
    for (magazin* i = lista; i != NULL; i = i->lp)
    {
        if (strcmp(i->nume, nume) == 0)
            i->ls = adauga_produs(cod, i->ls);
    }
    return lista;
}

magazin* elimina(magazin* lista, int cod)
{
    produs* tmp = NULL;
    for (magazin* i = lista; i != NULL; i = i->lp)
    {
        if (i->ls->cod == cod)
        {
            tmp = i->ls;
            i->ls = i->ls->urm;
            free(tmp);
        }

        produs* j;
        for (j = i->ls; j->urm->urm != NULL; j = j->urm);
        if (j->urm->cod == cod)
        {
            tmp = j->urm;
            j->urm = NULL;
            free(tmp);
        }

        for (j = i->ls; j->urm != NULL; j = j->urm)
        {
            if (j->urm->cod == cod)
            {
                tmp = j->urm;
                j->urm = j->urm->urm;
                free(tmp);
            }
        }

    }
    return lista;
}

int main()
{
    magazin* lista = NULL;
    lista = adauga_magazin("m1", lista);
    lista = adauga_magazin("m2", lista);
    lista = adauga_magazin("m3", lista);
    lista = adauga(lista, "m1", 003);
    lista = adauga(lista, "m1", 001);
    lista = adauga(lista, "m1", 002);
    lista = adauga(lista, "m1", 006);
    lista = adauga(lista, "m1", 005);

    lista = adauga(lista, "m2", 003);
    lista = adauga(lista, "m2", 001);
    lista = adauga(lista, "m2", 012);
    lista = adauga(lista, "m2", 010);
    lista = adauga(lista, "m2", 005);

    lista = adauga(lista, "m3", 003);
    lista = adauga(lista, "m3", 001);
    lista = adauga(lista, "m3", 022);
    lista = adauga(lista, "m3", 056);
    lista = adauga(lista, "m3", 015);
    afisare(lista);

    lista = elimina(lista, 1);
    lista = elimina(lista, 10);
    afisare(lista);

    return 0;
}