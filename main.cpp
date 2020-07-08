/************************

Author Sahil Pant

*************************/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    TreeNode *left = NULL;
    int data;
    TreeNode *right = NULL;
}*root = NULL;

typedef struct TreeNode node;


node* create(int data){
    node *NewNode = new node;
    NewNode->data = data;
    return NewNode;
}

node* insert(node *root,int data){
    
    if(root == NULL){
        return create(data);
    }
    
    if(root)
    {
        if(root->data > data){
            root->left = insert(root->left,data);
        }
        else
        {
            root->right = insert(root->right,data);
        }
    }
}


void Preorder(node *root ){
    if(root){
        cout<<root->data<<" ";
        Preorder(root->left);
        Preorder(root->right);
    }
}


void Inorder(node *root)
{
    if(root)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}

void Postorder(node *root){
    if(root){
        Postorder(root->left);
        Postorder(root->right);
        cout<<root->data<<" ";
    }
}


int main()
{
    char ch;int n;int data;
    cout<<"\nDo You want to create a BST?";
    cin>>ch;
    A:
    if(ch == 'y'||ch == 'Y')
    {
        cout<<"\nEnter the data::";
        cin>>data;
        root = create(data);
    }
    B:
    cout<<"\nChoose from the below options::";
    cout<<"\n1. Insert an element::";
    cout<<"\n2. Preorder traversal::";
    cout<<"\n3. Postorder traversal::";
    cout<<"\n4. Inorder traversal::\n";
    cin>>n;
    switch(n)
    {
        case 1:
        int data;
        cout<<"\nEnter data::";
        cin>>data;
        insert(root,data);
        break;
        
        case 2:
        Preorder(root);
        break;

        case 3:
        Postorder(root);
        break;

        case 4:
        Inorder(root);
        break;
    }
    char ch1;
    cout<<"\ndo you want to continue?";
    cin>>ch1;
    if(ch1 == 'y' || ch1 == 'Y')
    {
        cout<<"\ndo you want to continue with the same tree?";
        cin>>ch1;
        if(ch1 == 'y' || ch1 == 'Y') goto B;
        else 
        {
            delete root;
            goto A;
        }
    }
    
    else exit(0);
}