#include<stdio.h>
#include<stdlib.h>

struct tree
{
 int data;
 struct tree*left;
 struct tree*right;
};
struct tree* new (int data)
{
    struct tree* temp = (struct tree *) malloc( sizeof(struct tree*) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
/*struct node *construct (int d[], int size)
{
    int i = 0;
    return constructTreeUtil ( d, &i, d[0], INT_MIN, INT_MAX, size );
}
void treef(int a[])
{
 struct tree*t;
 t->data=a[0];
}*/

void func(struct tree* root,int d[])
 {
    static int i=1;
    static tree *temp = new (d[i]);
    if (root->data > d[i])
       {
        root->left=temp;
        
       }
  
    else if (root->data < d[i])
       {root->right=temp;}
    
    func()
    return;
 }
 
void construct (int d[],int size)
{
 struct tree* root = new (d[0]); 
 func(&root,d)
}

int main()
{
 int d[]={10,5,9,18,7,5},size=6;
 construct(d, size);
 
} 
