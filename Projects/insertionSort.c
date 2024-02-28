#include <stdio.h>
/*
Sortarea prin insertie presupune luarea fiecarui elemen in parte si inserarea lui la locul
 potrivit in partea stanga astfel incat partea satnga sa fie sortata si asa pana ajungi la ultimul element 
 Inserarea se face prin copierea elementului pe care dorim sa il inseram intr-un aux si apoi copiem de fiecare data 
 cand de adancim elementele vecine t[j] si t[j+1], Apoi cand gasim locul atribuim fara sa ne temem deoarece valoarea la celula unde atribuim este in cea vecina

*/
void insertionSort(int *t,int n){
    int aux,j;
    //pornim de la 1 din cauza ca un element este intotdeauna sortat
    for(int i=1;i<n;i++){
        //facem o copie
        aux=t[i];
        //pornim de la pozitia curenta
        j=i;
        //Verificam daca nu am ajuns la capatul tabelului sau urmatorul sa fie mai mic deja
        while(j>=0 && t[j-1]>aux){
            j--;
            t[j+1]=t[j];

        }
        //atribuim
        t[j]=aux;
        /*
        printarea pentru demonstatie
        printf("\n\n");
        for(int i=0;i<n;i++){
        printf("%d ",t[i]);
        */
    }
    
}


int main(){

    int n,t[100];
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }

    insertionSort(t,n);

    for(int i=0;i<n;i++){
        printf("%d ",t[i]);
    }




    return 0;
}