#include <stdio.h>
#include <stdlib.h>
#define print_tab(t,n) for(int i=0;i<n;i++)printf("%d ",t[i])
void merge(int *t,int l ,int m ,int r){
    int n_left=m-l+1;//nr de elemente din partea stanga
    int n_right= r-m;//ne de elemente din partea dreapta

    int t_left[n_left];//declaram tabel pentru a copia elemetele din partea stanga
    int t_right[n_right];//declaram tabel penteu a copia elementele din partea dreapta

    //copiem
    for(int i=0;i<n_left;i++){
        t_left[i]=t[i+l];
    }
    //copiem
    for(int i=0;i<n_right;i++){
        t_right[i]=t[m+1+i];
    }

    //unim tabelele si le punem in tabelul initial
    int i=0,j=0;
    for(int k=l;k<=r;k++){
        // daca intr-un tabel este mai mic elementul il punem din 1 tabel sau daca al 2 tabel sa terminat la fel punem in 1 tabel 
        // altfel punem in tabelul 2
        if( t_left[i]<t_right[j] || (i<m)&&(j>r) ){
            t[k]=t_left[i];
            i++;
        }
        else {
            t[k]=t_right[j];
            j++;
        }
    }

}

void mergesort(int *t,int l,int r){
    int m=0;
    //daca avem mai mult de 1 celula
if(l<r){ 
    m=l+(r-l)/2;
    //despartim tablelul in 2 apoi iarsi in 2 pana ajungem la 1 celula
    mergesort(t,l,m);//sortam partea stanga
    mergesort(t,m+1,r);//sortam partea dreapta

    merge(t,l,m,r);//unim partile sortate
}
}

int main(){
    //declaram tabelul
    int t[100000];
    int t_length=0;

    //citim tabelul
    scanf("%d",&t_length);
    for(int i=0;i<t_length;i++){
        scanf("%d",&t[i]);
    }

    //afisam tabelul initial
    print_tab(t,t_length);
    printf("\n");

    //sortam tabelul
    mergesort(t,0,t_length-1);
    
    //afisam tabelul sortat
    printf("\n");
    print_tab(t,t_length);





    return 0;
}