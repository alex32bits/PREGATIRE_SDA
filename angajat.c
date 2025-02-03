#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5
//6:08
typedef struct {
	char nume[25];
	int salar;
	int bonus;
}angajat;

void swap(angajat* el1, angajat* el2)
{
	angajat tmp;
	tmp = *el1;
	*el1 = *el2;
	*el2 = tmp;
}

int muta(angajat* v)
{
	int p = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i].bonus == 1)
		{
			swap(&v[i], &v[p]);
			p++;
		}
	}
	return p;
}

void quicksort(angajat a[], int prim, int ultim)
{
	int stanga = prim + 1;
	int dreapta = ultim;
	//alegere pivot
	swap(&a[prim], &a[(prim + ultim) / 2]);
	//mutare pivot pe prima pozitie
	angajat pivot = a[prim];
	while (stanga <= dreapta) //partitionare
	{
		while (stanga <= ultim && a[stanga].salar > pivot.salar)
			stanga++;
		while (dreapta >= prim && pivot.salar > a[dreapta].salar)
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

void afisare(angajat* v)
{
	for (int i = 0; i < N; i++)
	{
		printf("%6s   %5d  %2d", v[i].nume, v[i].salar, v[i].bonus);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	angajat v[N] = { {"alex",1200,0},{"vali",1700,0},{"andi",1400,1},{"ale",5400,1},{"moni",6200,1} };
	int final = muta(v);
	afisare(v);

	quicksort(v, 0, final - 1);
	afisare(v);
	return 0;
}