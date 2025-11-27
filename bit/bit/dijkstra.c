#include <stdio.h>
#define V 4
#define INF 999
void dijkstra(int G[V][V], int x) {
    int c[V][V], d[V], v[V] = {0}, i, j, min, n;
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            c[i][j] = G[i][j] ? G[i][j] : INF;
    for (i = 0; i < V; i++)
        d[i] = c[x][i];
    v[x] = 1;
    d[x] = 0;
    for (int k = 1; k < V - 1; k++) {
        min = INF;
        for (i = 0; i < V; i++)
            if (!v[i] && d[i] < min)
                min = d[i], n = i;
        v[n] = 1;
        for (i = 0; i < V; i++)
            if (!v[i] && d[n] + c[n][i] < d[i])
                d[i] = d[n] + c[n][i];
    }
    printf("Vertex\tDistance from %d\n", x);
    for (i = 0; i < V; i++)
        printf("%d\t%d\n", i, d[i]);
}
int main() {
    int G[V][V] = {
        {0, 5, 0, 10},
        {5, 0, 3, 0},
        {0, 3, 0, 1},
        {10, 0, 1, 0}
    };
    dijkstra(G, 0);
}
