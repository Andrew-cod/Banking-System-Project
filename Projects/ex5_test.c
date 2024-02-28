////10:49
////11:35
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid(char *s)
{
    int flag = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        if (!(s[i] >= 'a' && s[i] <= 'z'))
            return 0;
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            flag = 1;
    }
    return flag;
}

void print(char **sir, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", sir[i]);
    }
}

void print_cr(char **sir, int n)
{
    int flag = 1;
    char aux[50];
    do
    {
        flag = 1;
        for (int i = 1; i < n; i++)
        {
            if (strlen(sir[i - 1]) > strlen(sir[i]))
            {
                flag = 0;
                strcpy(aux, sir[i - 1]);
                strcpy(sir[i - 1], sir[i]);
                strcpy(sir[i], aux);
            }
        }
    } while (flag == 0);
    print(sir, n);
}

void prima_vocala(char **sir, int n)
{

    char *vocale = NULL;
    vocale = (char *)malloc(n + 1);
    if (vocale == NULL)
    {
        printf("alocarea dinamica de memorie a esuat");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < strlen(sir[i]); j++)
        {
            if (sir[i][j] == 'a' || sir[i][j] == 'e' || sir[i][j] == 'i' || sir[i][j] == 'o' || sir[i][j] == 'u')
            {
                vocale[i] = sir[i][j];
                break;
            }
        }
    }
    vocale[n] = '\0';
    printf("%s", vocale);
}

void rep_bin(char **s, int n)
{
    int len = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i][strlen(s[i])-1] == 'a')
        {
            len = strlen(s[i]);
            printf("%s: ",s[i]);
            for (int j = 31; j >= 0; j--)
            {
                printf("%d", (len & (1 << j))?1:0);
            }
        }
        printf("\n");
    }
}

int main()
{

    int n, opt;
    char **sir;

    printf("n:");
    scanf("%d", &n);

    sir = (char **)malloc(sizeof(char *) * n);
    if (sir == NULL)
    {
        printf("alocarea dinamica de memorie a esuat");
        exit(1);
    }

    sir[0] = (char *)malloc(sizeof(char) * (strlen("cireasa") + 1));

    if (sir[0] == NULL)
    {
        printf("alocarea dinamica de memorie a esuat");
        exit(1);
    }

    strcpy(sir[0], "cireasa");
    char fruct[50];
    for (int i = 1; i < n; i++)
    {
        do
        {
            printf("Fruct %d: ", i + 1);
            scanf("%s", fruct);
        } while (valid(fruct) == 0);
        sir[i] = (char *)malloc(sizeof(char) * (strlen(fruct) + 1));
        if (sir[i] == NULL)
        {
            printf("alocarea dinamica de memorie a esuat");
            exit(1);
        }
        strcpy(sir[i], fruct);
    }

    do
    {
        printf("\n0. Ieșire\n1. Afișarea fructelor în ordine crescătoare după lungime.\n2. Să se copieze într-un vector prima vocală din numele fructelor, apoi să seafișeze vectorul creat.\n3. Să se afișeze reprezentarea binară a lungimii fructelor, pentru toate fructele carese termină în caracterul ‘a’. Se vor utiliza operații pe biți pentru aflarea valorilorbiților\n\nOptiunea:\n");
        scanf("%d", &opt);

        switch (opt)
        {
        case 0:
            exit(0);
            break;
        case 1:
            print_cr(sir, n);
            break;
        case 2:
            prima_vocala(sir, n);
            break;
        case 3:
            rep_bin(sir, n);
            break;
        default:
            printf("!!! Ati introdus o optiune inexistenta");
        }

    } while (1);

    return 0;
}