
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a,char *b){
    char aux=*a;
    *a=*b;
    *b=aux;
}

typedef struct nod{
    int val;
    int val_poz;
    struct nod *urm;
}nod;

nod* add(nod *lista,int x,int x_poz){
    if(lista == NULL){
        lista = (nod *)malloc(sizeof(nod));
        lista->urm=NULL;
        lista->val=x;
        lista->val_poz=x_poz;
        return lista;
    }else
    {
        nod *aux;
        aux = (nod *)malloc(sizeof(nod));
        aux->urm=NULL;
        aux->val=x;
        aux->val_poz=x_poz;

        nod *q=lista;
        if(q->val>x){
            aux->urm=lista;
            lista=aux;
            return lista;
        }
        int ok=0;
        while(q->urm!=NULL){

            if(q->urm->val>x){
                aux->urm=q->urm;
                q->urm=aux;
                ok=1;
                break;
            }
        }
        if(ok==0)q->urm=aux;
    }
    return lista;
}

nod * delete(nod* lista,nod* node){
    nod* aux;
    if(node==lista){
        aux=lista;
        lista=lista->urm;
        free(aux);
    }
    else{
        aux=lista;

        while(aux->urm!=NULL){
            if(aux->urm==node){
                nod *q=node;
                aux->urm=node->urm;
                free(q);
            }
            aux=aux->urm;
        }
    }
    return lista;

}

int main()
{

    char s[1000];
    scanf("%s",s);
    int l=strlen(s);
    nod *lista;

    int max=(int)s[l-1];
    lista=add(lista,(int)s[l-1],l-1);

    for(int i=l-2;i>=0;i--){
        if((int)s[i]<max){
            //cautam in lista cel mai mic element insa sa fie mai mare decat t[i]
            nod *q=lista;
            while(q!=NULL){

                if(q->val>(int)s[i]){
                    char aux=s[i];
                    s[i]=q->val;
                    lista=delete(lista,q);
                    lista=add(lista,aux,i);
                    for(int j=0;j<=i;j++){
                        printf("%c",s[j]);
                    }
                    while(lista!=NULL)
                    {
                        printf("%c",(char)lista->val);
                        lista=lista->urm;
                    }

                    i=-1;
                }
                q=q->urm;
            }
        }else{
            if((int)s[i]>max)max=(int)s[i];
            lista=add(lista,(int)s[i],i);
        }
    }
    printf("-1");


    return 0;

}
