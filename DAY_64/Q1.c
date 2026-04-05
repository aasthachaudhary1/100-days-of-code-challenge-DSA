#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Node;

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    Node queue[10000];
    int front = 0, rear = 0;
    int fresh = 0;
    int minutes = 0;

    int rows = gridSize;
    int cols = gridColSize[0];

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    // Add rotten oranges to queue
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 2) {
                queue[rear].x = i;
                queue[rear].y = j;
                rear++;
            }
            if(grid[i][j] == 1)
                fresh++;
        }
    }

    while(front < rear && fresh > 0) {
        int size = rear - front;
        minutes++;

        for(int i = 0; i < size; i++) {
            Node temp = queue[front++];
            
            for(int d = 0; d < 4; d++) {
                int nx = temp.x + dx[d];
                int ny = temp.y + dy[d];

                if(nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear].x = nx;
                    queue[rear].y = ny;
                    rear++;
                    fresh--;
                }
            }
        }
    }

    if(fresh == 0)
        return minutes;
    else
        return -1;
}
