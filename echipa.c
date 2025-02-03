#include <stdio.h>
#include <string.h>
#define N 5
typedef struct {
    char nume[25];
    int puncte;
    int buget;
    char oras[25];
}echipa;

void swap(echipa* e1, echipa* e2)
{
    echipa tmp;
    tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

void afisare(echipa v[], int indexi[]) {
    for (int i = 0; i < N; i++) {
        printf("Nume: %s, Puncte: %d, Buget: %d, Oras: %s\n", v[indexi[i]].nume, v[indexi[i]].puncte, v[indexi[i]].buget, v[indexi[i]].oras);
    }
}

void mutare(echipa* v)
{
    int b = 0;
    int f = N - 1;
    for (int i = 0; i < N; i++)
    {
        if (v[i].puncte > 45)
        {
            swap(&v[b], &v[i]);
            b++;
        }
        if (v[i].puncte < 20)
        {
            swap(&v[f], &v[i]);
            f--;
        }
    }
}

void quicksort(echipa a[], int indexi[], int prim, int ultim)
{
    int stanga = prim + 1;
    int dreapta = ultim;
    //alegere pivot
    swap(&a[indexi[prim]], &a[indexi[(prim + ultim) / 2]]);
    //mutare pivot pe prima pozitie
    echipa pivot = a[indexi[prim]];
    while (stanga <= dreapta) //partitionare
    {
        while (stanga <= ultim && a[indexi[stanga]].puncte >= pivot.puncte)
            stanga++;
        while (dreapta >= prim && pivot.puncte > a[indexi[dreapta]].puncte)
            dreapta--;
        if (stanga < dreapta)
            swap(&indexi[stanga++], &indexi[dreapta--]);
        else
            stanga++;
    }
    //mutare pivot la locul sau final
    swap(&a[indexi[dreapta]], &a[indexi[prim]]);
    //apelurile recursive
    if (prim < dreapta - 1)
        quicksort(a, indexi, prim, dreapta - 1);
    if (dreapta + 1 < ultim)
        quicksort(a, indexi, dreapta + 1, ultim);
}

void sortare_buget(echipa a[], int indexi[]) {
    // Creăm o listă cu echipele care au buget > 100000
    int filtreazaIndexi[N];
    int numarEchipeFiltrate = 0;
    for (int i = 0; i < N; i++) {
        if (a[i].buget > 100000) {
            filtreazaIndexi[numarEchipeFiltrate] = i;
            numarEchipeFiltrate++;
        }
    }

    // Apelăm quicksort doar pe echipele filtrate
    quicksort(a, filtreazaIndexi, 0, numarEchipeFiltrate - 1);
}
int main() {
    echipa v[N] = {
        {"Echipa1", 50, 120000, "Oras1"},
        {"Echipa2", 30, 80000, "Oras2"},
        {"Echipa3", 60, 150000, "Oras3"},
        {"Echipa4", 40, 200000, "Oras4"},
        {"Echipa5", 20, 50000, "Oras5"}
    };

    int indexi[N] = { 0, 1, 2, 3, 4 }; // Indexurile echipelor, pentru a le sorta

    printf("Inainte de sortare:\n");
    afisare(v, indexi);
    
    // Apelăm funcția de sortare pe echipele cu buget > 100.000
    sortare_buget(v, indexi);

    printf("\nDupa sortare:\n");
    afisare(v, indexi);

    return 0;
}