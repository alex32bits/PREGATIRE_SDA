#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pasager {
	int cod;
	struct pasager* urm;
}pasager;


typedef struct zbor {
	char nume[20];
	struct zbor* lp;
	struct pasager* ls;
}zbor;

pasager* new_pasager(int cod)
{
	pasager* p = (pasager*)malloc(1 * sizeof(pasager));
	if (p == NULL)
	{
		perror(NULL);
		exit(-1);
	}
	p->cod = cod;
	p->urm = NULL;
	return p;
}

pasager* adauga_pasager(pasager* lista, int cod)
{
	pasager* p = new_pasager(cod);

	if (lista == NULL)
		return p;

	if (p->cod < lista->cod)
	{
		p->urm = lista;
		lista = p;
		return lista;
	}

	pasager* q;
	for (q = lista; q->urm != NULL; q = q->urm)
	{
		if (q->urm->cod > p->cod)
		{
			p->urm = q->urm;
			q->urm = p;
			return lista;
		}

	}
	if (q->cod < p->cod)
		q->urm = p;
	return lista;


}

zbor* new_zbor(char nume[20])
{
	zbor* p = (zbor*)malloc(1 * sizeof(zbor));
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

zbor* adauga_zbor(zbor* lista, char nume[20])
{
	zbor* p = new_zbor(nume);
	if (lista == NULL)
		return p;
	p->lp = lista;
	lista = p;
	return lista;
}

void afisare(zbor* lista)
{
	for (zbor* q = lista; q != NULL; q = q->lp)
	{
		printf("zbor:%s  pasagrii:", q->nume);
		for (pasager* p = q->ls; p != NULL; p = p->urm)
		{
			printf("%5d", p->cod);
		}
		printf("\n");
	}
}

zbor* sterge(zbor* lista, int cod)
{
	for (zbor* p = lista; p != NULL; p = p->lp)
	{
		pasager* tmp;

			if (p->ls->cod == cod)
			{
				tmp = p->ls;
				p->ls = p->ls->urm;
				free(tmp);
			}

			pasager* q;

			for (q = p->ls; q->urm->urm != NULL; q = q->urm);
			if (q->urm->cod == cod)
			{
				tmp = q->urm;
				q->urm = NULL;
				free(tmp);
			}

			for (q = p->ls; q->urm != NULL; q = q->urm)
			{
				if (q->urm->cod == cod)
				{
					tmp = q->urm;
					q->urm = q->urm->urm;
					free(tmp);
				}
			}
			
	}
	return lista;
}

zbor* adauga(zbor* lista, char nume[20], int cod)
{
	for (zbor* p = lista; p != NULL; p = p->lp)
	{
		if (strcmp(p->nume, nume) == 0)
		{
			p->ls = adauga_pasager(p->ls, cod);
		}
	}
	return lista;
}

int main()
{
	zbor* lista = NULL;
	lista = adauga_zbor(lista, "zbor1");
	lista = adauga_zbor(lista, "zbor2");
	lista = adauga_zbor(lista, "zbor3");
	lista = adauga(lista, "zbor1", 100);
	lista = adauga(lista, "zbor1", 106);
	lista = adauga(lista, "zbor1", 102);
	lista = adauga(lista, "zbor2", 105);
	lista = adauga(lista, "zbor2", 104);
	lista = adauga(lista, "zbor2", 108);
	lista = adauga(lista, "zbor3", 120);
	lista = adauga(lista, "zbor3", 125);
	lista = adauga(lista, "zbor3", 102);

	afisare(lista);

	lista = sterge(lista, 108);
	printf("\n");
	afisare(lista);

}