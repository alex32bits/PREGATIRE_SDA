#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct {
	char nume[25];
	char telefon[10];
	int varsta;
	int venit;
}agenda;

void swap(agenda* el1, agenda* el2)
{
	agenda tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

void muta(agenda* v)
{
	int n = N - 1;
	int ct = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[i].venit < 1000 && ct<3)
		{
			swap(&v[i], &v[n]);
			n--;
			ct++;
		}

	}
}

void quicksort(agenda a[],int indexi[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[indexi[prim]], &a[indexi[(prim + ultim) / 2]]);
	//mutare pivot pe prima pozitie
	agenda pivot = a[indexi[prim]];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && strcmp(a[indexi[stanga]].nume, pivot.nume)<0)
			stanga++;
		while (dreapta >= prim && strcmp(pivot.nume,a[indexi[dreapta]].nume)<0)
			dreapta--;
		if (stanga < dreapta)
			swap(&a[indexi[stanga++]], &a[indexi[dreapta--]]);
		else
			stanga++;
	}
	//mutare pivot la locul sau final
	swap(&a[indexi[dreapta]], &a[indexi[prim]]);
	//apelurile recursive
	if (prim < dreapta - 1)
		quicksort(a,indexi, prim, dreapta - 1);
	if (dreapta + 1 < ultim)
		quicksort(a,indexi, dreapta + 1, ultim);
}
void afisare(agenda* v)
{
	for (int i = 0; i < N; i++)
	{
		printf("%s  %3d\n", v[i].nume, v[i].varsta);
	}
}
void sortare(agenda* v)
{
	int indexi[N];
	int ct = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i].varsta > 29 && v[i].varsta < 41)
		{
			indexi[ct] = i;
			ct++;
		}
	}
	quicksort(v, indexi, 0, ct-1);
}

int main()
{
	agenda l[N] = { {"alex","074524",24,2000},
		{"mari","076456",35,3645},
		{"costi","43435",37,3465},
		{"paul","653635",44,5432},
		{"dani","045423",32,7634}
	};
	afisare(l);
	sortare(l);
	printf("\n");
	afisare(l);
	return 0;
}