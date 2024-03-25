#include<iostream>
using namespace std;

class Node{
    public:
    int key,height;
    Node* left;
    Node* right;

    Node(int d){
        key=d;
        height=1;
    }
};

int height(Node* N){
    if(N==NULL)
        return 0;

    return N->height;
}

int getBalance(Node* N){
    if(N==NULL)
    return 0;
    return height(N->left)-height(N->right);
}

Node* rightRotate(Node* x){
    Node* y=x->left;
    Node* T2=y->right;

    y->right=x;
    x->left=T2;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
Node* leftRotate(Node* x){
    Node* y=x->right;
    Node* T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}

Node* insert(Node* node,int key){
    if(node==NULL){
    node=new Node(key);
    return node;
}
    if(key<node->key)
         node->left=insert(node->left,key);
    if(key>node->key)
         node->right=insert(node->right,key);

    node->height=max(height(node->left),height(node->right))+1;

    int balance=getBalance(node);

    if(balance>1&&key<node->left->key)
        return rightRotate(node);
    if(balance<-1&&key>node->right->key)
        return leftRotate(node);
    if(balance>1&&key>node->left->key){
        node->left=leftRotate(node->left);
        return rightRotate(node);
    }
    if(balance<-1&&key<node->right->key){
        node->right=rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

int main(){
    
    return 0;
}