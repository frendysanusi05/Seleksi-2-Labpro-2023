#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int x, y, distance;
} Queue;

int valid(int nx, int ny, int n, int** chess) {
    if (nx > 0 && ny > 0 && nx <= n && ny <= n && chess[nx][ny] == -1)
        return 1;
    return 0;
}

int minMoves(int n, int x, int y, int x_final, int y_final) {
    int** chess = (int**)malloc((n+1) * sizeof(int*));
    for (int i = 1; i <= n; i++) {
        chess[i] = (int*)malloc((n+1) * sizeof(int));
        for (int j = 1; j <= n; j++)
            chess[i][j] = -1;
    }

    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    Queue step = {x, y, 0};
    chess[x][y] = 1;
    
    Queue* queue = (Queue*)malloc((n+1)*(n+1)* sizeof(Queue));
    int front = 0, rear = 0;
    queue[rear++] = step;

    while (front < rear) {
        Queue c = queue[front++];

        if (c.x == x_final && c.y == y_final)
            return c.distance;

        for (int i = 0; i < 8; i++) {
            int nx = c.x + dx[i];
            int ny = c.y + dy[i];

            if (valid(nx, ny, n, chess)) {
                chess[nx][ny] = 1;
                Queue q = {nx, ny, c.distance + 1};
                queue[rear++] = q;
            }
        }
    }

    free(queue);
    for (int i = 1; i <= n; i++)
        free(chess[i]);
    free(chess);

    return -1;
}

int main() {
    int n, x_origin, y_origin, x_final, y_final;
    scanf("%d %d %d %d %d", &n, &x_origin, &y_origin, &x_final, &y_final);
    int level = minMoves(n, x_origin, y_origin, x_final, y_final);
    printf("%d\n", level);
    return 0;
}
