#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;++i) 
#define frn(i,a,b) for(int i=a;i>=b;--i) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;

bool diff(int ar[26], int br[26])
{
	fr(i,0,25)
	{
		if(ar[i]!=br[i]) return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string p,h;
	cin>>t;
	while(t--)
	{
		cin>>p;
		cin>>h;
		
		int alpcnt[26], ans[26];
		
		fr(i,0,25) alpcnt[i]=0, ans[i]=0;
		
		n=p.length();
		fr(i,0,n-1)
		{
			alpcnt[(int)(p[i]-'a')]++;
		}
		
		m=h.length();
		if(m<n) cout<<"NO\n";
		else
		{
			fr(j,0,n-1)
			{
				ans[(int)(h[j]-'a')]++;
			}
			
			int k=n;
			while(diff(ans, alpcnt) && (k<m))
			{
				ans[(int)(h[k-n]-'a')]--;
				ans[(int)(h[k]-'a')]++;
				k++;
			}	
			if(!diff(ans, alpcnt)) cout<<"YES\n";
			else cout<<"NO\n";
		}
		
	}
	return 0;
}
