Perform DFS starting from a given source vertex using recursion.

Input:
- n
- adjacency list
- starting vertex s

Output:
- DFS traversal order

#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v)
{
    printf("%d ", v);
    visited[v] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for(int i = 0; i < n; i++)
        visited[i] = 0;

    printf("DFS Traversal: ");
    DFS(start);

    return 0;
}
