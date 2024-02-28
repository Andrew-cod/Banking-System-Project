#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    int n=100,b;
    char *str=NULL, *p=NULL;
    str= (char*)malloc(n);
    scanf("%[^\n]s",str);
    p=strtok(str," .");

    while(p!=NULL){
        printf("%s\n",p);
        p=strtok(NULL," .");
    }

    return 0;
}