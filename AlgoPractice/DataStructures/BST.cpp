#include<bits/stdc++.h> 
using namespace std; 
  
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 

struct node *newNode(int item) 
{ 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        cout<<  root->key << " "; 
        inorder(root->right); 
    } 
} 

struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
  
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    return node; 
} 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 

//Time complexity : O(height_of_tree)
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 
   
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 

//Time complexity : O(n)
struct node* constructTreeUtil( int pre[], int* preIndex, int key,  
                                int min, int max, int size )  
{  
    // Base case  
    if( *preIndex >= size )  
        return NULL;  
  
    node* root = NULL;  
  
    // If current element of pre[] is in range, then  
    // only it is part of current subtree  
    if( key > min && key < max )  
    {  
        // Allocate memory for root of this  
        // subtree and increment *preIndex  
        root = newNode ( key );  
        *preIndex = *preIndex + 1;  
          
        if (*preIndex < size)  
        {  
            // Construct the subtree under root  
            // All nodes which are in range  
            // {min .. key} will go in left  
            // subtree, and first such node  
            // will be root of left subtree.  
            root->left = constructTreeUtil( pre, preIndex, pre[*preIndex],  
                                        min, key, size );  
  
            // All nodes which are in range  
            // {key..max} will go in right  
            // subtree, and first such node 
            // will be root of right subtree.  
            root->right = constructTreeUtil( pre, preIndex, pre[*preIndex],  
                                        key, max, size );  
        }  
    }  
    return root;  
}  

struct node *constructTree (int pre[], int size)  
{  
    int preIndex = 0;  
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN,  
                            INT_MAX, size );  
}  

int main() 
{ 
    struct node *root = NULL; 
    root = insert(root, 50); 
    root = insert(root, 30); 
    root = insert(root, 20); 
    root = insert(root, 40); 
    root = insert(root, 70); 
    root = insert(root, 60); 
    root = insert(root, 80); 
  
    cout << "Inorder traversal of the given tree \n"; 
    inorder(root);
    cout << "\n"; 
  
    cout<<"\nDelete 20\n"; 
    root = deleteNode(root, 20); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root);
    cout << "\n"; 
  
    cout<<"\nDelete 30\n"; 
    root = deleteNode(root, 30); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root); 
    cout << "\n"; 
  
    cout<<"\nDelete 50\n"; 
    root = deleteNode(root, 50); 
    cout<<"Inorder traversal of the modified tree \n"; 
    inorder(root);
    cout << "\n";  
  
    // Pre-order traversal to BST
    int pre[] = {10, 5, 1, 7, 40, 50};  
    int size = sizeof( pre ) / sizeof( pre[0] );  
  
    node *ro = constructTree(pre, size);  
  
    cout<<"\nInorder traversal of the constructed tree: \n";  
    inorder(ro);
    cout << "\n"; 
       
    return 0; 
} 
