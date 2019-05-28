#include<iostream>
#include<list>
#include<iterator>
using namespace std;

int main()
{
	long long int a,b;
	cin>>a>>b;
	list<long long int>l;
	list<long long int>::iterator it,it2;
	
	l.push_back(b);
	
	while(b>a)
        {
            if(b%2==0)
            {
                b=b/2;
                l.push_back(b);
            }
            else if((b-1)%10==0)
            {
                b-=1;
                b=b/10;
                l.push_back(b);
            }
            else break;
        }
        if(b<a || b>a)
        {
        	cout<<"NO\n";
        }
        else
        {
        	cout<<"YES\n"<<l.size()<<"\n";
        	it=l.end();
        	it--;
        	for(it2=it;it2!=l.begin();--it2)
        		cout<<*it2<<" ";
        	cout<<*it2;
        	cout<<"\n";
        }
	return 0;
}
