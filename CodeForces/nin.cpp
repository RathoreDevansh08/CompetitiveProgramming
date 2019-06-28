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
long int sod(int y)
{
	long int sum=0;
	while(y)
	{
		sum+=y%10;
		y=y/10;
	}
	return sum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	while(sod(n)%4!=0)
	{
		n+=1;
	}
	cout<<n<<"\n";
	return 0;
}
