#include <stdio.h>
#include <stdlib.h>
#define MAXG 10000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int N, int G, int weights[], int profits[]) {
    int *dp=NULL;
    dp=(int*)calloc(G+1,sizeof(int));


    for (int i = 0; i < N; i++) {
        for (int j = G; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + profits[i]);
        }
    }
    int x=dp[G];
    free(dp);
    return x;
}a

int main() {
    int N, G;


    // Input values
    scanf("%d", &N);
    scanf("%d", &G);

    int *weights=NULL;
    weights=(int*)calloc(G,sizeof(int));
    int *profits=NULL;
    profits=(int*)calloc(G,sizeof(int));


    for (int i = 0; i < N; i++) {
        scanf("%d", &weights[i]);
        scanf("%d", &profits[i]);
    }

    // Calculate and display the result
    int maxProfit = knapsack(N, G, weights, profits);
    printf("%d", maxProfit);
    free(weights);
    free(profits);


    return 0;
}
