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

node* buildFromLevelOrder(node*  &root){
    queue<node*>q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

void inorder(node* root,int &count){
    //Base case
    if( root==NULL)
    return;
    inorder(root->left,count);
    //leaf node
    if(root->left==NULL&&root->right==NULL){
       count++;
    }
     inorder(root->right,count);
}

int noOfLeafNodes(node* root){
    int cnt=0;
inorder(root,cnt);
return cnt;
}

int main(){
    node* root=NULL;
     buildFromLevelOrder(root);
     levelOrderTraversal(root);
     //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

     //------->COUNT TOTAL NUMBER OF LEAF NODES<------

     cout<<"No of leaf nodes are "<<noOfLeafNodes(root);
    
    return 0;
}