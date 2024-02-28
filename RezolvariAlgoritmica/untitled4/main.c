#include <stdio.h>
#include <string.h>
#define MAX 100
int main() {
    int flag;
    int n,k;
    int i=0,j=0;
    char t[MAX][MAX];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf(" %c",&t[i][j]);
        }
    }

    char s[101];
    scanf("%s",s);
    int l= strlen(s);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            //dreapta

            if(l+j<=n){
                flag=1;
                for(k=0;k<l;k++){
                    if(t[i][j+k]!=s[k])flag=0;
                }
                if(flag==1){
                    printf("lin:%d col:%d spre dreapta\n",i,j);
                }
            }
            //stanga
            if(l-j>=0){
                flag=1;
                for(k=0;k<l;k++){
                    if(t[i][j-k]!=s[k]){
                        flag=0;
                    }
                }
                if(flag==1){
                    printf("lin:%d col:%d spre stanga\n",i,j);
                }
            }
            //jos
            if(l-i<=n){
                flag=1;
                for(k=0;k<l;k++){
                    if(t[i+k][j]!=s[k])flag=0;
                }
                if(flag==1){
                    printf("lin:%d col:%d spre jos\n",i,j);
                }
            }

            //sus
            if(l-i>=0){
                flag=1;
                for(k=0;k<l;k++){
                    if(t[i-k][j]!=s[k]){
                        flag=0;
                    }
                }
                if(flag==1){
                    printf("lin:%d col:%d spre sus\n",i,j);
                }
            }
        }
    }

    return 0;
}
