#include<iostream>
#include<cmath>
using namespace std;

#define INF 100007

int le(int i){return 2*i+1;}
int ri(int i){return 2*i+2;}
int par(int i){return floor((i-1)/2);}

int minu(int as,int bs){if(as<=bs)return as;return bs;}

int sr;
void construct(int s[],int a[],int ind,int l,int r)
{		
 if(l==r){sr=l;s[ind]=a[l];
 //return a[l];
 }
 else
 {
  //sr=ceil((float)(r+l-1)/2); 
  sr=(l+r)>>1;
  //s[le(ind)]=construct(s,a,le(ind),l,sr);
  construct(s,a,le(ind),l,sr);
  //s[ri(ind)]=construct(s,a,ri(ind),sr+1,r);
  construct(s,a,ri(ind),sr + 1, r);
  s[ind]=min(s[le(ind)],s[ri(ind)]); 
 } 
 //return s[ind];
}

void update(int s[],int a[],int ind,int l,int r,int lr,int rr,int up)
{
 if(l>rr || lr>r)return ;
 if(l==r)
 {
  sr=l;
  if(lr<=l && l<=rr)s[ind]+=up;
  else s[ind]=a[l];
  return ;
 }
 else
 {
  sr=(l + r)>>1; 
  //s[le(ind)]=
  update(s,a,le(ind),l,sr,lr,rr,up);
  //s[ri(ind)]=
  update(s,a,ri(ind),sr+1,r,lr,rr,up);
  s[ind]=minu(s[le(ind)],s[ri(ind)]); 
 } 
 //return s[ind];
}

int mina(int s[],int a[],int ind,int l,int r,int lr,int rr)
{
 
 if(lr<=l && r<=rr)return s[ind];
 else if(l>rr || lr>r)return INF;
 else
 {
  sr=(l + r)>>1;
  return minu(mina(s,a,le(ind),l,sr,lr,rr),mina(s,a,ri(ind),sr+1,r,lr,rr));
 }
}

int main()
{
 int n=6,a[6]={2,5,11,14,19,13},s[36]={0};
 construct(s,a,0,0,5);
 
 for(int i=0;i<36;i++)cout<<s[i]<<" ";
 cout<<"\n";
 
 cout<<"minimum value in range 2 to 4:"<<mina(s,a,0,0,5,2,4)<<"\n";
 
 update(s,a,0,0,5,2,5,10);
 for(int i=0;i<36;i++)cout<<s[i]<<" ";
 cout<<"\n";
 
 cout<<"minimum value in range 2 to 4 (after updation) :"<<mina(s,a,0,0,5,2,4)<<"\n";
 
 return 0;
}
