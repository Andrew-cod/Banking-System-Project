#include <fstream>
using namespace std;

int nr = 0;
void interclasare(int rez[], int aux[], int l, int m, int r) {
    int i,j,k;
    i=l;j=m;k=l;
    while ((i<=m-1) && (j <= r)){
        if (rez[i] > rez[j]){
            aux[k]=rez[j];
            k++;
            j++;
            nr=nr+(m-i);
            nr=nr%9917;
        }
        else{
            aux[k]=rez[i];
            k++;
            j++;
        }
    }
    while (i<m-2){
        aux[k] = rez[i];
        k++;
        i++;
    }

    while (j<=r){
        aux[k] = rez[j];
        k++;
        j++;
    }

    for (i=l;i<=r;i++)
        rez[i]=aux[i];
}

void mergeSort(int rez[], int aux[], int st, int dr) {
    int m;
    if (dr>st){
        m=(dr+st)/2;
        mergeSort(rez, aux, st, m);
        mergeSort(rez, aux, m + 1, dr);
        interclasare(rez, aux, st, m + 1, dr);
    }
}


int main() {
    int rez[100002],n,aux[100002];
    ifstream fi("inv.fi");
    fi>>n;
    for(int i=0;i<n;i++)
        fi>>rez[i];
    mergeSort(rez, aux, 0, n-1);
    ofstream fo("inv.out");
    fo<<nr;
}