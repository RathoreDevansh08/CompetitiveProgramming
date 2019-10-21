#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		map<int, set<pair<int, int>> > mpc;	
			
		fr(i,0,n-1)	
		{
			cin>>a>>b>>m;
			mpc[m].insert(mp(a,b));
		}
		
		for(auto e: mpc)
		{
			if(e.second.size()>1)
			{
				f=0;
				
				map<int, int> coord;
				for(auto h: e.second)
				{
					coord[h.first]++;
					coord[h.second+1]--;
				}
				
				int last=0;
				for(auto h: coord)
				{
					coord[h.first]+=last;
					last=coord[h.first];
					
					if(coord[h.first]>=3)
					{
						f=1;break;
					}
				}
				
				if(f) break;
			}
		}
		
		if(f) cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}
