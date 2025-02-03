/*
#include <stdio.h>
#include <string.h>
#define N 5
typedef struct{
    char nume[35];
    int varsta;
    int premii;
}student;

void swap(student *s1,student *s2)
{
    student tmp;
    tmp=*s1;
    *s1=*s2;
    *s2=tmp;
}
void mutare(student *v)
{
    int z=0;
    for(int i=0;i<N;i++)
    {
        if(v[i].premii==1)
        {
            swap(&v[z],&v[i]);
            z++;
        }
    }
}

void sortare(student *v)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(strcmp(v[i].nume,v[j].nume)<0 && v[i].premii==1 && v[j].premii==1)
            swap(&v[i],&v[j]);
        }
    }
}

void afisare(student *v)
{
    for(int i=0;i<N;i++)
    {
        printf("%10s  %5d\n",v[i].nume,v[i].premii);
    }
}

int main()
{
    student v[N]={{"alex",20,1},
                  {"adi",19,0},
                  {"art",23,0},
                  {"mani",22,1},
                  {"aana",19,1},
                  };

    afisare(v);
    printf("\n");
    mutare(v);
    afisare(v);
    printf("\n");
    sortare(v);
    afisare(v);

    return 0;
}
*/
/*
#include <stdio.h>
#define N 5

typedef struct {
    char nume[35];
    int salar;
    int bonus;
}angajat;

void swap(angajat *a1,angajat *a2)
{
    angajat tmp;
    tmp=*a1;
    *a1=*a2;
    *a2=tmp;
}

void mutare(angajat *a)
{
    int j=0;
    for(int i=0;i<N;i++)
    {
        if(a[i].bonus==1)
        {
            swap(&a[i],&a[j]);
            j++;
        }
    }
}

void sortare(angajat *a)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(a[i].bonus==0 && a[j].bonus==0)
            {
                if(a[i].salar<a[j].salar)
                    swap(&a[i],&a[j]);
            }
        }
    }
}
void afisare(angajat *a)
{
    for(int i=0;i<N;i++)
    {
        printf("%10s  %5d    %5d\n",a[i].nume,a[i].salar,a[i].bonus);
    }
}

int main()
{
    angajat a[N]={
        {"alex",1200,0},
        {"andi",1900,1},
        {"alin",2000,0},
        {"ale",1800,1},
        {"relu",4000,0},
    };

    afisare(a);
    printf("\n");
    mutare(a);
    afisare(a);
    printf("\n");
    sortare(a);
    afisare(a);

    return 0;
}
*/
/*
#include <stdio.h>
#include <string.h>
#define N 5

typedef struct{
    char nume[25];
    char telefon[10];
    int an;
    int venit;
}agenda;

void swap(agenda *a1,agenda *a2)
{
    agenda tmp;
    tmp=*a1;
    *a1=*a2;
    *a2=tmp;
}

void mutare(agenda *a)
{
    int j=N-1;
    int ct=0;
    for(int i=0;i<N;i++)
    {
        if(a[i].venit<1000 && ct<3)
        {
            swap(&a[i],&a[j]);
            j--;
            ct++;
        }
    }
}

void sortare(agenda *a)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            if(a[i].an<41 && a[i].an>29 && a[j].an<41 && a[j].an>29)
            {
                if(strcmp(a[i].nume,a[j].nume)>0)
                    swap(&a[i],&a[j]);
            }
        }
    }
}

void afisare(agenda *a)
{
    for(int i=0;i<N;i++)
    {
        printf("%10s,%4d,%5d\n",a[i].nume,a[i].an,a[i].venit);
    }
}

int main()
{
    agenda a[N]={
        {"alex","073442434",31,999},
        {"andi","073442434",23,1200},
        {"pao","073442434",35,800},
        {"mada","073442434",34,900},
        {"babi","073442434",49,4000},
    };
    afisare(a);
    printf("\n");
    mutare(a);
    afisare(a);
    printf("\n");
    sortare(a);
    afisare(a);
    printf("\n");
    return 0;
}
*/
/*

#include <stdio.h>
#define n 10
void swap(int* a, int* b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int aranjeaza(int* v)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            swap(&v[j], &v[i]);
            j++;
        }
    }
    return j;
}

void quicksort(int a[], int prim, int ultim)
{
    int stanga = prim + 1;
    int dreapta = ultim;
    //alegere pivot
    swap(&a[prim], &a[(prim + ultim) / 2]);
    //mutare pivot pe prima pozitie
    int pivot = a[prim];
    while (stanga <= dreapta) //partitionare
    {
        while (stanga <= ultim && a[stanga] < pivot)
            stanga++;
        while (dreapta >= prim && pivot < a[dreapta])
            dreapta--;
        if (stanga < dreapta)
            swap(&a[stanga++], &a[dreapta--]);
        else
            stanga++;
    }
    //mutare pivot la locul sau final
    swap(&a[dreapta], &a[prim]);
    //apelurile recursive
    if (prim < dreapta - 1)
        quicksort(a, prim, dreapta - 1);
    if (dreapta + 1 < ultim)
        quicksort(a, dreapta + 1, ultim);
}

void afis(int* v)
{
    for (int i = 0; i < n; i++)
    {
        printf("%5d", v[i]);
    }
    printf("\n");
}

int main()
{
    int v[n] = { 1,10,-3,3,7,9,2,-6,4,-8 };
    afis(v);
    int prim = aranjeaza(v);
    afis(v);
    quicksort(v, prim, n - 1);
    afis(v);
}
*/


