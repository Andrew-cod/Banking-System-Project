#include <stdio.h>
//schimba 2 variabile cu locul folosind adresele lor swap(&a,&b);
void swap(int *a,int *b){
    int  aux;
    aux=*b;
    *b=*a;
    *a=aux;
}

//ia un pivot si imparte in 2 parti tabelul 
// din partea stanga sunt elementele ce sunt mai mici ca pivot 
// din partea dreapta sunt elementele ce sunt mai mari sau egale ca pivot
int partition(int *t,int l,int r){
    int pivot = t[r];
    //in acest exemplu se ia tot timpul ca pivot untimpul element din tabel

    //i de la inceput este l-1 deoarece nu putem asuma ca pe pozitia l este un element mai mic ca pivot 
        // in stanga lui i si pe pozitia lui sunt numaidecat doar elementele mai mici ca pivot
    int i=l-1;
    int j=l;
        // j este variabila care cauta elemente mai mici ca pivot
    for(j=l;j<r;j++){
        //in caz ca am gasit un element care este mai mic ca pivot 
        if(t[j]<pivot){
            i++;
            swap(&t[i],&t[j]);
                //in caz ca am gasit incrementam pe i si apoi facem swap dintre t[i] si t[j]
                    //adica intre elementul t[i] si t[j] 
                        //unde t[j] este elementul care dorim sa fie pe pozitia i pentru ca este t[j]<pivot; 
        }
    }
    // facem swap() pentru ca sa punem elementul pivot intre elementele din stanga care sunt mai mici si elemntele din dreapta care sunt mai mari
    swap(&t[i+1],&t[r]);
    //returnam pozitia pivotului
    return i+1;

}

void qs(int *t,int l,int r){
    //daca l<r adica mai avem subtaboluri de sortat
    //sau mai bine spus daca este valid tabloul
    if(l<r){
        //gasim elemntul pivot
        //si punem elentele mai mici in stanga lui iar cele mai mari in dreapta lui
        int p=partition(t,l,r);
        //deoarece elementului pivor sigur iam gasit pozitia vesnica adica nu se va mai schimba 
        //sortam doar elementele din stanga lui si din dreapta lui 
        qs(t,l,p-1);//sortam subtabloul din stanga 
        qs(t,p+1,r);//sortam subtabolul din dreapta
    }
}

int main(){
    //citim n 
int n;
scanf("%d",&n);
int t[n];
//citim n elemente
for(int i=0;i<n;i++){
    scanf("%d",&t[i]);
}

//apelam functia qs pentru tabelul l si pozitiile 0 si n-1
//este n-1 deorarece n este numarul elementelor la care numaratorea incepe de la 1 iarasi numaratoarea pozitiilor incep de la 0
//si este 0 pentru ca dorim sa sortam de la incputul tabelului
qs(t,0,n-1);

//printaz
for(int i=0;i<n;i++){
    printf("%d ",t[i]);
}


}