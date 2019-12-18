#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n;
char a[55], b[55];
int alpha_count[26];
vector<pair<int, int> > swap_a;

void read()
{
	cin>>n;
	
	for(int i = 0;i < 26;i++)
		alpha_count[i] = 0;

	
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
		alpha_count[a[i] - 'a'] ++;
	}	
	for(int i = 0;i < n;i++)
	{
		cin>>b[i];
		alpha_count[b[i] - 'a'] ++;
	}	
}

void solve()
{
	for(int i = 0;i < 26;i++)
	{
		if(alpha_count[i] & 1)
		{
			cout<<"No\n";
			return;
		}
	}
	
	swap_a.clear();
	int i, j, k;
	for(i = 0;i < n;i++)
	{
		if(a[i] != b[i])
		{
			for(j = i + 1;j < n;j++)
			{
				if(b[i] == b[j])
				{
					swap(a[i], b[j]);
					swap_a.push_back({i, j});
					break;
				}
				else if(b[i] == a[j])
				{
					swap(a[j], b[j]);
					swap(a[i], b[j]);
					swap_a.push_back({j, j});
					swap_a.push_back({i, j});
					break;
				}
			}
		}
	}
	
	cout<<"Yes\n";
	cout<<swap_a.size()<<"\n";
	for(auto e : swap_a)
	{
		cout<<e.first + 1<<" "<<e.second + 1<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		read();
		solve();
	}
	
	return 0;
}
