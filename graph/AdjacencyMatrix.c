#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int adj[MAX][MAX];
int n;
int main()
{
    int i, j, origin, destin, max_edges;
    int graphtype;
    printf("Enter graph type : \n");
    printf("1. DIRECTED       2. UNDIRECTED\n");
    scanf("%d",&graphtype);
    printf("\nEnter no. of vertices : ");
    scanf("%d",&n);
    if(graphtype==1)
    {
        max_edges=n*(n-1)/2;
    }
    else{
        max_edges=n*(n-1);
    }
    for(i=1;i<=max_edges;i++)
    {
        printf("\nEnter edge %d : ",i);
        scanf("%d %d",&origin,&destin);
        if((origin==-1) && (destin == -1))
              break;
        if((origin>=n)||(destin>=n)||(origin<0)||(destin<0))
              {
                  printf("\nInvelid Vertex!\n");
                  i--;
              }
        else{
            adj[origin][destin]=1;
            if(graphtype==2)
                   adj[destin][origin]=1;
        }
    }
    printf("\nAdjacency matrix for the entered graph is : \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",adj[i][j]);
        }
        printf("\n");
    }
}
