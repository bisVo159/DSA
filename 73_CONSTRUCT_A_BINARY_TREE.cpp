#include<iostream>
#include<queue>
#include<map>
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
void levelOrderTraversal(node* root){
      queue<node*>q;
      q.push(root);
      q.push(NULL);

      while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){//Old level traverse completed
            cout<<endl;
            if(!q.empty()) {     //queue still has some child nodes
                  q.push(NULL);
            }
        }

        else{
              cout<<temp->data<<" ";
            if(temp->left){
             q.push(temp->left);
        }

        if(temp->right){
             q.push(temp->right);
        }
        }
      }
}

void createMapping(int in[],map<int,int>&nodeToindex,int n){
      for(int i=0;i<n;i++){
          nodeToindex[in[i]]=i;
      }
}

node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n,map<int,int>nodeToindex){
    //base case
    if(index>=n||inorderStart>inorderEnd)
    return NULL;

    //create a root node for element
    int element=pre[index++];
    node* root=new node(element);
    //find element index in inorder
    int position=nodeToindex[element];
    root->left=solve(in,pre,index,inorderStart,position-1,n,nodeToindex);
    root->right=solve(in,pre,index,position+1,inorderEnd,n,nodeToindex);
    return root;
}

node* buildTree(int in[],int pre[],int n){
    int preOrderIndex=0;
    map<int,int>nodeToindex;
    //create node to index mapping
    createMapping(in,nodeToindex,n);
   node* ans= solve(in,pre,preOrderIndex,0,n-1,n,nodeToindex);
    return ans;
}

node* solve2(int in[],int post[],int &index,int inorderstart,int inorderend,int n,map<int,int>nodeToindex){
    if(index<0||inorderstart>inorderend)
    return NULL;

    int element=post[index--];
    node* root=new node(element);
    int position=nodeToindex[element];
    //recursive calls in case of posorder and inorder we first build right subtree
    root->right=solve2(in,post,index,position+1,inorderend,n,nodeToindex);
    root->left=solve2(in,post,index,inorderstart,position-1,n,nodeToindex);
    return root;
}

node* buildTree2(int in[],int post[],int n){
    int postorderindex=n-1;
    map<int,int>nodeToindex;
    createMapping(in,nodeToindex,n);
    node* ans=solve2(in,post,postorderindex,0,n-1,n,nodeToindex);
    return ans;
}

int main(){
    // --->CONSTRUCT A BINARY TREE FROM INORDER AND PREORDER TRAVERSAL<---
   /* int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    node* root=buildTree(in, pre,6);
    levelOrderTraversal(root);*/

    // --->CONSTRUCT A BINARY TREE FROM INORDER AND POSTORDER TRAVERSAL<---
    int in[]={4,8,2,5,1,6,3,7};
    int post[]={8,4,5,2,6,7,3,1};
    node* root=buildTree2(in, post,8);
    levelOrderTraversal(root);
   
    return 0;
}