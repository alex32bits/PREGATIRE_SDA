#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conex {
    int id;
    struct conex* nxt;
}conex;

typedef struct elem {
    int id;
    char nume[35];
    char ocupatie[35];
    struct conex* con;
    struct elem* urm;
}elem;

conex* new(int id)
{
    conex * p = (conex*)malloc(1 * sizeof(conex));
    if (p == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->id = id;
    p->nxt = NULL;
    return p;
}


elem* new_nod(int id, char nume[35], char ocupatie[35])
{
    elem* p;
    p = (elem*)malloc(1 * sizeof(elem));
    if (p == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->id = id;
    strcpy(p->nume, nume);
    strcpy(p->ocupatie, ocupatie);
    p->urm = NULL;
    p->con = NULL;
    return p;
}

elem* adauga(elem* lista, int id, char nume[35], char ocupatie[35])
{
    if (lista == NULL)
        return new_nod(id, nume, ocupatie);

    elem* p = new_nod(id, nume, ocupatie);
    p->urm = lista;
    lista = p;
    return lista;

}

elem* crereCon(elem* lista, int idpers, int idcon)
{
    for (elem* i = lista; i != NULL; i = i->urm)
    {
        if (i->id == idpers)
        {
            if (i->con == NULL)
            {
                i->con = new(idcon);
            }
            else
            {
                conex* q;
                for (q = i->con; q->nxt != NULL; q = q->nxt);
                q->nxt = new(idcon);

            }
        }
    }
    return lista;
}

void Afisconexiuni(conex* lista)
{
    printf("conexiuni: ");
    for (conex* q = lista; q != NULL; q = q->nxt)
    {
        printf("%2d", q->id);
    }
    printf("\n");
}

void afis(elem* lista)
{
    for (elem* i = lista; i != NULL; i = i->urm)
    {
        printf("%s: ", i->nume);
        Afisconexiuni(i->con);
    }
    printf("\n");
}

int main()
{
    elem* lista = NULL;
    lista = adauga(lista, 1, "alex", "fermier");
    lista = adauga(lista, 2, "adi", "avocat");
    lista = adauga(lista, 3, "gabi", "profesor");
    lista = crereCon(lista, 1, 2);
    lista = crereCon(lista, 1, 3);
    lista = crereCon(lista, 2, 1);
    lista = crereCon(lista, 2, 3);
    lista = crereCon(lista, 3, 1);
    lista = crereCon(lista, 3, 2);

    afis(lista);
    return 0;

}
