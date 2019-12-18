#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0,sum,even,zero;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>st;
		sum=0;even=0;zero=0;
		
		a=0;
		while(st[a])
		{
			sum += st[a] - '0' ;
			if(!(st[a]-'0')) zero++;
			if((st[a]-'0')%2 == 0) even++;
			
			a++;
		}
		
		if(sum%3!=0 || zero==0 || even<2) cout<<"cyan\n";
		else cout<<"red\n";
	}
	return 0;
}
