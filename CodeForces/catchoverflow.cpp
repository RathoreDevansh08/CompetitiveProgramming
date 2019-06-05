#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define for(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

ll t,m,n,a,b,f=0;
ll x,high,ans;
string st,st2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	high=pow(2,32)-1;
	
	cin>>m;
	getline(cin,st);
	stack<ll>s;
	s.push(1);
	x=1;ans=0;
	while(m--)
	{
		getline(cin,st);
		if(st=="add") 
		{
			if(s.top()>high || s.top()<=0) {cout<<"OVERFLOW!!!\n";return 0;}
			ans+=s.top();
		}
		else if(st=="end")
		{
			s.pop();
		}
		else
		{
			stringstream ss(st);
			ss>>st2>>n;
			x=s.top();
			s.push(x*n);
		}
		if(ans>high || ans<0) {cout<<"OVERFLOW!!!\n";return 0;}
	}
	cout<<ans<<"\n";
	return 0;
}
