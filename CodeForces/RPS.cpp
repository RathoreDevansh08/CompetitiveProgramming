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
int t,m,n,a,b,f=0,c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>a>>b>>c;
		cin>>st;
		
		int j=0, R=0, P=0, S=0, ans=0, er=0, ep=0, es=0;
		while(st[j])
		{
			if(st[j]=='R') R++;
			else if(st[j]=='P') P++;
			else S++; 
			j++;
		}
		
		ans = min(a,S)+min(b,R)+min(c,P);
		
		//cout<<S<<" "<<R<<" "<<P<<"===";
		//cout<<ans<<"====\n";
		if(n%2==0 && ans<n/2) cout<<"NO\n";
		else if(n%2!=0 && ans<(int(n/2)+1)) cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			
			if(a>S)er=a-S;
			if(b>R)ep=b-R;
			if(c>P)es=c-P;
			
			j=0;
			while(st[j])
			{
				if(st[j]=='R' && b!=0)
				{
					cout<<"P";b--;
				} 
				else if(st[j]=='R' && er) {cout<<"R";a--;er--;}
				else if(st[j]=='R' && es) {cout<<"S";c--;es--;}
				
				if(st[j]=='P' && c!=0)
				{
					cout<<"S";c--;
				} 
				else if(st[j]=='P' && er) {cout<<"R";a--;er--;}
				else if(st[j]=='P' && ep) {cout<<"P";b--;ep--;}
				
				if(st[j]=='S' && a!=0)
				{
					cout<<"R";a--;
				} 
				else if(st[j]=='S' && ep) {cout<<"P";b--;ep--;}
				else if(st[j]=='S' && es) {cout<<"S";c--;es--;}
				
				j++;
			}
			cout<<"\n";
		}
	}
	
	return 0;
}
