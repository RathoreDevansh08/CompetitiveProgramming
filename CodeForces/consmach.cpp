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
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>st;
	n=st.length();
	
	int z=0;
	while(st[z])
	{
		if(st[z]=='m' || st[z]=='w'){cout<<0<<"\n";return 0;}
		z++;
	}
	
	ll fib[n+5];fib[0]=1;fib[1]=1;
	fr(i,2,n+4)
	{
		fib[i]=(fib[i-1]+fib[i-2])%inf;
	}
	
	int j=0;
	ll ans=1, cn=0, cu=0;
	while(j<n && st[j])
	{
		cn=0;cu=0;
		if(st[j]=='n')while(j<n && st[j]=='n'){cn++;j++;}
		else if(st[j]=='u')while(j<n && st[j]=='u'){cu++;j++;}
		else j++;
		ans = (ans * ((fib[cn]*fib[cu])%inf) )%inf;
	}
	
	cout<<ans<<"\n";
	
	return 0;
}
