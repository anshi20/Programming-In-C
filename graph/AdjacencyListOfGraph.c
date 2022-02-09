#include<stdio.h>
#include<stdlib.h>
struct AdjListNode
{
	int Dest;
	struct AdjListNode* next;
};
struct AdjList
{
	struct AdjListNode* head;
};

struct graph
{
	int V;
	struct AdjList* array;
};

struct AdjListNode* createAdjListNode(int dest)
{
	struct AdjListNode* newnode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
	newnode->Dest=dest;
	newnode->next=NULL;
	return newnode;
}

struct graph* CreateGraph(int v)
{
	struct graph* g = (struct graph*)malloc(sizeof(struct graph));
	g->V=v;
	g->array = (struct AdjList*)malloc(v * sizeof(struct AdjList));
	int i;
	for(i=0;i<v;i++)
	{
		g->array[i].head=NULL;
	}
	return g;
}

void addEdge(struct graph* g, int src, int dest)
{
	struct AdjListNode* check=NULL;
	struct AdjListNode* newnode = createAdjListNode(dest);
	if(g->array[src].head==NULL)
	{
		newnode->next=g->array[src].head;
		g->array[src].head= newnode;
	}
	else
	{
		check = g->array[src].head;
		while(check->next!=NULL)
		{
			check=check->next;
		}
		check->next=newnode;
	}
	newnode = createAdjListNode(src);
	if(g->array[dest].head==NULL)
	{
		newnode->next=g->array[dest].head;
		g->array[dest].head=newnode;
	}
	else
	{
		check = g->array[dest].head;
		while(check->next!=NULL)
		{
			check=check->next;
		}
		check->next=newnode; 
	}
}

void printGraph(struct graph* g)
{
	printf("\nThe graph's adjacency list representation is :\n");
	int i;
	for(i=0;i<g->V;i++)
	{
	    printf("\n Adjacency list of vertex %d\n head ", i);
		struct AdjListNode* ptr = g->array[i].head;
		while(ptr)
		{
			printf("-> %d ",ptr->Dest);
			ptr=ptr->next;
		}
		printf("\n");
	}
}

int main()
{
	int v=5;
	struct graph* g = CreateGraph(v);
	addEdge(g,0,1);
	addEdge(g,0,4);
	addEdge(g,1,2);
	addEdge(g,1,3);
	addEdge(g,1,4);
	addEdge(g,2,3);
	addEdge(g,3,4);
	printGraph(g);
	return 0;
}
