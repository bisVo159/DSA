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

// create mapping 
// return target node
node* createParentMapping(node* root,int target,map<node*,node*>&nodeToParent){
    node* res=NULL;
    queue<node*>q;
    q.push(root);
    nodeToParent[root]=NULL;
    while(!q.empty()){
        node* front=q.front();
        q.pop();
        if(front->data==target){
            res=front;
        }
        if(front->left){
        nodeToParent[front->left]=front;
        q.push(front->left);
        }
        if(front->right){
        nodeToParent[front->right]=front;
        q.push(front->right);
        }
    }
    return res;
}

int burnTree(node* root,map<node*,node*>&nodeToParent){
    map<node*,bool>visited;
    queue<node*>q;
    q.push(root);
    visited[root]=true;

    int ans=0;
    while(!q.empty()){
        bool flag=0;
        int size=q.size();
        for(int i=0;i<size;i++){
            node* front=q.front();
            q.pop();
            if(front->left&&!visited[front->left]){
                q.push(root->left);
                visited[root->left]=1;
                flag=1;
            }
            if(front->right&&!visited[front->right]){
                q.push(root->right);
                visited[root->right]=1;
                flag=1;
            }
            if(nodeToParent[front]&&!visited[nodeToParent[front]]){
               q.push(nodeToParent[front]);
               visited[nodeToParent[front]]=1;
               flag=1;
            }
        }
        if(flag==1){
            ans++;
        }
    }
    return ans;
}

int minTree(node* root,int target){
    map<node*,node*>nodeToParent;
    node* targetNode=createParentMapping(root,target,nodeToParent);
    int ans=burnTree(targetNode,nodeToParent);
    return ans;
}

int main(){
    // step1 : create nodeToParent mapping
    // step2 : find target node
    // step3 : burn the tree in min time
    //1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1
    node* root=NULL;
     root=buildTree(root);
    cout<<"Maximum time to burn a binary tree "<<minTree(root,8)<<endl;
    
    return 0;
}