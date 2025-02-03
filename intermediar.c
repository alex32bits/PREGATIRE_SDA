#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5

typedef struct {
	char nume[25];
	int pct;
	int buget;
	char oras[25];
}echipa;

void swap(echipa* el1, echipa* el2)
{
	echipa tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

void muta(echipa* v)
{
	int b = 0;
	int e = N - 1;
	for (int i = 0; i < e;)
	{
		if (v[i].pct > 45)
		{
			swap(&v[i], &v[b]);
			b++;
			i++;
		}
		else
			if (v[i].pct < 20)
		{
			swap(&v[i], &v[e]);
			e--;
		}
		else
		{
			i++;
		}

	}
}

void quicksort(echipa a[],int indexi[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[indexi[prim]], &a[indexi[(prim + ultim) / 2]]);
	//mutare pivot pe prima pozitie
	echipa pivot = a[indexi[prim]];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && a[indexi[stanga]].pct > pivot.pct)
			stanga++;
		while (dreapta >= prim && pivot.pct > a[indexi[dreapta]].pct)
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

void sort(echipa* v)
{
	int ct = 0;
	int indexi[10];
	for (int i = 0; i < N; i++)
	{
		if (v[i].buget > 100000)
		{
			indexi[ct] = i;
			ct++;
		}
	}

	quicksort(v, indexi, 0, ct - 1);
}

void afisare(echipa* v)
{
	for (int i = 0; i < N; i++)
	{
		printf("%6s,%4d,%7d,%4s\n", v[i].nume, v[i].pct, v[i].buget, v[i].oras);
	}
	printf("\n");
}

int main()
{
	echipa v[N] = { {"barca",47,123000,"bar"},{"real",30,560000,"mad"},{"mun",14,163000,"lon"},{"mci",10,50000,"lona"},{"fcb",65,503000,"mun"}};
	afisare(v);
	muta(v);
	afisare(v);
	sort(v);
	afisare(v);

	return 0;

}