#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 struct node *left, *right;
 int data;
}node;

node* createNode(int d)
{
 node* t=(node*)malloc(sizeof(node));
 t->left=NULL;
 t->right=NULL;
 t->data=d;
 return t;
}

void insert(int d,node* root)
{
 node* t= createNode(d);
 if(d<root->data)
 {
  if(root->left==NULL)
  {root->left=t;return;}
  insert(d,root->left);
 }
 else if(d>root->data)
 {
  if(root->right==NULL)
  {root->right=t;return;}
  insert(d,root->right);
 }
 return;
}

void Lorder(node* node,int h) 
{ 
    if (node == NULL) 
        return; 
    if(h==1)printf("%d ",node->data);
    else if(h>1)
    {
     Lorder(node->left,h-1);
     Lorder(node->right,h-1);
    } 
    return;
} 


void Lorderprint(node* root)
{
 for(int i=1;i<=6;i++)
 {
  Lorder(root,i);
 }
}


int main()
{
 int n=10,b;
 node* root,*r;
 scanf("%d",&b);
 root=createNode(b);
 for(int i=1;i<n;i++)
 {
  scanf("%d",&b);
  insert(b,root);
 }
 //printf("----------\nr: %d\n",root->left->left->left->data);
 Lorderprint(root);
 return 0;
}
