#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n,a,x=0;cin>>n;
	for(int i=0;i<n;i++)cin>>a,x^=a;
	cout<<(x==0?-1:1)<<endl;
}
