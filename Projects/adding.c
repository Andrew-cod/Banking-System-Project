#include <stdio.h>

int add(int x, int y)
{
    int carry; // declaram un carry
    while (y != 0)
    {
        carry = (x & y) << 1; // vedem toti carry si shiftam la stanga dupa cum sar face adunarea astfel formam un numar noucare trebuie adaugat;
        x = x ^ y;            // facem adaunarea fara carry
        y = carry;            // atribui iarasi carry fiind un numar nou de adauga astfel in ciclu
    }
    return x;
}

int add_rec(int x, int y)
{
    if (y == 0)
        return x;//in caz ca avem pe y zero returnam insusi x => x+0=x
    else
    {
        return add(x^y,(x&y)<<1);
        //returnam ^ dintro numere astfel adunam fiecare numar fara a lua in consideratie carry
        //si & dintre numere fiind carry la fiecare adunare dintre cifre binare 
            //care este shiftata la stanga cu o pozitie adica trece pe rangul urmator 
            //se se impinge in recursivitate pana cand ajunge ca nu mai este carry de adunat
    }
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d", add_rec(a, b));

    return 0;
}