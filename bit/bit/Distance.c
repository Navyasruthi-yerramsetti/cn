#include <stdio.h>

#define INF 999
#define MAX 20

int main() {
    int n, i, j, k;
    int cost[MAX][MAX];
    int dist[MAX][MAX];
    int next[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (999 = INF):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            dist[i][j] = cost[i][j];

            if (i != j && cost[i][j] != INF)
                next[i][j] = j;   // next hop
            else
                next[i][j] = -1;
        }
    }

    // Bellman-Ford update
    int updated;
    do {
        updated = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {

                    if (dist[i][j] > cost[i][k] + dist[k][j]) {
                        dist[i][j] = cost[i][k] + dist[k][j];
                        next[i][j] = k;
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);

    // Print final routing tables
    printf("\n--- Final Routing Tables ---\n");

    for (i = 0; i < n; i++) {
        printf("\nNode %d Routing Table:\n", i);
        printf("Dest\tNext\tCost\n");

        for (j = 0; j < n; j++) {
            if (i == j) continue;

            printf("%d\t", j);

            if (next[i][j] == -1)
                printf("-\t");
            else
                printf("%d\t", next[i][j]);

            if (dist[i][j] == INF)
                printf("INF\n");
            else
                printf("%d\n", dist[i][j]);
        }
    }

    return 0;
}
