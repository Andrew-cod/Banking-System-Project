#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
#define N_MAX 100001
ifstream fin("permutariab.in");
ofstream fout("permutariab.out");

long long int tree[N_MAX*4+5];
int positions[N_MAX+5]; // positions[i] = position of element B[i] in A
int arrayA[N_MAX+1], arrayB[N_MAX+1];

void update(int node, int l, int r, int pos, long long int &result) {
if (l == r) {
tree[node] = 1;
return;
}
int mid = (l + r) / 2;
if (pos <= mid) {
result = (result + tree[node*2+1]);
update(2*node, l, mid, pos, result);
} else {
update(2*node+1, mid+1, r, pos, result);
}
tree[node] = tree[2*node] + tree[2*node+1];
}

int main() {
    long long int n, result = 0, temp;
    fin >> n;
    for (int i = 1; i <= n; i++) {
        fin >> temp;
        arrayA[temp] = i;
    }
    for (int i = 1; i <= n; i++) {
        fin >> arrayB[i];
    }
    for (int i = 1; i <= n; i++) {
        positions[i] = arrayA[arrayB[i]];
    }
    for (int i = 1; i <= n; i++) {
        update(1, 1, n, positions[i], result);
    }
    fout << result;
    return 0;
}
