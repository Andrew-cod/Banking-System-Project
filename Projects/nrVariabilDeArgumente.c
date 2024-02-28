#include <stdio.h>
#include <stdarg.h>
int sum(int primul, ...){
    va_list lista;
    int sum=0;
    va_start(lista,primul);
    for(int i=0;i<primul;i++){
        sum=sum+va_arg(lista,int);
    }
    va_end(lista);
    return sum;
}

int main()  
{   
    printf("%d",sum(5,1,2,3,4,5,6));
    return 0;
}
