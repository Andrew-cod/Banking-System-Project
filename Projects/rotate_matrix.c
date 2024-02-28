 #include <stdio.h>
#include <stdlib.h>

//Faillll nu pot trimite in functie **t 

/*void rotate(int** matrix, int n, int* matrixColSize){
    int aux=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            aux=*(*(matrix+i)+j);
            *(*(matrix+i)+j)=*(*(matrix+j)<n-1-i);
            *(*(matrix+j)<n-1-i)=aux;
        }
    }

}*/
int main(){
    int **t,n=0;
    scanf("%d",&n);

    //alocarea dinamica facand un tabel 1D de pointeri apoi la fiecare pointeri un tabel de elemente
    t=malloc(n*sizeof(*t));
    for(int i=0;i<n;i++){
        t[i]=malloc(n*sizeof(*t[i]));
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)scanf("%d",&*(*(t+i)+j));
    }
    
    int aux=0;
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n;j++){
            printf("%d %d \n",*(*(t+i)+j), *(*(t+j)+n-1-i));
            aux=*(*(t+i)+j);
            *(*(t+i)+j)=*(*(t+j)+n-1-i);
            *(*(t+j)+n-1-i)=aux;
        }
    }


    printf("\n");
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++)printf("%d ",*(*(t+i)+j));
    printf("\n");
    }


}