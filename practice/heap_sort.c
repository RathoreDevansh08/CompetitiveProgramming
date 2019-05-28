#include<stdio.h>

void swap(int *a,int *b)
{
 int t;
 t=*a;
 *a=*b;
 *b=t;
}

void max_heapify(int A[],int i,int n)
{
 static int lar;
 int f=0;
 if((2*i)<=(n-1) && A[2*i-1]<=A[2*i])
  {
   if(A[i-1]<A[2*i])
   {
    swap(&A[i-1],&A[2*i]);
    lar=2*i+1;f=1;
   }
  }
 else if(((2*i)<=n) && A[i-1]<A[2*i-1])
  {
   swap(&A[i-1],&A[2*i-1]);
   lar=2*i;f=1;
  }
  
  if(f==1)
  max_heapify(A,lar,n);
 
 return;
}

void build_maxheap(int A[],int n)
{			
 for(int i=(n-1)/2;i>=1;i--)
 {
  max_heapify(A,i,n);
 } 
 return;
}

void heap_sort(int A[],int n)
{
 build_maxheap(A,n);
 /*int s=1;
 while(n>s)
 {
  swap(&A[0],&A[n-s]);
  build_maxheap(A,n-s); 
  s++;
 }*/
 return;
}
 
 void insert(int A[],int k, int *n)
 {
 int j;
  *n=*n+1;
  A[*n-1]=k;
  while(j>1)
  {
  if(j%2==0)
   {
   if(A[j]>A[j/2-1])
    {swap(&A[j],&A[j/2-1]);
    j=j/2-1;}
   else break; 
   }
  else if(j&2!=0)
  {
  if(A[j]>A[j/2])
   {swap(&A[j],&A[j/2]);
   j=j/2;}
  else break;
  }  
  }
 }

int main()
{
 int A[]={4,3,7,2,9,1,0,5,8,6,0,0},n=10,key;
 
 heap_sort(A,n);
 if(A[1]<A[0])swap(&A[0],&A[1]);
 
 for(int i=0;i<n;i++)
 {
  printf("%d\n",A[i]);
 }
 
 printf("insert key to be inserted in heap:");
 scanf("%d",&key);
 insert(A,key,&n);
 
 for(int i=0;i<n;i++)
 {
  printf("%d\n",A[i]);
 }
return 0;
}

