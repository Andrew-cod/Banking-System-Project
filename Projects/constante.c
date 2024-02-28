#include <stdio.h>
 int uit=54;
int main(){
    
    int i;//variabila simpla
    const int a;//variabile de tip constanta
    int *o=&i;//pointer la o variabila de tip integer
    const int *p;//Adresa care este păstrată în pointer poate fi schimbată, însă valoarea de la adresa respectivă nu poate fi modificată






    int *const cpi=&i;//putem schimba valoarea variabilei a cărei adresă o păstrează pointerul, însă acesta nu va putea indica decât spre acea zonă de memorie pe tot parcursul programului.

    //albele
    const int *const cpu=&a;//pointer constant la o constanta de tip integer








    return 0;
}