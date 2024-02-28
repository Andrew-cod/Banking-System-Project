//deep firs search

#include <stdio.h>

void dfs(int t[][100],int visited[],int start,int n){
    visited[start]=1;//am vizitat nodul pe care suntem
    printf("NODUL   %d\n",start);//eventul il printam
    for(int i=1;i<=n;i++){//precautam printre toate nodurile posibile
        if(t[start][i]!=0){//in caz ca are o latura catre el
            if(visited[i]==0){//si in plus inca nodul nu a fost vizitat
                dfs(t,visited,i,n);//plecam recusiv spre nodul nevizitat
            }
        }
    }
}

int main() {
    int t[100][100]={0};//declaram un tabel
    int n,k,x;
    //printf("How many nodes?\n");
    //citim graful
    scanf("%d",&n);
    //declaram un tabel de frecventa
    int visited[100]={0};

    for(int i=1;i<=n;i++){
        //printf("How many nodes have %d?\n",i);
        scanf("%d",&k);
        //printf("Print all nodes that conects with %d\n",i);
            for(int j=1;j<=k;j++){
                scanf("%d",&x);
                t[i][x]=1;
            }
    }
//    for(int i=1;i<=n;i++){
//
//        for(int j=1;j<=n;j++){
//    printf("%d ",t[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n");
//    printf("\n");

    //putem se afisam parcurgerea din oricare nod dorim pana la inserarea lui 0
    x=1;
    while(x!=0) {
        scanf("%d",&x);
        dfs(t, visited, x, n);

        //de fiecare data initializam vectorul de frecventa cu 0 asfel sa putem traversa din nou
        for(int i=0;i<=n;i++){
            visited[i]=0;
        }
    }
    printf("\n\n");
    //printam ce nod cu cine are conexiune
    for(int i=1;i<=n;i++){
        printf("%d -> ",i);
        for(int j=1;j<=n;j++){
            if(t[i][j]==1 && i!=j)printf("%d ",j);
        }
        printf("\n");
    }

    return 0;
}
