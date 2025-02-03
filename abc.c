/*
#include <stdio.h>
#define N 10
int a[N];  // tablou de solutii
int pos[4] = { 1,2,3 };  //tabloul de posibilitati
int ct = 0;

void afiseaza_solutia()
{
    int i;
    for (i = 0; i < N; i++)
    {
        switch (a[i])
        {
        case 1:
            printf(" a ");
            break;
        case 2:
            printf(" b ");
            break;
        case 3:
            printf(" c ");
            break;

        }
    }
    printf("\n");
}

int acceptabil(int k)
{
    //elementele din solutie trebuie sa fie unice
    int cta = 0, ctb = 0, ctc = 0;
    for (int i = 0; i <= k; i++)
    {
        if (a[i] == 1)
            cta++;
        if (a[i] == 2)
            ctb++;
        if (a[i] == 3)
            ctc++;

    }
    if (cta > 3 || ctb > 4 || ctc > 3)
        return 0;

    return 1;
}

int solutie(int k)
{
    return (k == N - 1);  //solutia cuprinde n elemente
}

void permuta(int k)  //k pasul, n -nr de elemente
{
    if (ct < 5)
    {
        for (int i = 0; i < 3; i++)  // parcurgem pe rand posibilitatile
        {
            a[k] = pos[i];
            if (acceptabil(k)) {//daca posibilitatea  e acceptabila
                if (solutie(k))
                {
                    afiseaza_solutia();
                    ct++;
                }
                else
                    permuta(k + 1);   // back1(posibilitate_k+1)
            }
            //sterge_inregistrarea lipseste din aceasta implementare;
        }
    }
}   

int main(void)
{

    permuta(0);
}

*/

#include <stdio.h>

int a[6] = { 'a','b','c' };
int v[11];
int n = 10;

int ct = 0;

void afisare(int pos)
{
    for (int i = 0; i < n; i++)
    {
        printf("%c ", v[i]);
    }
    printf("\n");
}

int valid(int pos)
{
    int cta = 0;
    int ctb = 0;
    int ctc = 0;
    for (int i = 0; i <= pos; i++)
    {
        if (v[i] == 'a')
            cta++;
        if (v[i] == 'b')
            ctb++;
        if (v[i] == 'c')
            ctc++;

    }
    if (cta > 3)
        return 0;
    if (ctb > 4)
        return 0;
    if (ctc > 3)
        return 0;

    return 1;
}

int solutie(int pos)
{

    if (pos == n - 1)
        return 1;

    return 0;
}

void back(int k)
{
    if (ct < 6)
        for (int i = 0; i < 3; i++)
        {
            v[k] = a[i];
            if (valid(k))
                if (solutie(k))
                {
                    afisare(k);
                    ct++;
                }
                else
                    back(k + 1);
        }
}



int main()
{
    back(0);
    return 0;
}
