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
	
	cin>>n;
	
	int a[n], b[n], c[n], ps=0, mx=-1, mxi=0;
	fr(i,0,n-1)
	{
		cin>>a[i];
		b[i]=-1*a[i]-1;
		if(abs(a[i])>abs(b[i])) c[i]=a[i];
		else c[i]=b[i];
		
		if(c[i]<0) ps=1-ps;
		if(mx<abs(c[i]))
		{
			mx=abs(c[i]);mxi=i;
		}
	}
	
	if(ps==1)
	{
		c[mxi]=-c[mxi]-1;
	}
	
	fr(i,0,n-1)
	{
		cout<<c[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
