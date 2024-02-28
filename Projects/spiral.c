#include <stdio.h>
int t[100][100]={0},n=0,m=0,i=0,j=0,nr=1;


void dreapta(){
    
    while(j<m){
        if(t[i][j]==0){
            t[i][j]=nr;
            nr++;
            j++;
        }else break;
    }
    j--;
    i++;
}

void jos(){
    while(i<n){
        if(t[i][j]==0){
            t[i][j]=nr;
            nr++;
            i++;
        }else break;
    }
    i--;
    j--;
    
}

void stanga(){
    while(j>=0){
        if(t[i][j]==0){
            t[i][j]=nr;
            nr++;
            j--;
        }else break;
    }
    j++;
    i--;
}
void sus(){
    while(i>=0){
        if(t[i][j]==0){
            t[i][j]=nr;
            nr++;
            i--;
        }else break;
    }
    i++;
    j++;
}

int main(){
    
    scanf("%d %d",&n,&m);
    i=0,j=0;
    while(nr<=n*m){
        dreapta();
        jos();
        stanga();
        sus();
    }

    for(int u=0;u<n;u++){
        for(int z=0;z<m;z++)printf("%4d ",t[u][z]);
    printf("\n");
    }


    
}

