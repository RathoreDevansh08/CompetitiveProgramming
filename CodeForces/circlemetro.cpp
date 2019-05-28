#include<iostream>

using namespace std;

int n,a,x,b,y,k,l,f,fa,fb;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>a>>x>>b>>y;
	int pa[2*n+1],pb[2*n+1];
	k=a;l=b;f=0;fa=0;fb=0;
	for(int i=1;i<=n;i++)
	{
		if(k!=n)k+=1;
		else k=1;
		if(l!=1)l-=1;
		else l=n;
		
		if(k==l){f=1;break;}
		if(k==x || l==y) break;
	}
	if(f)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
