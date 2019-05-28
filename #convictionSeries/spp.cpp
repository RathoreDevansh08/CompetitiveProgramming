#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<iterator>
using namespace std;
#define inf 10000000007

long int mi;
unsigned char a=0,b;
int n;

void addEdge(vector<int>V[],int a,int b)
{
	V[a].push_back(b);
	V[b].push_back(a);
}
/*
void bfs(int s,vector<int>V[],map<int,int>vis,map<pair<int,int>,long int>mp)
{
	if(s==(n-1))
	{
		mi=min((long int)a,mi);
	}
	vis[s]=1;
	
	for(auto e:V[s])
	{
		
		if(!vis[e])
		{
			b=mp[{s,e}];
			a=a^b;
			dfs(e,V,vis,mp);
		}
	}
}
*/  
void BFS(int s,vector<int>V[],map<int,int>vis,map<pair<int,int>,long int>mp,map<int,int>dis,map<int,int>par) 
{ 
    list<int> que; 
 
    vis[s] = 1; 
    dis[s]=0;
    que.push_back(s); 
  
    while(!que.empty()) 
    { 
        s = que.front(); 
        //cout << s << " "; 
        que.pop_front();  
        for (auto e:V[s]) 
        { 
            if(e==s)
            {
            	
            }
            if(e==n-1 && !vis[e])
            {
            	vis[e]=1;
            	que.push_back(e);
            	par[e]=s;
            	dis[e]=(int)(unsigned char)dis[s]^(unsigned char)mp[{s,e}];
            	cout<<"e:"<<dis[e]<<"\n";
            }
            else if (!vis[e]) 
            { 
                vis[e] = 1; 
                par[e]=s;
                que.push_back(e); 
                dis[e]=dis[s]+mp[{s,e}];
            } 
            else if()
            dis[e]=min((int)((unsigned char)dis[s]^(unsigned char)mp[{s,e}]),dis[e]);
        } 
    } 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m,a,b;
	long int w;
	cin>>n>>m;
	vector<int>V[n];
	map<int,int>vis,dis;
	map<pair<int,int>,long int>mp;

	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		a--;b--;                        //apply bfs not dfs
		if(a!=b)addEdge(V,a,b);
		else V[a].push_back(b);
		vis[a]=vis[b]=0;
		dis[a]=dis[b]=0;
		par[a]=par[b]=-1;
		if(a!=b)mp[{a,b}]=mp[{b,a}]=w;
		else mp[{a,b}]=w;
	}
	mi=inf;
	BFS(0,V,vis,mp,dis.par);
	cout<<dis[0]<<dis[1]<<dis[n-1]<<"\n";
	
	return 0;
}
