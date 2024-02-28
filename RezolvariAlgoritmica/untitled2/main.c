#include <stdio.h>
#include <stdlib.h>

void afis(char** grid, int gridSize, int gridColSize){
    printf("---------\n");
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            printf("%d ",grid[i][j]);
        }
        printf("%d");
    }
}

void sterg(int i,int j,int **t,int n,int m){
    t[i][j]=0;
    if(t[i+1][j]==0 && i+1<n)sterg(i+1,j,t,n,m);
    if(t[i][j-1]==0 && j>0)sterg(i,j-1,t,n,m);
    if(t[i-1][j]==0 && i>0)sterg(i-1,j,t,n,m);
    if(t[i][j+1]==0 && j+1<n)sterg(j+1,j,t,n,m);
}

int numIslands(char** grid, int gridSize, int gridColSize) {
    int nr = 0;
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            afis(grid,gridSize,gridColSize);
            if (grid[i][j] == 1) {
                nr++;
                sterg(i, j, grid, gridSize, gridColSize);
            }

        }
    }
    return nr;
}


int main() {
    int t[10][10];
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&t[i][j]);
        }
    }
    printf("\n%d",numIslands(t,n,m));
    return 0;
}
