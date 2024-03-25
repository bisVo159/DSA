#include<iostream>
#include<limits.h>
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
node* insertIntoBST(node* root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        //insert at right part
        root->right=insertIntoBST(root->right,d);
    }
    else{
        //insert at left part
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
            cin>>data;
    }
}

bool isBST(node* root,int min,int max){
    //base case
    if(root==NULL)
    return true;

    if(root->data>=min&&root->data<=max){
        bool left= isBST(root->left,min,root->data);
        bool right= isBST(root->right,root->data,max);
        return left&&right;
    }
    else{
        return false;
    }
}

bool ValidateBST(node* root ){
    return isBST(root,INT_MIN,INT_MAX);
}

int solve(node* root,int &i,int k){
    if(root==NULL)
    return -1;

    int left=solve(root->left,i,k);
    if(left!=-1){
        return left;
    }
    //N
    i++;
    if(i==k){
        return root->data;
    }
    //right
    return solve(root->right,i,k);
}

int kthSmallest(node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

int solve2(node* root,int &i,int k){
    if(root==NULL)
    return -1;

    int right=solve2(root->right,i,k);
    if(right!=-1)
    return right;

    //N
    i++;
    if(i==k)
    return root->data;

    //left
    return solve2(root->left,i,k);
}

int KthLargest(node* root,int k){
    int i=0;
    int ans=solve2(root,i,k);
    return ans;
}

pair<int,int> predecessorSuccessor(node* root,int key){
    int pred=-1;
    int succ=-1;
    node* temp=root;
    while(temp->data!=key){
        if(temp->data>key){
        succ=temp->data;
        temp=temp->left;
        }
        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
    //pred
    node* leftTree=temp->left;
    while(leftTree!=NULL){
        pred=leftTree->data;
        leftTree=leftTree->right;
    }
    //succ
    node* rightTree=temp->right;
    while(rightTree!=NULL){
        succ=rightTree->data;
        rightTree=rightTree->left;
    }
    // pair<int,int>ans=make_pair(pred,succ);
    return {pred,succ};
}

/*node* LCAinaBST(node*root,int a,int b){
    if((root==NULL))
    return NULL;

    if(root->data<a&&root->data<b)
    return LCAinaBST(root->right,a,b);
    else if(root->data>a&&root->data>b)
    return LCAinaBST(root->left,a,b);
    else
    return root;
}*/
node* LCAinaBST(node*root,int a,int b){
    if((root==NULL))
    return NULL;

    while(root!=NULL){
    if(root->data<a&&root->data<b)
    root= root->right;
    else if(root->data>a&&root->data>b)
    root=root->left;
    else
    return root;
    }
}

int main(){
    node* root=NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
    // ------>VALIDATE BST<------
    //4 2 5 1 3 -1
    if(ValidateBST(root ))
    cout<<"Valid BST "<<endl;
    else
    cout<<"Not valid"<<endl;

    // ------>Kth SMALLEST<------
    //5 4 8 2 6 10 3 7 -1
    cout<<"Kth smallest is "<<kthSmallest(root,3)<<endl;
    cout<<"Kth largest is "<<KthLargest(root,3)<<endl;
    //HW:using morris traversal

    // ----->PREDECESSOR AND SUCCESSOR<-----
    pair<int,int>ans=predecessorSuccessor(root,8);
    cout<<"Predecessor is "<<ans.first<<endl;
    cout<<"Successor is "<<ans.second<<endl;

    // ----->LCA IN BST<-----
    cout<<"LCA in BST "<<LCAinaBST(root,6,10)->data<<endl;
    
    return 0;
}