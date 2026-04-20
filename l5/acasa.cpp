#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct Node
{
    int data;
    Node *left,*right;
    Node(int val)
    {
        data=val;
        left=right=nullptr;
    }
};
struct Compare
{
    bool operator()(Node* a,Node *b)const
    {
        return a->data>b->data;//min heap
    }
};
int calcul_LEP(Node* root,int depth)
{
    if(root==nullptr)
    {
        return 0;
    }
    else
    {
        if(root->left==nullptr && root->right==nullptr)//frunza
        {
            return root->data*depth;
        }
        return calcul_LEP(root->left,depth+1)+calcul_LEP(root->right,depth+1);
    }
}
void stergere_arbore(Node *root)
{
    if(root==nullptr)
    {
        return;
    }
    stergere_arbore(root->left);
    stergere_arbore(root->right);
    delete root;
}
int main()
{
    priority_queue<Node*,vector<Node*>,Compare> B;
    int n,val;
    cout<<"n=";cin>>n;
    cout<<"elem :";
    for(int i=0;i<n;i++)
    {
        cin>>val;
        B.push(new Node(val));
    }
    //incep procedura
    while(B.size()>1)
    {
        Node *t1=B.top();
        B.pop();
        Node *t2=B.top();
        B.pop();
        Node *t=new Node(t1->data+t2->data);
        t->left=t1;
        t->right=t2;
        B.push(t);
    }
    Node *root=B.top();
    cout<<calcul_LEP(root,0);
    stergere_arbore(root);
    // ori cu stergere
    // ori trb folosi unique_ptr din <memory>
    // si std::move()
    return 0;
}