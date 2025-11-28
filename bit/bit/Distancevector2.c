#include <stdio.h>

#define INF 999
#define MAX 20

int main() {
    int n, i, j;
    int cost[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (999 = INF):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\n--- SIMPLE ROUTING TABLES ---\n");

    for (i = 0; i < n; i++) {
        printf("\nRouting Table for Node %d:\n", i);
        printf("Destination\tCost\n");

        for (j = 0; j < n; j++) {
            if (i == j) continue;

            printf("%d\t\t", j);

            if (cost[i][j] == INF)
                printf("INF\n");
            else
                printf("%d\n", cost[i][j]);
        }
    }

    return 0;
}
