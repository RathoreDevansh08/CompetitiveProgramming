#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long int big(long int a,long int b)
{
 if(a>=b)return a;
 return b;
}

int main()
{
 long int n,q,k;
 char ch;
 
 cin>>n>>q>>k;

 long int c[n],s=0,h=0,sh=0,m,b,v1,v2,l,w=0;
 std::vector<long int>a(2*n),d(2*n),e(2*n);

 for(long int i=0;i<n;i++)
 {
  cin>>a[n-i-1];
  a[2*n-1-i]=a[n-i-1];
  if(a[n-i-1])s++;
  else 
  {
   if(w==0){b=s;w++;s=0;continue;}
   if(s>=h){sh=h;h=s;}
   else if(s>sh){sh=s;}
   s=0;
  }
 }

 if(s+b>=h){sh=h;h=s+b;}
 else if(s+b>sh){sh=s+b;}

 if(h==sh || h==0 || h==1 || h==n || sh>=k)
 {
  c[0]=h;if(c[0]>k)c[0]=k;
  long int shift=0;
  for(long int i=0;i<q;i++)
  {
   cin>>ch;
   if(ch=='!')
   {shift++;shift=shift%n;}
   else
   {
    cout<<c[0]<<"\n";
   }
  }
 return 0;
}
else{
long int hj=0,hl=0;
for(int i=0;i<2*n;i++)
{
 if(a[i]==1)
 {hj++;d[i]=hj;}
 else
 {hj=0;d[i]=hj;}
 if(a[2*n-i-1]==1)
 {hl++;e[2*n-i-1]=hl;}
 else
 {hl=0;e[2*n-i-1]=hl;}
}

for(long int i=0;i<n;i++)
{
 if(a[i]==1 && a[n-1+i]==1)
 {
  m=e[i];l=d[n-1+i];
  if((m+l)==h)
  {
   c[i]=big(sh,big(m,l));
  }
  else c[i]=h;
 }
 else c[i]=h;
 if(c[i]>k)c[i]=k;
}}

long int shift=0;
for(long int i=0;i<q;i++)
{
 cin>>ch;
 if(ch=='!')
 {shift++;shift=shift%n;}
 else
 {
  cout<<c[shift]<<"\n";
 }
}
return 0;
}
