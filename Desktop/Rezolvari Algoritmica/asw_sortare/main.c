#include <stdio.h>
#include <string.h>

void swap(char *a,char *b){
    char aux=*a;
    *a=*b;
    *b=aux;
}
int main() {
    char s[1000];
    int n;
    scanf("%d",&n);
    for(int k=0;k<n;k++){
        scanf("%s",s);
        int l=strlen(s);
        int mac=0;
        for(int i=l-2;i>=0;i--){

            int ok=0;
            int min=s[l-1];
            int min_poz=l-1;

            for(int j=i;j<l;j++){
                //cautam cel  mai mic mai mare din cuvant
                if(s[j]>s[i]){
                    ok=1;
                    if(s[j]<min){
                        min=s[j];
                        min_poz=j;
                    }
                }
                if(ok==1)break;
                //daca gasim o litera mai mare lexicografic
            }

            if(ok) {
                mac=1;//variabila care tine cont daca s a facut macar o interschimbare
                //facem interschimbarea
                swap(&s[i], &s[min_poz]);


                for (int o = i+1; o < l; o++) {
                    min = s[o];
                    min_poz = o;
                    for (int j = o + 1; j < l; j++) {
                        if (s[j] < min) {
                            min = s[j];
                            min_poz = j;
                        }
                    }
                    swap(&s[o], &s[min_poz]);
                }
                i = -1;
            }


        }
        if(mac==1)
        printf("%s\n",s);
        else
        printf("-1\n");
    }

    return 0;
}
