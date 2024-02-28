#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* decode(char s[],int l,int r){
    static char nou[250];
    static int index=0;
    int rCop=r;
    int nr=0;
    int i;
    for(l;l<=r;l++){
        if(isdigit(s[l])){
            nr=nr*10+s[l]-'0';
        }else
        {
            if(s[l]=='['){
            while(s[rCop]!=']')rCop--;
            for(int j=0;j<nr;j++)
                decode(s,l+1,rCop-1);
            l=rCop+1;
            nr=0;
            }
            if(s[l]!=']'){
                nou[index]=s[l];
                index++;
            }
        }
    }
    return nou;
}


int main() {
    char s[250];
    scanf("%s",s);
    printf("%s",decode(s,0,strlen(s)-1));
    //printf("\n%s\n",nou);
    return 0;
}
