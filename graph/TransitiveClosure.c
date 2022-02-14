#include<stdio.h>
# define V 4
void print(int a[][V]);
void tc(int graph[][V])
{
  int a[V][V],i,j,k;
  for(i=0;i<V;i++)
  {
    for(j=0;j<V;j++)
    {
      a[i][j]=graph[i][j];
    }
  }
  for(k=0;k<V;k++)
  {
    for(i=0;i<V;i++)
    {
      for(j=0;j<V;j++)
      {
        a[i][j] = a[i][j] || (a[i][k]&&a[k][j]);
      }
    }
  }
  print(a);
}
void print(int a[][V])
{
  printf("Transitive Closure : \n");
  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
      if(i==j)
        printf("1 ");
      else
        printf("%d ",a[i][j]);
    }
    printf("\n");
  }
}
int main()
{
  int graph[V][V]={{1,1,0,1},
                   {0,1,1,0},
                   {0,0,1,1},
                   {0,0,0,1}
                  }
  tc(graph);
  return 0;
}
  return 0;
}
