#include <stdio.h>
#include "extern variable.c"
int g=10;

int func(int x){
 return x;
}
//acesta functie are o variabila statica care se comporta ca o variabila globala insa nu este vizibila inafara functiei
int next(){
static int i=0;
printf("%d\n",i);
i++;
}

int main(){
    for(int j=0;j<=50;j++)next();



    return 0;
}