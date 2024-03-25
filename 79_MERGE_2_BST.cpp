#include<iostream>
#include<vector>
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

void inorder(node* root,vector<int>&in){
    if(root==NULL)
    return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}
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
node* inorderToBST(int s,int e,vector<int>&inorderval){
    //base case
    if(s>e)
    return NULL;
    int mid=(s+e)/2;
    node* root=new node(inorderval[mid]);
    root->left=inorderToBST(s,mid-1,inorderval);
    root->right=inorderToBST(mid+1,e,inorderval);
    return root;
}

vector<int> mergeArrays(vector<int>&a,vector<int>&b){
    vector<int>ans(a.size()+b.size());
    int i=0,j=0,k=0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i++];
        }
        else{
            ans[k++]=b[j++];
        }
    }
    while(i<a.size()){
        ans[k++]=a[i++];
    }
    while(j<b.size()){
        ans[k++]=b[j++];
    }
    return ans;
}

node* mergeBST(node* root1,node* root2){
    //step1 : store inorder 
    vector<int>bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    //step2 : merge both sorted arrays
    vector<int>mergeArray=mergeArrays(bst1,bst2);
    
    //step3 : use merged inorder array to BST
    int s=0,e=mergeArray.size()-1;
    return inorderToBST(s,e,mergeArray);
}

int main(){
     node* root1=NULL;
    cout<<"Enter data to create BST1 "<<endl;
    takeInput(root1);
     node* root2=NULL;
    cout<<"Enter data to create BST2 "<<endl;
    takeInput(root2);
    // ----->MERGE 2 BST<-----
    //50 40 60 70 -1 55 45 65 35 47 -1
    node* mergeTree=mergeBST(root1,root2);
    levelOrderTraversal(mergeTree);
    
    return 0;
}