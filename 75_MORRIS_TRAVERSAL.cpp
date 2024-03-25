#include<iostream>
#include<queue>
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

void inOrderTraversal(node* root){
    if(root==NULL)
    return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void morrisTraversal(node* root){
    while(root!=NULL){
          if(root->left==NULL){
            cout<<root->data<<" ";
            root=root->right;
          }
          else{
            node* pred=root->left;
            while(pred->right!=NULL&&pred->right!=root){
                pred=pred->right;
            }
            if(pred->right==NULL){
            pred->right=root;
            root=root->left;
            }
            else{
                pred->right=NULL;
                cout<<root->data<<" ";
                root=root->right;
            }
          }
    }cout<<endl;
}

node* FlattenToLL(node* root){
    node* curr=root;
    while(curr!=NULL){
        if(curr->left){
            node* pred=curr->left;
            while(pred->right)
            pred=pred->right;
            pred->right=curr->right;
            curr->right=curr->left;
            curr->left=NULL;
        }
        curr=curr->right;
    }
    return root;
}

int main(){
    node* root=NULL;
     root=buildTree(root);
     //----->MORRIS TRAVERSAL<-----
    /* cout<<"Morris Traversal of the tree is : ";
     morrisTraversal(root);*/
     //1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1

     //----->FLATTEN A BINARY TREE TO LINKED LIST<-----
     //1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
     root=FlattenToLL( root);
    cout<<"Binary tree to Linked List : ";
    inOrderTraversal(root);
    
    return 0;
}