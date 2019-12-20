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
ll t,m,n,a,b,k,dif,r,lf=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		
		if(abs(a-b)==0) cout<<"0\n";
		else 
		{
			dif=abs(a-b);
			
			n=1;
			while(true)
			{
				r = dif + n*(n+1)/2;
				if(r>0 && r%2==0 && (r)<=(n*(n+1))) 
				{
					cout<<n<<"\n";
					break;
				}
				if(r<0)break;
				n++;
			}
		}
	}
	return 0;
}
