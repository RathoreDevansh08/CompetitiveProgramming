#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
 struct node *left,*right;
 char data;
}node;


node* newNode(char data) 
{ 
    node* n = (node*)malloc(sizeof(node)); 
    n->data = data; 
    n->left = NULL; 
    n->right = NULL; 
    return (n); 
} 

int search(int st,int en,char a[],int d)
{
 for(int i=st;i<=en;i++)
 {
  if(a[i]==d)return i;
 }
}

int w=0;
node* build(char a[],char b[],int st,int en)
{
 if(st>en) return NULL;
 node *t=newNode(b[w++]);
 if(st==en) return t;
 
 int ind=search(st,en,a,t->data);
 
 t->left=build(a,b,st,ind-1);
 t->right=build(a,b,ind+1,en);
 return t;
}

void printInorder(node* node) 
{ 
    if (node == NULL) 
        return; 
  
    /* first recur on left child */
    printInorder(node->left); 
  
    /* then print the data of node */
    printf("%c ", node->data); 
  
    /* now recur on right child */
    printInorder(node->right); 
} 

int main()
{
 char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
 char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
 int n=6;
 
 node* root=build(in,pre,0,5);
 
 printInorder(root);
return 0;
}
