#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stoi(char *str)
{
	int x;
	sscanf(str, "%d", &x);
	return x;
}

typedef struct QNode 
{ 
    int key; 
    struct QNode *next; 
}QNode; 
typedef struct Queue 
{ 
    struct QNode *front, *rear; 
}Queue; 

int Size=0;
 
QNode* newNode(int k) 
{ 
    QNode *temp = (QNode*)malloc(sizeof(QNode)); 
    temp->key = k; 
    temp->next = NULL; 
    return temp;  
}
  
Queue *createQueue() 
{ 
    Queue *q = (Queue*)malloc(sizeof(Queue)); 
    q->front = q->rear = NULL; 
    return q; 
}


 
void enQueue(Queue *q, int k) 
{ 
    QNode *temp = newNode(k); Size++;
    if (q->rear == NULL) 
    { 
       q->front = q->rear = temp; 
       return; 
    } 

    q->rear->next = temp; 
    q->rear = temp; 
} 
 
QNode *deQueue(Queue *q) 
{ 
    	
    if (q->front == NULL) 
       return NULL; 
    Size--;
    QNode *temp = q->front; 
    q->front = q->front->next; 
   
    if (q->front == NULL) 
       q->rear = NULL; 
    return temp; 
} 

typedef struct node
{
	int val;
	struct node * next;
}node;

typedef struct Graph
{
	node **li;
	int *vis, *dis;
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
	G->dis = (int *) malloc(n*sizeof(int));	
	G->n = n;
	int i;
	for(i=0;i<n;i++)
	{
		node *te = createNode(i);
		G->li[i] = te;
		G->vis[i] = 0;
		G->dis[i] = -1;		
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
/*
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
}*/

void bfs (graph *G,int x)
{
 G->dis[x]=0;
 Queue *q=createQueue(); 
 enQueue(q,x);
 while(Size!=0)
 {
 //printf("i");
  QNode *u=deQueue(q);
  node *t=G->li[u->key];
  while(t->next!=NULL)
  {
   t=t->next;
   if(G->dis[t->val]==-1)
   {
    enQueue(q,t->val);
    G->dis[t->val]=G->dis[u->key]+1;
   }
  }
 }
}

void print(graph *G)
{
	int i,j;
	for(i=0;i<G->n;i++)
	{
	  printf("%d\n",G->dis[i]);
	}
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
	
	bfs(G,0);
	
	print(G);
}

