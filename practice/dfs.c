#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ne=500,nv=500;int a[500][500]={0};
int par[500],vis[500];

void explore(int i)
{
 vis[i]=1;
 for(int j=0;j<nv;j++)
 {
  if(a[i][j]==1 && vis[j]==0)
  {
   par[j]=i;
   printf("%d\t",j);
   explore(j);
  }
 }
 return;
}

void dfs(int ne,int nv)
{
 for(int i=0;i<ne;i++)
 {
  if(vis[i]==0)
  {
   printf("%d\t",i);
   explore(i);
  }
 }
}

int main()
{
 int b,c;
 
 scanf("%d %d",&ne,&nv);
 
 for(int i=0;i<ne;i++)
 {
  scanf("%d %d",&b,&c);
  a[b][c]+=1;
 }
 dfs(ne,nv);
 return 0; 
}
