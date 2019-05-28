#include<iostream>
#include<cmath>
using namespace std;

int le(int i){return 2*i+1;}
int ri(int i){return 2*i+2;}
int par(int i){return floor((i-1)/2);}

int sr;
int construct(int s[],int a[],int ind,int l,int r)
{
 if(l==r){sr=l;s[ind]=a[l];return a[l];}
 else
 {
  sr=ceil((float)(r+l-1)/2); 
  s[le(ind)]=construct(s,a,le(ind),l,sr);
  s[ri(ind)]=construct(s,a,ri(ind),sr+1,r);
  s[ind]=s[le(ind)]+s[ri(ind)]; 
 } 
 return s[ind];
}

int update(int s[],int a[],int ind,int l,int r,int lr,int rr,int up)
{
 if(l>rr || lr>r)return s[ind];
 if(l==r)
 {
  sr=l;
  if(lr<=l && l<=rr)s[ind]+=up;
  else s[ind]=a[l];
  return s[ind];
 }
 else
 {
  sr=ceil((float)(r+l-1)/2); 
  s[le(ind)]=update(s,a,le(ind),l,sr,lr,rr,up);
  s[ri(ind)]=update(s,a,ri(ind),sr+1,r,lr,rr,up);
  s[ind]=s[le(ind)]+s[ri(ind)]; 
 } 
 return s[ind];
}

int sum(int s[],int a[],int ind,int l,int r,int lr,int rr)
{
 if(l>rr || lr>r)return 0;
 else if(lr<=l && r<=rr)return s[ind];
 else
 {
  sr=ceil((float)(r+l-1)/2);
  return sum(s,a,le(ind),l,sr,lr,rr)+sum(s,a,ri(ind),sr+1,r,lr,rr);
 }
}

int main()
{
 int n=6,su,a[6]={1,3,5,7,9,11},s[15]={0};
 s[0] = construct(s,a,0,0,5);
 
 for(int i=0;i<15;i++)cout<<s[i]<<" ";
 cout<<"\n";
 
 su = sum(s,a,0,0,5,2,4);
 cout<<"sum is:"<<su<<"\n";
 
 s[0] = update(s,a,0,0,5,2,5,10);
 for(int i=0;i<15;i++)cout<<s[i]<<" ";
 cout<<"\n";
 
 su = sum(s,a,0,0,5,2,4);
 cout<<"updated sum is:"<<su<<"\n";
 
 return 0;
}
