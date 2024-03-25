#include<iostream>
#include<vector>
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

void solve(node* root,int sum,int &maxsum,int len,int &maxlen){
       //base case
       if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        else if(len==maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
       }
       sum+=root->data;
       solve(root->left,sum,maxsum,len+1,maxlen);
       solve(root->right,sum,maxsum,len+1,maxlen);
}

int sumofLongRootToLeafPath(node* root){
    int len=0;
    int maxlen=0;
    int sum=0;
    int maxsum=INT_MIN;
    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}

node* LCA(node* root,int n1,int n2){
    if(root==NULL)
    return NULL;

    if(root->data==n1||root->data==n2)
    return root;

    node * leftAns=LCA(root->left,n1,n2);
    node * rightAns=LCA(root->right,n1,n2);
    if(leftAns!=NULL&&right!=NULL)
    return root;
    else if(leftAns!=NULL&right==NULL)
    return leftAns;
    else if(leftAns==NULL&right!=NULL)
    return rightAns;
    else 
    return NULL;
}

void solveK(node* root,int k,int &count,vector<int>path){
      //base case
      if(root==NULL)
      return;
      path.push_back(root->data);
      //left
      solveK(root->left,k,count,path);
      //right
      solveK(root->right,k,count,path);
    //   check for K sum
    int size=path.size();
    int sum=0;
    for(int i=size-1;i>0;i--){
        sum+=path[i];
        if(sum==k)
        count++;
    }
    // path.pop_back();
}

int sumK(node* root,int k){
    vector<int>path;
    int count = 0;
    solveK(root,k,count,path);
    return count;
}

node* solveKth(node* root,int &k,int n){
    if(root==NULL)
    return NULL;
    if(root->data==n)
        return root;

    node* leftAns=solveKth(root->left,k,n);
    node* rightAns=solveKth(root->right,k,n);

    if(leftAns!=NULL&&rightAns==NULL){
        k--;
        if(k==0){
            // k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    else if(leftAns==NULL&&rightAns!=NULL){
        k--;
         if(k==0){
            // k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    else{
        return NULL;
    }
}

int KthAncestor(node* root,int k,int n){
      node* ans= solveKth(root,k,n);
      if(ans==NULL||ans->data==n)
      return -1;
      return ans->data;
}

pair<int,int> solveSum(node* root){
     if(root==NULL){
     pair<int,int>p=make_pair(0,0);
     return p;
     }

     pair<int,int>leftAns=solveSum(root->left);
     pair<int,int>rightAns=solveSum(root->right);

     pair<int,int>ans;
     ans.first=root->data+leftAns.second+rightAns.second;
     ans.second=max(leftAns.first,leftAns.second)+max(rightAns.first,rightAns.second);
     return ans;
}

int getMaxSum(node* root){
    pair<int,int>ans=solveSum(root);
    return max(ans.first,ans.second);
}

int main(){
    node* root=NULL;
    root=buildTree(root);
    // ----->SUM OF LONGEST BLOODLINE OF A TREE<-----
    // cout<<"sum of longest pathfrom root to leaf "<<sumofLongRootToLeafPath(root)<<endl;
    //4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1

    // ----->LOWEST COMMON ANCESTOR IN A BINARY TREE<-----
    // cout<<"Lowest common ancestor is "<<LCA(root,21,4)->data<<endl;
    //1 2 6 -1 8 -1 -1 -1 3 4 -1 -1 5 21 -1 -1 -1 

    // ------>KSUM PATHS<------
    // cout<<"Total no of K sum paths are "<<sumK(root,8);

    // ----->Kth ANCESTOR IN A TREE<-----
//     int k=2;
//    cout<<"Kth ancestor in a tree "<< KthAncestor(root,k, 8)<<endl;

// ----MAXIUM SUM OF NON-ADJACENT NODES<-----
cout<<"maximum sum of non-adjacent nodes "<<getMaxSum(root)<<endl;
//1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1 
    
    return 0;
}