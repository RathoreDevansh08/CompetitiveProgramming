#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stoi(char *str)
{
	int x;
	sscanf(str, "%d", &x);
	return x;
}

typedef struct node
{
	int val;
	struct node * next;
}node;

typedef struct Graph
{
	node **li;
	int *vis;
	int n;
	int *par;
}graph;

node * createNode(int key)
{
	node *no = (node*) malloc(sizeof(node));
	no->val = key;
	no->next = NULL;
	return no;
}

graph * createGraph(int n)
{
	graph *G = (graph *) malloc(sizeof(graph));
	G->li = (node**) malloc(n*sizeof(node*));
	G->vis = (int *) malloc(n*sizeof(int));
	G->par = (int *) malloc(n*sizeof(int));
	G->n = n;
	int i;
	for(i=0;i<n;i++)
	{
		node *te = createNode(i);
		G->li[i] = te;
		G->vis[i] = 0;
		G->par[i] = 10000;
	}
	return G;
}

void add(graph *G, int u, int v)
{
	node *no = createNode(v);
	no->next = NULL;
	node *temp = G->li[u];
	while(temp->next!=NULL && temp->next->val<v)
	{
		temp = temp->next;
	}
	if(temp->next!=NULL){
	no->next = temp->next;
	}
	else no->next = NULL;
	temp->next = no;
}

void explore(graph *G, int v)
{
	
	node *temp = G->li[v];
	G->vis[v] = 1;
	//printf("%d\n", G->vis[temp->val]);
	while(temp->next!=NULL)
	{
		temp = temp->next;
		
		if(G->vis[temp->val]==0)
		{
			//printf("kdj\n");
			G->par[temp->val] = v;
			explore(G,temp->val);
		}
	}
}

void dfs(graph *G)
{
	int i;
	for(i=0;i<G->n;i++)
	{
		//printf("%d\n", G->vis[i]);
		if(G->vis[i]==0) explore(G,i);
	}
}

void print(graph *G)
{
	int i,j;
	for(i=0;i<G->n;i++)
	{
		for(j=0;j<G->n;j++)
		{
			if(G->par[j]==i)
			{
				printf("(%d,%d)\n", G->par[j],j);
			}
		}
	}
	printf("\n");
}

int main()
{
	char line[128];
	char v1[15];
	char v2[15];
	char v3[15];
	int lineNo = 0;
	int n;
	graph *G;
	
	while(fgets(line, sizeof line, stdin) != NULL)
	{
		sscanf(line, "%s %s", v1, v2);
		lineNo++;
		if(lineNo==1)
		{
			n = stoi(v1);
			G = createGraph(n);
		}
		else
		{
			int u,v;
			u = stoi(v1);
			v = stoi(v2);
			add(G,u,v);
		}
	}
	int i;
	
	dfs(G);
	
	
	print(G);
}

