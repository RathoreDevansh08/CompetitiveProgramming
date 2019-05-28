#include<iostream>
#include<vector>
#include<list>
#include<cstdio>
using namespace std;

#define inf 100000
int g[2000][2000];

void bfs(int s,vector<int>V[],int n) 
{
    bool *vis = new bool[n]; 
    int dis[n],s1=s,f=0;
    for(int i = 0; i < n; i++){vis[i] = false;dis[i] = inf;} 
    vis[s] = true;dis[s]=0; 
    
    list<int> q; 
    
    q.push_back(s); 
    while(!q.empty()) 
    { 
        s = q.front(); 
        q.pop_front(); 

        for(auto e : V[s]) 
        { 
            if (!vis[e]) 
            { 
                if(s1==s && g[e][s]==1){cout<<2<<"\n";f=1;break;}
                vis[e] = true; 
                dis[e]=min(dis[e],dis[s]+1);
                q.push_back(e); 
            } 
        } 
        if(f==1)break;
    } 
    if(f==0)
    {
        int mi=inf;
        for(int i=0;i<n;i++)
        {
        	if(g[i][s1] && dis[i]!=inf){mi=min(mi,dis[i]);f=1;}
        }
        if(f==1) cout<<mi+1<<"\n";
        else cout<<"NO WAY\n";
    }
} 

int main()
{
	int n;
	scanf("%d",&n);
	vector<int>V[n];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{scanf("%d",&g[i][j]);if(g[i][j])V[i].push_back(j);}
	
	for(int i=0;i<n;i++)
	{
		if(g[i][i]!=1)
		{
			bfs(i,V,n);
		}
		else cout<<1<<"\n";
	}
	return 0;
}
