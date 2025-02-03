#include <stdio.h>

int a[6];  // tablou de solutii
int pos[10] = { 1,2,3,4,5,6 };  //tabloul de culori
int n = 3;

void afiseaza_solutia()
{
    int i;
    for (i = 0; i < n; i++)
    {
        switch (a[i]) {
        case 1:
            printf(" alb ");
            break;
        case 2:
            printf(" galben ");
            break;
        case 3:
            printf(" rosu ");
            break;
        case 4:
            printf(" verde ");
            break;
        case 5:
            printf(" albastru ");
            break;
        case 6:
            printf(" negru ");
            break;

        }
    }
    printf("\n");
}

int acceptabil(int pos)
{
    //elementele din solutie trebuie sa fie unice
    if (pos > n - 1)
        return 0;
    if (pos == 1)
        if (a[pos] != 4 && a[pos] != 2)
            return 0;
    for (int i = 0; i < pos; i++)
    {
        if (a[i] == a[pos])
            return 0;
    }
    return 1;
}

int solutie(int k)
{
    if (k == n - 1)
        return 1;  //solutia cuprinde n-1 elemente
    return 0;
}

void permuta(int k)  //k pasul
{

    for (int i = 0; i < 6; i++)  // parcurgem pe rand posibilitatile
    {
        a[k] = pos[i];
        if (acceptabil(k)) //daca posibilitatea  e acceptabila
            if (solutie(k))
                afiseaza_solutia();
            else

                permuta(k + 1);   // back1(posibilitate_k+1)


    }
}   /*permuta*/

int main(void)
{

    permuta(0);
    return 0;
}