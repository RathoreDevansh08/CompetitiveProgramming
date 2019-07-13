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
	if(n%4==0)
	{
		cout<<"1 A\n";
	}
	else if(n%4==1)
	{
		cout<<"0 A\n";
	}
	else if(n%4==2)
	{
		cout<<"1 B\n";
	}
	else
	{
		cout<<"2 A\n";
	}
	return 0;
}
