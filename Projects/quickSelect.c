#include <stdio.h>
#include <stdlib.h>

//simplu swap
void swap(int *a,int *b){
    int aux;
    aux=*a;
    *a=*b;
    *b=aux;
}


int part(int *t,int l,int r){
    //selectam pivotul ca fiind ultimul element din vector
    int pivot=t[r];
    //facem in asa fel incat din partea stanga sa fie elementele mai mici iar din dreapta mai mari
    int i=l-1;

    for(int k=l;k<r;k++){
        if(t[k]<pivot){
            i++;
            swap(&t[k],&t[i]);
        }
    }
    //pozitionam pivotul la mijloc unde are din stanga elemente mai mici si din dreapta mai mari
    swap(&t[i+1],&t[r]);
    //returnam pozitia pivotului
    return i+1;
}

int quickselect(int *t,int l,int r,int k){
    int p;
    //in caz ca mai avem >=2 elemente in subarray
    if(l<r){

        // partitionam si returnam pozitia pivotului
        p=part(t,l,r);
        //daca pivotul este al k element din array atunci returnam valarea pozitiei
        if(p==k){
            return t[k];
        }else{
        
        //daca ne trebuie un element mai mic
        if(k<p){
                return quickselect(t,l,p-1,k);
        }else{  
                //daca elementul cautat este unul mai mic 
                return quickselect(t,p+1,r,k);
        }

        }
    }
    //in caz ca avem doar un element in returnam
return t[l];
}



int main()
{   
    int n,k;
    scanf("%d %d",&n,&k);
    int t[n];
    for(int i=0;i<n;i++){
        scanf("%d",&t[i]);
    }
    k--;//deoarece k este pozitia care e numarata de la 0 ci nu de la 1
    printf("%d",quickselect(t,0,n-1,k));

    return 0;
}
