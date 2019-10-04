#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,as,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	map <pair<int,int>,int> mapr, mapc;
	
	cin>>n>>m;
	int a[n][m];
	
	vector<int>rowcard(n), colcard(m);
	vector<set<int>>rw(n), cl(m);
	
	fr(i,0,n-1)
		fr(j,0,m-1)
			cin>>a[i][j];
	
	fr(i,0,n-1) 
	{		
		fr(j,0,m-1)
		{
			rw[i].insert(a[i][j]);
		}
		rowcard[i]=rw[i].size();
		//cout<<rowcard[i]<<"-";
	}
	
	fr(j,0,m-1) 
	{		
		fr(i,0,n-1)
		{
			cl[j].insert(a[i][j]);
		}
		colcard[j]=cl[j].size();
		//cout<<colcard[j]<<"-";
	}
	
	fr(i,0,n-1)
	{
		int g=1;
		for(auto e:rw[i])
		{
			mapr[{e,i}]=g;
			g++;
		}
	}
	
	fr(j,0,m-1)
	{
		int g=1;
		for(auto e:cl[j])
		{
			mapc[{e,j}]=g;
			g++;
		}
	}
	
	fr(i,0,n-1)
	{
		fr(j,0,m-1)
		{
			as=mapr[{a[i][j],i}];
			b=mapc[{a[i][j],j}];
			if(as==b) cout<<max(rowcard[i],colcard[j])<<" ";
			else if(as>b)
			{
				cout<<max(rowcard[i], colcard[j]+(as-b))<<" ";
			}
			else
			{
				cout<<max(colcard[j], rowcard[i]+(b-as))<<" ";
			}
		}
		cout<<"\n";
	}
	
	
	return 0;
}
