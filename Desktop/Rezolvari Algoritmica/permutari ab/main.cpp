#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int pos[100006];
int A[100002], B[100002];
long long int st[400010];

void refresh(int nod, int l, int r, int pos, long long int &rez) {
    if(l==r){
        st[nod]=1;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m){
        rez=(rez+st[nod*2+1]);
        refresh(2*nod,l,m,pos,rez);
    }
    else{
        refresh(2*nod+1,m+1,r,pos,rez);
    }
    st[nod]=st[2*nod]+st[2*nod+1];
}

int main() {
    long long int nr, rez = 0, aux;
    ifstream fi("permutations.in");
    fi>>nr;
    for (int i = 1; i <= nr; i++) {
        fi>>aux;
        A[aux]=i;
    }
    for (int i = 1; i <= nr; i++)
        fi>>B[i];
    for (int i = 1; i <= nr; i++)
        pos[i]=A[B[i]];
    for (int i = 1; i <= nr; i++)
        refresh(1,1,nr,pos[i],rez);
    ofstream fo("permutations.out");
    fo << rez;
    return 0;
}
