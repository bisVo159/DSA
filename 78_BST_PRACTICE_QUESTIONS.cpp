#include<iostream>
#include<vector>
#include<queue>
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

bool TwoSumInBST(node* root,int target){
    vector<int>inorderval;
    inorder(root,inorderval);
    int i=0,j=inorderval.size()-1;
    while(i<j){
        int sum=inorderval[i]+inorderval[j];
        if(sum==target)
        return true;
        else if(sum<target)
        i++;
        else
        j--;
    }
    return false;
}

node* flatten(node* root){
    vector<int>inorderval;
    inorder(root,inorderval);
    node* newroot=new node(inorderval[0]);

    node* curr=newroot;
     int n=inorderval.size();

    for(int i=1;i<n;i++){
        node* temp=new node(inorderval[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }
    curr->left=NULL;
    curr->right=NULL;
    return newroot;
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

node* balancedBST(node* root){
    vector<int>inorderval;
    inorder(root,inorderval);   
    return inorderToBST(0,inorderval.size()-1,inorderval);
}

node* solve(vector<int>&preorder,int mini,int maxi,int &i){      //By using only maxi also possible
    if(i>=preorder.size())
    return NULL;
    if(preorder[i]<mini||preorder[i]>maxi)
    return NULL;

    node* root=new node(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);
    return root;
}

node* preorderToBST(vector<int>&preorder){
    int mini=INT_MIN;
    int maxi=INT_MAX;
    int index=0;
    return solve(preorder,mini,maxi,index);
}

int main(){
   /* node* root=NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);*/
    // ----->TWO SUM IN A BST<-----
    //10 6 12 2 8 11 15 -1
    /*if(TwoSumInBST(root,20))
    cout<<"There is two node in BST which sum is equal to target "<<endl;
    else
    cout<<"Not present"<<endl;*/

    // ----->FLATTEN BST TO A SORTED LIST<------
    // node* newroot=flatten(root);

    // ----->NORMAL BST TO BALANCED BST<-----
    // node* balanced=balancedBST(root);

    // ----->BST FROM PREORDER<------
    vector<int>preorder={20,10,5,15,13,35,30,42};
    node* tree=preorderToBST(preorder);
    levelOrderTraversal(tree);
    
    return 0;
}