#include <stdio.h>

int strStr(char * haystack, char * needle){
int i=0,ok=1,j=0,i_cop=0;
    while(haystack[i]!='\0'){
        if(haystack[i]==needle[0]){
            ok=1;
            i_cop=i;
            j=0;
            while(needle[j]!='\0'){
                if(haystack[j]=='\0')return -1;
                if(needle[j]!=haystack[i_cop])ok=0;
                j++;
                i_cop++;
            }
            if(ok==1)return i;
            
        }
        i++;
    }
    //printf("%d",i);
    return -1;
}


int main(){
    char s1[50],s2[50];
    scanf("%s",s1);
    scanf("%s",s2);
    printf("%d",strStr(s1,s2));



    return 0;
}