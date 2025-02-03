﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct palet {
    int cod;
    struct palet* urm;
}palet;

typedef struct depozit {
    char nume[20];
    struct depozit* urm_lp;
    struct palet* urm_ls;
}depozit;

palet* new_palet(int cod)
{
    palet* p;
    p = (palet*)malloc(1 * sizeof(palet));
    if (p == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->cod = cod;
    p->urm = NULL;
    return p;
}

palet* adaugaOrdonat(palet* ls, int cod)
{
    palet* p = new_palet(cod);
    if (ls == NULL || ls->cod > p->cod)
    {
        p->urm = ls;
        ls = p;
        return ls;
    }

    palet* q;
    for (q = ls; q->urm != NULL; q = q->urm)
    {
        if (q->urm->cod > p->cod)
        {
            p->urm = q->urm;
            q->urm = p;
            return ls;
        }
    }
    q->urm = p;
    p->urm = NULL;
    return ls;
}

depozit* new_depozit(char nume[20])
{
    depozit* p = (depozit*)malloc(1 * sizeof(depozit));
    if (p == NULL)
    {
        perror(NULL);
        exit(-1);
    }
    strcpy(p->nume, nume);
    p->urm_lp = NULL;
    p->urm_ls = NULL;
    return p;
}

depozit* adauga_depozit(char nume[20], depozit* lp)
{
    depozit* p = new_depozit(nume);
    if (lp == NULL)
    {
        return p;
    }
    depozit* i;
    for (i = lp; i->urm_lp != NULL; i = i->urm_lp);
    i->urm_lp = p;
    return lp;

}

depozit* adaugaPalet(char nume[20], int cod, depozit* lp)
{
    depozit* i;
    for (i = lp; i != NULL; i = i->urm_lp)
    {
        if (strcmp(i->nume, nume) == 0)
        {
            i->urm_ls = adaugaOrdonat(i->urm_ls, cod);
            return lp;
        }
    }
    printf("Depozitul %s nu a fost găsit!\n", nume);
    return lp;
}

depozit* eliminaPalet(int cod, depozit* lp)
{
    depozit* i;
    for (i = lp; i != NULL; i = i->urm_lp)
    {
        if (i->urm_ls->cod == cod)
        {
            palet* tmp;
            tmp = i->urm_ls;
            i->urm_ls = i->urm_ls->urm;
            free(tmp);
        }
        palet* j;
        for (j = i->urm_ls; j->urm->urm != NULL; j = j->urm);
        if (j->urm->cod == cod)
        {
            palet* tmp;
            tmp = j->urm;
            j->urm = NULL;
            free(tmp);
        }

        for (j = i->urm_ls; j->urm != NULL; j = j->urm)
        {

            if (j->urm->cod == cod)
            {
                palet* tmp;
                tmp = j->urm;
                j->urm = j->urm->urm;
                free(tmp);
            }
        }
    }
    return lp;

}

void afisareLS(palet* ls)
{
    for (palet* i = ls; i != NULL; i = i->urm)
    {
        printf("%5d", i->cod);
    }
}

void afisareLP(depozit* lp)
{
    depozit* i;
    for (i = lp; i != NULL; i = i->urm_lp)
    {
        printf("Depozit: %s\nPaleti: ", i->nume);
        afisareLS(i->urm_ls);
        printf("\n");
    }
}

int main()
{

    depozit* lp = NULL;
    lp = adauga_depozit("depozit1", lp);
    lp = adauga_depozit("depozit2", lp);

    lp = adaugaPalet("depozit1", 10, lp);
    lp = adaugaPalet("depozit1", 8, lp);
    lp = adaugaPalet("depozit1", 9, lp);
    lp = adaugaPalet("depozit1", 11, lp);
    lp = adaugaPalet("depozit1", 12, lp);
    lp = adaugaPalet("depozit2", 20, lp);
    lp = adaugaPalet("depozit2", 24, lp);
    lp = adaugaPalet("depozit2", 22, lp);
    lp = adaugaPalet("depozit2", 21, lp);
    lp = adaugaPalet("depozit2", 23, lp);
    afisareLP(lp);

    lp = eliminaPalet(8, lp);
    lp = eliminaPalet(12, lp);
    lp = eliminaPalet(8, lp);
    lp = eliminaPalet(24, lp);
    printf("\n");
    afisareLP(lp);


}