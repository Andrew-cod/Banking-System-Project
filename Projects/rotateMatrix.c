#include <stdio.h>

void rotateMatrix(int **t, int n)
{
    

}

int main()
{
    int t[100][100];
    int n;

    printf("Nr de Coloane|Linii: \n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &t[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }

    rotateMatrix(t, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", t[i][j]);
        printf("\n");
    }

    return 0;
}