#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

set<Node*>nd;
Node* solution(Node* root)
{
    Node* temp = root;
    nd.insert(root);

    if(root == root->next) return root;

    while(true)
    {
        Node* t = temp->next;
        if(t->data == temp->data)
        {
            temp->next = temp->next->next;
        }
        else
        {
            nd.insert(temp->next);
            temp=temp->next;
        }
        if(temp->next == root) break;
    }

    if(temp->data == root->data && temp!=root)
    {
        temp->next = temp->next->next;
        return temp;
    }
    return root;
}

int main()
{
    Node* head = new Node;
    Node* t1 = new Node;
    Node* t2 = new Node;
    Node* t3 = new Node;
    Node* t4 = new Node;

    head->data = 3;
    t1->data = 3;
    t2->data = 4;
    t3->data = 5;
    t4->data = 3;
    head->next = t1;
    t1->next = t2;
    t2->next = t3;
    t3->next = head;

    Node* r = solution(head);
    Node* t = r;

    cout<<r->data<<" ";
    while(t->next != r)
    {   
        t = t->next;
        cout<<t->data<<" ";
    }
    cout<<"\n";

    if(head == t3) cout<<"equal\n";
    else cout<<"unequal\n";

    return 0;
}
