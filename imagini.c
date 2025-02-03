#include <stdio.h>
#define l 4
#define c 3
int a[l * c];  // tablou de maxim nmax elemente
int pos[4] = { 1,2,3,4 };  //tabloul de posibilitati

void afisare(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
        if ((i + 1) % 3 == 0 && i != 0)
            printf("\n");
    }
    printf("\n\n");
}

int acceptabil(int k)
{
    if (a[k] == a[k - l - 1] || a[k] == a[k - l + 1] || a[k] == a[k + l - 1] || a[k] == a[k + l + 1])
        return 0;
    return 1;
}

int solutie(int k)
{
    return (k == l * c);  //solutia cuprinde n elemente
}

void permuta(int k)  //k pasul, n -nr de elemente
{

    for (int i = 0; i < 4; i++)  // parcurgem pe rand posibilitatile
    {
        a[k] = pos[i];
        if (acceptabil(k))
            if (solutie(k))
                afisare(k);
            else
                permuta(k + 1);

    }

}

int main(void)
{

    permuta(0);
}