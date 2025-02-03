#include <stdio.h>
#include <stdlib.h>

#define N 6

typedef struct coordonate
{
    int linie, coloana;
} coordonate;
coordonate pos[4];   // vector cu directiile in care pot merge
coordonate c[N * N]; // vectorul solutie
// bordez matricea cu -1, ca sa nu depasesc limitele matricei
int matrice[N + 2][N + 2] = { {-1, -1, -1, -1, -1, -1, -1, -1},
                             {-1, 1, 1, 1, 1, 1, 1, -1},
                             {-1, 1, 1, 0, 1, 0, 1, -1},
                             {-1, 1, 1, 0, 1, 1, 1, -1},
                             {-1, 1, 1, 1, 0, 0, 1, -1},
                             {-1, 1, 0, 1, 1, 1, 1, -1},
                             {-1, 1, 1, 1, 1, 1, 1, -1},
                             {-1, -1, -1, -1, -1, -1, -1} };

int zonaMaxima = -1, numarIncaperi = 0, ok = 0, numarMaximIncaperi = -1, linieAdaugata, coloanaAdaugata;

int aux[N + 2][N + 2] = { {-1, -1, -1, -1, -1, -1, -1, -1},
                             {-1, 1, 1, 1, 1, 1, 1, -1},
                             {-1, 1, 1, 0, 1, 0, 1, -1},
                             {-1, 1, 1, 0, 1, 1, 1, -1},
                             {-1, 1, 1, 1, 0, 0, 1, -1},
                             {-1, 1, 0, 1, 1, 1, 1, -1},
                             {-1, 1, 1, 1, 1, 1, 1, -1},
                             {-1, -1, -1, -1, -1, -1, -1} };

void initializare() // definesc deplasarea pe matrice
{
    // Nord
    pos[0].coloana = 0;
    pos[0].linie = -1;
    // Est
    pos[1].coloana = 1;
    pos[1].linie = 0;
    // Sud
    pos[2].coloana = 0;
    pos[2].linie = 1;
    // Vest
    pos[3].coloana = -1;
    pos[3].linie = 0;
}

int solutie(int k, coordonate c) // o solutie avem atunci cand nu mai avem in jurul nostru alt 0, pentru a continua secventa de camere
{
    if (matrice[c.linie - 1][c.coloana] != 0 && matrice[c.linie][c.coloana + 1] != 0 && matrice[c.linie + 1][c.coloana] != 0 && matrice[c.linie][c.coloana - 1] != 0)
        return 1;
    else
        return 0;
}

int acceptabil(coordonate c) // acceptam un elemnt daca este 0 si nu am depasit limitele matricei
{
    if (matrice[c.linie][c.coloana] == 0 && c.linie >= 1 && c.coloana >= 1 && c.linie <= N && c.coloana <= N)
        return 1;
    else
        return 0;
}

void actualizeazaLungimea(int k) // actualizam lungimea secventei maxime
{
    if (k > zonaMaxima)
    {
        zonaMaxima = k;
    }
}

void labirint(int k)
{
    int i;
    coordonate aux;
    if (solutie(k, c[k - 1])) // verificam daca e solutie
    {
        ok = 1;
        actualizeazaLungimea(k);
    }
    else
    {
        for (i = 0; i < 4; i++) // verificam toate posibilitatile de parcurgere
        {
            aux.coloana = c[k - 1].coloana + pos[i].coloana;
            aux.linie = c[k - 1].linie + pos[i].linie;
            if (acceptabil(aux)) // verificam daca e un punct valid
            {
                c[k] = aux;
                matrice[c[k].linie][c[k].coloana] = -1; // marchez cu -1 o pozitie unde am trecut o data
                labirint(k + 1);
            }
        }
    }
}

void gasesteLungime(void) // caut secventa cea mai mare, pornind de oriunde in matrice
{
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (matrice[i][j] == 0) // incep cu cautarea daca sunt pe un element cu valoarea 1
            {
                ok = 0;
                c[0].linie = i;
                c[0].coloana = j;
                matrice[c[0].linie][c[0].coloana] = -1; // marchez ca am vizitat pozitia initiala
                labirint(1);
                if (ok == 1)
                {
                    numarIncaperi++;
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            matrice[i][j] = aux[i][j];
        }
    }
}

void gasesteMaximIncaperi(void)
{
    numarMaximIncaperi = zonaMaxima;
    linieAdaugata = 0;
    coloanaAdaugata = 0;
    int i, j;
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            if (matrice[i][j] == 1)
            {
                matrice[i][j] = 0; // distrug zidul
                gasesteLungime();
                if (numarMaximIncaperi < zonaMaxima)
                {
                    numarMaximIncaperi = zonaMaxima;
                    linieAdaugata = i - 1;
                    coloanaAdaugata = j - 1;
                }
                matrice[i][j] = 1; // construiesc zidul
            }
        }
    }
}

int main(void)
{
    initializare();
    gasesteLungime();
    printf("In matricea\n");
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    printf("numarul de incaperi este %d\n", numarIncaperi);
    printf("cea mai lunga secventa de 0 este %d\n", zonaMaxima);
    gasesteMaximIncaperi();
    printf("daca distrugem zidul de pe pozitia %d %d avem cea mai mare incapere\n", linieAdaugata, coloanaAdaugata);
    return 0;
}