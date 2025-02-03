#include <stdio.h>
int a[7];  // tablou de maxim nmax elemente
int pos[2] = { 0,1 };  //tabloul de posibilitati
int n = 6;

void afiseaza_solutia()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int acceptabil(int pos)
{
    if (pos > n - 1)
        return 0;
    int ct0 = 0, ct1 = 0;
    for (int i = 0; i <= pos; i++)
    {
        if (a[i] == 0)
            ct0++;
        if (a[i] == 1)
            ct1++;
    }
    if (ct0 > 2)
        return 0;
    if (ct1 > 4)
        return 0;
    if (pos > 0 && a[0] == 1 && a[1] == 1)
        return 0;
    if (pos == n - 1 && a[pos] == 0)
        return 0;
    return 1;
}

int solutie(int k)
{
    return (k == n-1);  //solutia cuprinde n elemente
}

void permuta(int k)  //k pasul, n -nr de elemente
{

        for (int i = 0; i < 2; i++)  // parcurgem pe rand posibilitatile
        {
            a[k] = pos[i];
            if (acceptabil(k)) //daca posibilitatea  e acceptabila
                if (solutie(k))
                    afiseaza_solutia();
                else
                permuta(k + 1);   // back1(posibilitate_k+1)
            
            //sterge_inregistrarea lipseste din aceasta implementare;
        }
   
}   /*permuta*/

int main(void)
{
   
    permuta(0);
}