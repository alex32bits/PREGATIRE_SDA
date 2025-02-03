#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//definim structura produs
typedef struct produs {
	int cod;
	struct produs* urm;
}produs;
//definim structura magazin
typedef struct magazin {
	char nume[20];
	struct magazin* lp;
	struct produs* ls;
}magazin;

//functie pentru a crea un nod nou
//Complexitate O(1)
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
//functie pentru a adauga sortat in lista de produse
//Complexitate O(n) n-nr de produse
produs* adauga_produs(produs* lista, int cod)
{
	produs* p = new_produs(cod);
	if (lista == NULL)
		return p;
	if (lista->cod > p->cod)
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
//functie pentru un nod nou de tip magazin
//Complexitate O(1)
magazin* new_magazin(char nume[20])
{
	magazin* p = (magazin*)malloc(1 * sizeof(magazin));
	if (p == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	strcpy(p->nume, nume);
	p->lp = NULL;
	p->ls = NULL;
	return p;
}

//functie pentru a adauga un magazin la final
//Complexitate O(m) m-nr magazinului
magazin* adauga_magazin(magazin* lista, char nume[20])
{
	magazin* p = new_magazin(nume);
	if (lista == NULL)
		return p;
	magazin* q;
	for (q = lista; q->lp != NULL; q = q->lp);
	q->lp = p;
	return lista;

}

//functie pentru a adauga in lista principala la magazinul cu numele
//dat ca parametru un produs 
//Complexitate O(m+n)
magazin* adauga(magazin* lista, char nume[20], int cod)
{
	for (magazin* p = lista; p != NULL; p = p->lp)
	{
		if (strcmp(p->nume, nume) == 0)
		{
			p->ls = adauga_produs(p->ls, cod);
		}
	}
	return lista;
}

//functie pentru a elimina un produs
//Complexitate O(m*n)
magazin* elimina(magazin* lista, int cod)
{
	for (magazin* p = lista; p != NULL; p = p->lp)
	{
		produs* tmp;
		if (p->ls->cod == cod)
		{
			tmp = p->ls;
			p->ls = p->ls->urm;
			free(tmp);
		}

		produs* a;
		for (a = p->ls; a->urm->urm != NULL; a = a->urm);
		if (a->urm->cod == cod)
		{
			tmp = a->urm;
			a->urm = NULL;
			free(tmp);
		}

		for (a = p->ls; a->urm != NULL; a = a->urm)
		{
			if (a->urm->cod == cod)
			{
				tmp = a->urm;
				a->urm = a->urm->urm;
				free(tmp);
			}
		}
	}
	return lista;
}

//functie pentru afisare multilisata
//Complexitate O(m*n)
void afisare(magazin* lista)
{
	for (magazin* p = lista; p != NULL; p = p->lp)
	{
		printf("%6s :", p->nume);
		for (produs* q = p->ls; q != NULL; q = q->urm)
		{
			printf("%4d ", q->cod);
		}
		printf("\n");
	}
	printf("\n");
}

int main()
{
	magazin* lista = NULL;
	lista = adauga_magazin(lista, "mag1");
	lista = adauga_magazin(lista, "mag2");
	lista = adauga_magazin(lista, "mag3");

	lista = adauga(lista, "mag1", 100);
	lista = adauga(lista, "mag1", 101);
	lista = adauga(lista, "mag1", 103);
	lista = adauga(lista, "mag1", 106);
	lista = adauga(lista, "mag1", 102);

	lista = adauga(lista, "mag2", 102);
	lista = adauga(lista, "mag2", 105);
	lista = adauga(lista, "mag2", 110);
	lista = adauga(lista, "mag2", 122);
	lista = adauga(lista, "mag2", 106);

	lista = adauga(lista, "mag3", 106);
	lista = adauga(lista, "mag3", 112);
	lista = adauga(lista, "mag3", 132);
	lista = adauga(lista, "mag3", 130);
	lista = adauga(lista, "mag3", 116);
	afisare(lista);

	lista = elimina(lista, 106);
	lista = elimina(lista, 112);
	lista = elimina(lista, 100);
	afisare(lista);
	return 0;
}