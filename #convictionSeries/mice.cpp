#include<iostream>
#include<vector>

using namespace std;

#define inf 1000000007

int V,T;
int minDistance(int dist[], bool sptSet[]) 
{ 
   int min = inf, min_index; 
   
   for (int v = 0; v < V; v++) 
     if (sptSet[v] == false && dist[v] <= min) 
         min = dist[v], min_index = v; 
   
   return min_index; 
} 
  
void printSolution(int dist[], int n) 
{ 
   int cnt=0;
   for (int i = 0; i < V; i++)
   { 
   	if(dist[i]<=T)cnt++;
   } 
   cout<<cnt<<"\n";
} 


int main()
{
	int n,ec,t,e,a,b,w;
	cin>>n>>ec>>t>>e;
	V=n;T=t;
	int adj[n][n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			adj[i][j]=-1;
	
	for(int i=0;i<e;i++)
	{
		cin>>a>>b>>w;
		adj[b-1][a-1]=w;
	}
	
	//Dijkstra(adj,ec-1);
	
     int dist[V];     
     bool sptSet[V]; 
     
     for (int i = 0; i < V; i++) 
     {
     	dist[i] = inf;
     	sptSet[i] = false;
     } 
   
     dist[ec-1] = 0; 
   
     for (int c=0;c<V-1;c++) 
     { 
       int u = minDistance(dist, sptSet); 
       sptSet[u] = true; 
   
       for (int v = 0; v < V; v++) 
         if (!sptSet[v] && adj[u][v]!=-1 && dist[u]!=inf && dist[u]+adj[u][v]<dist[v]) 
            dist[v] = dist[u] + adj[u][v]; 
     } 
 
     printSolution(dist, V); 
	return 0;
}
