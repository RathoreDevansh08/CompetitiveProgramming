#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,c,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a1,a2,a3;char c1,c2,c3;
	cin>>a1>>c1;cin>>a2>>c2;cin>>a3>>c3;
	set<int>s;set<char>d;
	s.insert(a1);s.insert(a2);s.insert(a3);
	d.insert(c1);d.insert(c2);d.insert(c3);
	
	if(d.size()==1 && s.size()==1) cout<<0;
	else if(d.size()==1)
	{
		if(s.size()==2) cout<<1;
		else 
		{
			set<int>::iterator it;
			it=s.begin();
			a=*it;it++;
			b=*it;it++;
			c=*it;
			
			if(c-a==2) cout<<0;
			else if(b-a==1 || c-b==1) cout<<1;
			else if(b-a==2 || c-b==2) cout<<1;
			else cout<<2;
		}
	}
	else if(s.size()==1)
	{
		if(d.size()==2) cout<<1;
		else cout<<2;	
	}
	else if(d.size()==2)
	{
		if(c1==c2)
		{
			if(abs(a2-a1)<=2) cout<<1;
			else cout<<2;
		}
		else if(c2==c3)
		{
			if(abs(a3-a2)<=2) cout<<1;
			else cout<<2;
		}
		else if(c3==c1)
		{
			if(abs(a3-a1)<=2) cout<<1;
			else cout<<2;
		}
		else cout<<2;
	}
	else cout<<2;
	return 0;
}
