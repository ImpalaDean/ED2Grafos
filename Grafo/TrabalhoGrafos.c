#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define INF INT_MAX
#define N 5

int encontrarMenorDistancia(int dist[], bool visitado[]) {
    int min = INF, minIndex;

    for (int i = 0; i < N; i++) {
        if (!visitado[i] && dist[i] <= min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void imprimirCaminho(int caminho[], int j) {
    if (caminho[j] == -1) {
        printf("%c ", 'A' + j);
        return;
    }
    imprimirCaminho(caminho, caminho[j]);
    printf("-> %c ", 'A' + j);
}

void dijkstra(int grafo[N][N], int inicio) {
    int dist[N];       
    bool visitado[N];
    int caminho[N];  

    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = false;
        caminho[i] = -1;
    }
    dist[inicio] = 0;

    for (int count = 0; count < N - 1; count++) {
        int u = encontrarMenorDistancia(dist, visitado);
        visitado[u] = true;

        for (int v = 0; v < N; v++) {
            if (!visitado[v] && grafo[u][v] && dist[u] != INF &&
                dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
                caminho[v] = u;
            }
        }
    }

    printf("Menor tempo para chegar de A até E: %d\n", dist[10]);
    printf("Caminho completo de A até E: ");
    imprimirCaminho(caminho, 4);
    printf("\n");

    printf("Menor tempo para chegar de A até D: %d\n", dist[10]);
    printf("Caminho completo de A até D: ");
    imprimirCaminho(caminho,3);
    printf("\n");
}

int main() {
    int grafo[N][N] = {
        {0, 4, 2, 7, 0},
        {4, 0, 1, 0, 1},
        {2, 1, 0, 3, 3},
        {7, 0, 3, 0, 2},
        {0, 1, 3, 2, 0}
    };

    dijkstra(grafo, 0); 

    return 0;
}
