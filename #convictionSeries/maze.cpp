#include<iostream>
#include<map>
#include<utility>
using namespace std;

char g[23][23];
int e,f,m,n;
int dfs(int a,int b,map<pair<int,int>,int>vis)
{
	if(vis[{a,b}])return 0;
	vis[{a,b}]=1;
	if(a==e && b==f){return 1;}
	if(a!=0 && g[a-1][b]=='.' && !vis[{a-1,b}]){if (dfs(a-1,b,vis))return 1;}
	if(b!=0 && g[a][b-1]=='.' && !vis[{a,b-1}]){if (dfs(a,b-1,vis))return 1;}
	if(b<n-1 && g[a][b+1]=='.' && !vis[{a,b+1}]){if (dfs(a,b+1,vis))return 1;}
	if(a<m-1 && g[a+1][b]=='.' && !vis[{a+1,b}]){if (dfs(a+1,b,vis))return 1;}
	
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	
	while(t--)
	{
		cin>>m>>n;
		int cnt=0,a,b,v=0;
		
		map<pair<int,int>,int>vis;
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
				vis[{i,j}]=0;
				if(i==0 || j==0 || j==(n-1) || i==(m-1))
				{
					if(g[i][j]=='.' && cnt==0)
					{cnt++;a=i;b=j;}
					else if(g[i][j]=='.' && cnt==1)
					{cnt++;e=i;f=j;}
					else if(g[i][j]=='.')cnt++;
				}
			}
			
		if(cnt!=2)cout<<"invalid\n";
		else
		{
			v=dfs(a,b,vis);
			if(v==0)cout<<"invalid\n";
			else cout<<"valid\n";
		}
	}
	return 0;
}
