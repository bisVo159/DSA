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

int height(node* root){
    //base case
    if(root==NULL)
    return 0;

    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}

pair<int,int> diameterfast(node* root){
     if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
     }

     pair<int,int>left=diameterfast(root->left);
     pair<int,int>right=diameterfast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;
    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;
    return ans;
}
// int diameterF(node* root){
//     return diameterfast(root).first;
// }

int diameter(node* root){
    if(root==NULL)
    return 0;

    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=height(root->left)+1+height(root->right);
    int ans=max(op1,max(op2,op3));
    return ans;
}

pair<bool,int> isBalancedFast(node* root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }

        pair<bool,int>left=isBalancedFast(root->left);
        pair<bool,int>right=isBalancedFast(root->right);

        pair<bool,int>ans;
        bool diff=(abs(left.second-right.second<=1));
        ans.first=(left.first&&right.first&&diff);
        ans.second=max(left.second,right.second)+1;
        return ans;
    }

bool isBalancedTree(node* root){
    if(root==NULL)
    return true;

    bool left=isBalancedTree(root->left);
    bool right=isBalancedTree(root->right);
    bool diff=abs(height(root->left)-height(root->right)<=1);
    return left&&right&&diff;
}

int main(){
    //----->HEIGHT OF A BINARY TREE<-----
    node* root=NULL;
    root=buildTree(root);
    levelOrderTraversal(root);
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3  6 9 8 -1 -1 -1 -1 -1
    cout<<"Height of binary tree "<<height(root)<<endl;

    //------->DIAMETER OF A BINARY TREE<-------
                              //O(n^2)
    // cout<<"Diameter of the binary tree is "<<diameter(root)<<endl;
                                //O(n)
    cout<<"Diameter of the binary tree is "<<diameterfast(root).first<<endl;

    //------>CHECK FOR BALANCED TREE<-------
    // if(isBalancedTree(root))          //O(n^2)
    if(isBalancedFast(root).first)          //O(n)
    cout<<"Tree is balanced"<<endl;
    else
    cout<<"Tree is not balanced"<<endl;
    //1 10 5 -1 -1 -1 39 -1 -1

    return 0;
}