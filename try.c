#include <stdio.h>
#define N 5

typedef struct coordonate
{
	int linie, coloana;
}coordonate;
coordonate pos[4];
coordonate a[N * N];
int matrice[N][N] = { {1,1,1,1 ,1},
					  {1,0,1,1,1},
					  {1,0,1,0,1},
					  {1,0,1,0,1},
					  {1,1,1,1,1}
					};

int nr = 0;
int ok = 0;
void initializare() //int pos[] variabila globala
{	//initializarea posibilitatilor de deplasare Posibilitățile de deplasare sunt Nord, Est, Sud, Vest
	pos[0].coloana = 0; // Nord
	pos[0].linie = -1;// y scade spre Nord
	pos[1].coloana = 1; // Est – x creste spre Est
	pos[1].linie = 0;
	pos[2].coloana = 0; // Sud
	pos[2].linie = 1; // y creste spre Sud
	pos[3].coloana = -1;// Vest – x scade spre Vest
	pos[3].linie = 0;
}
int solutie(coordonate c)
{
	if (matrice[c.linie-1][c.coloana]!=0 && matrice[c.linie][c.coloana+1] != 0 && matrice[c.linie+1][c.coloana] != 0 && matrice[c.linie][c.coloana - 1] != 0) //daca am ajuns la margine
		return 1;
	else
		return 0;
}
int acceptabil(coordonate c)
{
	if (matrice[c.linie][c.coloana] == 0 && c.linie >= 0 && c.coloana >= 0 && c.linie < N && c.coloana < N) //daca este liber si coordonata se afla in dimensiunile matricei
		return 1;
	else return 0;
}

void afiseaza_solutia(k)
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			printf("%d ", matrice[i][j]);
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < k; i++)
		printf("pas %d-%d\n", a[i].linie, a[i].coloana);
	printf("\n");
}
void labirint(int k)  //k pasul, c coordonata curenta
{
	int i; coordonate aux;
	if (solutie(a[k - 1]))        //solutie completa
	{
		afiseaza_solutia(k);
		ok = 1;
	}
	else
	{
		for (i = 0; i < 4; i++)  // parcurgem pe rand posibilitatile
		{
			aux.coloana = a[k - 1].coloana + pos[i].coloana;
			aux.linie = a[k - 1].linie + pos[i].linie;
			if (acceptabil(aux)) {//daca posibilitatea  e acceptabila
				a[k] = aux;
				matrice[a[k].linie][a[k].coloana] = -1; //marcheaza ca vizitat
				labirint(k + 1);     // back1(posibilitate_k+1)
				//matrice[a[k].linie][a[k].coloana] = 0; //sterge marcajul ca vizitat
			}
		}
	}
}   /*labirint*/


void numar(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		
			if (matrice[i][j] == 0)
			{	
				ok = 0;
				a[0].linie = i;
				a[0].coloana = j;
				matrice[i][j] = -1;
				labirint(1);
				if (ok == 1)
				{
					nr++;
				}


			}
		
	}
}

int main(void)
{
	initializare();
	numar();
	printf("nr de camere: %d \n", nr);
	
	return 0;
}