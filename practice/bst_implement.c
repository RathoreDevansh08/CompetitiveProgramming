#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node* left;
 struct node* right;
};

struct node* new(int d)
{
 struct node* newt = (struct node *)malloc(sizeof(struct node));
 newt->data=d;
 newt->left=NULL;
 newt->right=NULL;
 return newt;
}

struct node* insert(struct node* root,int d)
{
 if(root==NULL)
 root=new(d);
 else if(d<=root->data)
 root->left=insert(root->left,d);
 else
 root->right=insert(root->right,d);
 return root;
}

int main()
{
 struct node* root=NULL;
 root= insert(root,5);
 root= insert(root,20);
 root= insert(root,2);
 root= insert(root,7);
 root= insert(root,25);
 root= insert(root,11);
 return 0;
}

