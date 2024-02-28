#include <stdio.h>
#include <math.h>

double rad(double numar, double aprox, double precizie) {
    double radical = 0.5 * (aprox + numar / aprox);
    if (fabs(radical - aprox) < precizie) {
        return radical;
    }
    return rad(numar, radical, precizie);
}

int main() {
    double numar;
    double precizie = 0.00000001;
    scanf("%lf",&numar);
    double rezultat = rad(numar, 1.0, precizie);
    printf("Radicalul de ordinul 2 al numarului %.2f este: %.4f\n", numar, rezultat);
    return 0;
}
