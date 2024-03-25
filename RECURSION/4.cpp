#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
     cout<<"Enter the data"<<endl;
     int data;
     cin>>data;
     root = new node(data);
     if(data==-1){
        return NULL;
     }
     cout<<"Enter data for inserting in left of "<<data<<endl;
     root->left=buildTree(root->left);
     cout<<"Enter data for inserting in right of "<<data<<endl;
     root->right=buildTree(root->right);
     return root;
}

bool checkMirror(node* tree1,node* tree2){
    if(tree1==NULL&&tree2==NULL)
    return true;
    else if(tree1==NULL&tree2!=NULL)
    return false;
    else if(tree2==NULL&tree1!=NULL)
    return false;

    if(tree1->data==tree2->data)
        return checkMirror(tree1->left,tree2->right)&&checkMirror(tree1->right,tree2->left);
    else
    return false;
}

bool isSymmetric(node* root){
    if(root==NULL)
    return true;

    return checkMirror(root->left,root->right);
}

int main(){
    node* root=NULL;
    root=buildTree(root);
    // 1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1
    // 3 4 6 -1 -1 -1 5 7 -1 -1 8 -1 -1
    if(isSymmetric(root))
    cout<<"Symmetric"<<endl;
    else
    cout<<"Not Symmetric"<<endl;
    
    return 0;
}