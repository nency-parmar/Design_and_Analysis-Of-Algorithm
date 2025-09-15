#include <stdio.h>
#include <limits.h>

#define V 5;

void Prims(int V, int graph[V][V]) {
    int edges;
    int selected[V];
    while(edges < V -1)
    {
        int min = INT_MAX;
        int x = 0, y = 0;
        for(if i = 0;i<V;i++)
        {
            if (selected[i])
            {
                for(j = 0;j<V;j++)
                {
                    if(!selected[j] && graph[i][j])
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
            
        }
        printf("%d - %d \t%d\n",x,y,graph[x][y]);
        selected[y] = 1;
        edges++;
    }

}

int main() {
    int V = 5;
    int graph[5][5] = {
        {0, 4, 6, 6, 5},
        {4, 0, 2, 0, 3},
        {6, 2, 0, 1, 5},
        {5, 3, 5, 7, 0}
    };

    Prims(V, graph);
    return 0;
}