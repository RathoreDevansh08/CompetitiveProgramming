#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
int data;
struct node *l,*r;
}node;

node* createNode(int k)
{
 node* n=(node*)malloc(sizeof(node));
 n->data=k;
 n->l=n->r=NULL;
 return n;
}

void inorder(node* root)
{
 if(root==NULL)return;
 inorder(root->l);
 printf("%d ",root->data);
 inorder(root->r);
}

node* insert (node* root,int k)
{
 if(root==NULL)return createNode(k);
 if(k<root->data)root->l=insert(root->l,k);
 else if(k>root->data)root->r=insert(root->r,k);
 return root;
}

node* mina(node* root)
{
 node* t=root;
 while(t->l!=NULL)t=t->l;
 return t;
}

node* delete(node* root,int k)
{
 if(root==NULL)return root;
 if(k<root->data)root->l=delete(root->l,k);
 else if(k>root->data)root->r=delete(root->r,k);
 else
 {
  if(root->l==NULL)
  {
   node* temp=root->r;
   free(root);
   return temp;
  }
  else if(root->r==NULL)
  {
   node* temp=root->l;
   free(root);
   return temp;
  }
  node* s=mina(root->r);
  root->data=s->data;
  root->r=delete(root->r,s->data);
 }
 return root;
}

int main() 
{
    node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 20\n"); 
    root = delete(root, 20); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 30\n"); 
    root = delete(root, 30); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 50\n"); 
    root = delete(root, 50); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    return 0; 
} 
