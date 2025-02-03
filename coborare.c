#include <stdio.h>
#define N 4

typedef struct coordonate
{
	int linie, coloana;
}coordonate;

coordonate pos[4];
coordonate a[N * N];
int matrice[N][N] = { {4,2,6,8},
					  {2,5,8,9},
					  {1,9,6,2},
					  {6,6,4,7}
};

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
	if (c.coloana == 0 || c.linie == 0 || c.coloana == N - 1 || c.linie == N - 1) //daca am ajuns la margine
		return 1;
	else
		return 0;
}
int acceptabil(coordonate c, coordonate urm)
{
	if (matrice[c.linie][c.coloana] > matrice[urm.linie][urm.coloana] && urm.linie >= 0 && urm.coloana >= 0 && urm.linie < N && urm.coloana < N) //daca este liber si coordonata se afla in dimensiunile matricei
		return 1;
	else return 0;
}

void afiseaza_solutia(int k) {
	printf("Traseu posibil: ");
	for (int i = 0; i < k; i++) {
		printf("(%d, %d) ", a[i].linie, a[i].coloana);
	}
	printf("\n");
}

void labirint(int k)  //k pasul, c coordonata curenta
{

	int i; coordonate aux;
	if (solutie(a[k - 1]))        //solutie completa
		afiseaza_solutia(k);
	else
	{
		for (i = 0; i < 4; i++)  // parcurgem pe rand posibilitatile
		{
			aux.coloana = a[k - 1].coloana + pos[i].coloana;
			aux.linie = a[k - 1].linie + pos[i].linie;
			if (acceptabil(a[k - 1], aux)) {//daca posibilitatea  e acceptabila
				a[k] = aux;
				//int tmp=matrice[a[k].linie][a[k].coloana];
				 //matrice[a[k].linie][a[k].coloana] = 1000; //marcheaza ca vizitat
				labirint(k + 1);     // back1(posibilitate_k+1)
				//matrice[a[k].linie][a[k].coloana] = tmp; //sterge marcajul ca vizita

			}
		}
	}

}   /*labirint*/

int main(void)
{
	initializare();
	a[0].linie = 2;
	a[0].coloana = 1;
	labirint(1);
	return 0;
}