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
char a[10005], b[10005];

void read()
{
	cin>>n;
	
	for(int i = 0;i < n;i++)
		cin>>a[i];
	for(int i = 0;i < n;i++)
		cin>>b[i];
}

bool solve()
{
	int diff_count = 0;
	char a_one, b_one;
	for(int i = 0;i < n;i++)
	{
		if(a[i] != b[i]) 
		{
			if(diff_count == 0)
			{
				a_one = a[i];
				b_one = b[i];
				diff_count ++;
			}
			else if(diff_count == 1)
			{
				if(a_one != a[i]
					|| b_one != b[i])
					return false;
				diff_count ++;
			}
			else
			{
				return false;
			}
		}
	}
	
	if(diff_count == 1)
		return false;
	
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		read();
		if(solve())
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	
	return 0;
}
