/*kmp*/

#include <stdio.h>
#include <string.h>
int main()
{
    char n[50];
    char pat[50];

    scanf("%s",n);
    scanf("%s",pat);
    int n_len=strlen(n);
    int pat_len=strlen(pat);
    //se incepe indexarea de la 1
    for(int i=n_len;i>=1;i--){
        n[i]=n[i-1];
    }

    n[0]='\0';

    for(int i=pat_len;i>=1;i--){
        pat[i]=pat[i-1];
    }
    pat[0]='\0';

    int l[50]={0};
    int x=0;

    //se verifica de cate ori se repeta paternul in patren gen:
    //12345
    //abcab
    //00012
    //adica caracterul de pe pozitia 4 e la fel ca ch de pe poz 1
    // si ch de pe poz 5 e la fel ca ch de pe poz 2 in caz ca precedentul a fost la fel

    for(int i=2;i<=pat_len;i++){
        if(pat[i]==pat[x+1]){
            l[i]=++x;
        }else
        {
            l[i]=0;
            x=0;
        }
    }
    //cautam paternul in n
    int j=0;
    for(int i=1;i<=n_len;i++){
        //in caz ca avem un caracter egal j++
        if(n[i]==pat[j+1]){
            j++;
        }else{
            //altfel plecam la caracterul egal de la inceput
            j=l[j];
            i--;//mai repetam o data verificarea
        }
        if(j+1==pat_len){
            //in caz ca avem pat_len caractere egale am gasit o aparaitie
            //si putem incepe din nou
            printf("Gasit la indexul %d\n",i-pat_len+1);
            j=0;
        }
    }

    //nevermind
    getchar();



    return 0;
}
