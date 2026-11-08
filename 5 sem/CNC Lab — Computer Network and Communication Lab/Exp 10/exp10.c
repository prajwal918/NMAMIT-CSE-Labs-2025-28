#include <stdio.h>
#include <stdlib.h>

struct node
{
    int dist[20];
    int from[20];
} rt[10];

int main()
{
    int dmat[20][20];
    int n, i, j, k, c = 1;

    printf("Enter the number of nodes: \n");
    scanf("%d", &n);

    printf("Enter the cost matrix: ");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &dmat[i][j]);
            dmat[i][i] = 0;
            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }

    do
    {
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                for(k = 1; k <= n; k++)
                    if(rt[i].dist[j] > dmat[i][k] + rt[k].dist[j])
                    {
                        rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                    }
        c++;
    }
    while(c < n);

    for(i = 1; i <= n; i++)
    {
        printf("\nDistance Table for router %c is in \n", i + 64);
        for(j = 1; j <= n; j++)
            printf("\tNode %d Via %d. Distance: %d.\n", j, rt[i].from[j], rt[i].dist[j]);
    }
    return 0;
}
