#include<iostream>
#include<vector>
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

vector<int> ZigZagtraversal(node* root){
    vector<int>result;
    if(root==NULL)
    return result;

    queue<node*>q;
    q.push(root);
    bool leftToright=true;
    while(!q.empty()){
        int size=q.size();
        vector<int>ans(size);
        // level process      
        for(int i=0;i<size;i++){
            node* frontNode=q.front();
            q.pop();
            //normal insert or reverse insert
            int index=leftToright?i:size-i-1;
            ans[index]=frontNode->data;

            if(frontNode->left)
            q.push(frontNode->left);
            if(frontNode->right)
            q.push(frontNode->right);
        }
        //direction change karna hain
        leftToright=!leftToright;
        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;
}

void traverseLeft(node* root,vector<int>&ans){
    //  base case
    if((root==NULL)||(root->left==NULL&&root->right==NULL))
    return;

    ans.push_back(root->data);
    if(root->left)
    traverseLeft(root->left,ans);
    else
    traverseLeft(root->right,ans);
}

void traverseLeaf(node* root,vector<int>&ans){
    // base case
    if(root==NULL)
    return;

    if(root->left==NULL&&root->right==NULL){
    ans.push_back(root->data);
    return;
    }

    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(node* root,vector<int>&ans){
        //  base case
    if((root==NULL)||(root->left==NULL&&root->right==NULL))
    return;

    if(root->right)
    traverseRight(root->right,ans);
    else
        traverseRight(root->left,ans);

      ans.push_back(root->data);

}

vector<int> boundary(node* root){
      vector<int>ans;
      if(root==NULL)
      return ans;

      ans.push_back(root->data);
    //   left part store
    traverseLeft(root->left,ans);

    // leaf part store
    // left subtree
    traverseLeaf(root->left,ans);
    // right subtree
    traverseLeaf(root->right,ans);

    // traverse right part
    traverseRight(root->right,ans);

    return ans;
}

vector<int> verticalOrder(node* root){
    map<int,map<int,vector<int>>>nodes;
    queue<pair<node*,pair<int,int>>>q;
    vector<int>ans;

    if(root==NULL)
    return ans;
    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty()){
        pair<node*,pair<int,int>>temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        nodes[hd][lvl].push_back(frontNode->data);
        if(frontNode->left)
        q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
    }
    for(auto i:nodes){
        for(auto j:i.second){
                 for(auto k:j.second){
                    ans.push_back(k);
                 }
        }
    }
    return ans;
}

int main(){
    //----->ZIG-ZAG TRAVERSAL<-----
      node* root=NULL;
    root=buildTree(root);
     //1 10 5 -1 -1 -1 39 -1 -1
   /* vector<int>a=ZigZagtraversal(root);
    for(auto i:a)
    cout<<i<<" ";
    cout<<endl;*/

    //------>BOUNDARY TRAVERSAL<-------
   /* vector<int>ans=boundary(root);
    cout<<"Boundary nodes of binary tree"<<endl;
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;*/
    //1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1

    //------>VERTICAL TRAVERSAL<------
    vector<int>ans=verticalOrder(root);
    cout<<"vertical traversal of binary tree : ";
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1
    
    return 0;
}