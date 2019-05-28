#include<iostream>
#include<cstring>

using namespace std;

float l;
float dp(int r,int g,int k)
{
	if(r==0) return 1.00;
	if(g==0 && k==0) return 1.00;
	else if(g==0 && k==1) return 0.00;
	l=(float)r/(r+g); 
	return (1-k)*l+ (1-l)*dp(r,g-1,1-k);
}

int main()
{
	int t,r,g;
	cin>>t;
	while(t--)
	{
		cin>>r>>g;
		printf("%f\n",dp(r,g,0));
	}
	return 0;
}
