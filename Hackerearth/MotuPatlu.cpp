#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		float a[n],b[n];int m=0,p=n-1,mc=0,pc=0,c=0;
		for(int i=0;i<n;i++){cin>>a[i];b[i]=a[i];}
		
		while(m<p)
		{
			if(a[m]/2<a[p])
			{
				a[p]-=(float)a[m]/2;a[m]=0.0;
				m++;mc++;c=1;
			}
			else if(a[m]/2>a[p])
			{
				a[m]=(float)((float)a[m]/2-a[p])*2;a[p]=0.0;
				p--;pc++;c=2;
			}
			else
			{
				a[m]=0.0;a[p]=0.0;
				p--;m++;
				mc++;pc++;c=3;
			}
		}
		if(m==p)
		{
			if(a[m]==b[m])mc++;
			else 
			{
				if(c==1)pc++;
				else if(c==2)mc++;
				else mc++;
			}
		}
		
		if(mc==pc)cout<<mc<<" "<<pc<<"\n"<<"Tie\n";
		else if(mc>pc)cout<<mc<<" "<<pc<<"\n"<<"Motu\n";
		else cout<<mc<<" "<<pc<<"\n"<<"Patlu\n";
	}
	
	return 0;
}
