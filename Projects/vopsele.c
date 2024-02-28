#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct vopsea{
    char brand[20];
    char color[20];
    float pret;
};

void afis_color(struct vopsea *t,int n){
    char cl[20];
    printf("Color:");
    scanf("%s",cl);
    for(int i=0;i<=n;i++){
        if(strcmp(t[i].color,cl)==0){
            printf("%s\n%s\n%f",t[i].brand,t[i].color,t[i].pret);
        }
    }
    printf("\n");
}

int valid(char *s){
    for(int i=0;i<strlen(s);i++){
        if(s[i]!=tolower(s[i]))return 0;
    }
    return 1;
}

void afis_brand(struct vopsea *t,int n){
    char br[20];
    printf("Brand:");
    scanf("%s",br);
    for(int i=0;i<=n;i++){
        if(strcmp(t[i].brand,br)==0){
            printf("%s\n%s\n%f",t[i].brand,t[i].color,t[i].pret);
        }
    }
    printf("\n");
}



void adauga(struct vopsea *t,int  *n){
    (*n)++;
    char b[20];
    char c[20];
    do{
        printf("Brand:");
        scanf("%s",b);
    }while(!valid(b));
    printf("Color:");scanf("%s",c);
    strcpy(t[*n].brand,b);
    strcpy(t[*n].color,c);
    scanf("%f",&t[*n].pret);
}

int main(){
    struct vopsea t[1000];
    int opt,n;
    n=-1;

    while(1){
        printf("Afisare meniu:\n");
        scanf("%d",&opt);

        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            adauga(t,&n);
            break;
        case 2:
            afis_brand(t,n);
            break;
        case 4:
            afis_color(t,n);
            break;
        case 3:
            
            break;
        default:

            break;
        }



    }








    return 0;
}