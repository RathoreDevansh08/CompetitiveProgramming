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
	
	long int as[102],k;
	as[1]=1;k=2;
	fr(i,2,100)
	{
		as[i]=as[i-1]+4*(k-1);
		k++;
	}
	cout<<as[n]<<"\n";
	return 0;
}
