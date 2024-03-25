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
class info{
    public:
    int maxi;
    int mini;
    bool isBST;
    int size;
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

info solve(node* root,int &ans){
        //base case
        if(root==NULL)
        return {INT_MIN,INT_MAX,true,0};

        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
            info currNode;

            currNode.size=left.size+right.size+1;
            currNode.maxi=max(root->data,right.maxi);
            currNode.mini=min(root->data,left.mini);
            if(left.isBST&&right.isBST&&(root->data>left.maxi&&root->data<right.mini)){
                currNode.isBST=true;
            }
            else{
                currNode.isBST=false;
            }
            //ans update
            if(currNode.isBST){
                ans=max(ans,currNode.size);
            }
            return currNode;
        }

int largestBST(node* root){
    int maxsize=0;
    info temp=solve(root,maxsize);
    return maxsize;
}

int main(){
    node* root=NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
     cout<<largestBST(root)<<endl;
     //5 2 4 1 3 -1

    return 0;
}