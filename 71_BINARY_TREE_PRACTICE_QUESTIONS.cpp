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

vector<int> vertical(node* root){
    map<int,vector<int>>nodes;
    queue<pair<node*,int>>q;
    vector<int>ans;

    q.push(make_pair(root,0));
    while(!q.empty()){
         pair<node*,int>frontNode=q.front();
        q.pop();
        int hd=frontNode.second;
        nodes[hd].push_back(frontNode.first->data);
        if(frontNode.first->left)
        q.push(make_pair(frontNode.first->left,hd-1));
        if(frontNode.first->right)
        q.push(make_pair(frontNode.first->right,hd+1));
    }
    for(auto i:nodes){
        for(auto j:i.second){
            ans.push_back(j);
        }
    }
    return ans;
}

vector<int> topview(node *root){
    vector<int>ans;
    if(root==NULL)
    return ans;

    map<int,int>topNode;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int>temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second;

        // if 1 value is present for a horizental distance then do nothing
        if(topNode.find(hd)==topNode.end())
        topNode[hd]=frontNode->data;
        if(frontNode->left)
        q.push(make_pair(frontNode->left,hd-1));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,hd+1));
    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}
vector<int> buttomview(node *root){
    vector<int>ans;
    if(root==NULL)
    return ans;

    map<int,int>buttomNode;
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node*,int>temp=q.front();
        q.pop();
        node* frontNode=temp.first;
        int hd=temp.second;
        buttomNode[hd]=frontNode->data;
        if(frontNode->left)
        q.push(make_pair(frontNode->left,hd-1));
        if(frontNode->right)
        q.push(make_pair(frontNode->right,hd+1));
    }
    for(auto i:buttomNode){
        ans.push_back(i.second);
    }
    return ans;
}

void solve2(node* root,vector<int>&ans,int level){
    //base case
    if(root==NULL)
    return;

    // we enter into a new level
    if(level==ans.size())
    ans.push_back(root->data);

    solve2(root->right,ans,level+1);
    solve2(root->left,ans,level+1);
}

vector<int> rightView(node* root){
    vector<int>ans;
    solve2(root,ans,0);
    return ans;
}
void solve(node* root,vector<int>&ans,int level){
    //base case
    if(root==NULL)
    return;

    // we enter into a new level
    if(level==ans.size())
    ans.push_back(root->data);

    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> leftView(node* root){
    vector<int>ans;
    solve(root,ans,0);
    return ans;
}

int main(){
    node* root=NULL;
    root=buildTree(root);
    // ------>VERTICALORDER TRAVERSAL<------
   /* vector<int>ans=vertical(root);
    cout<<"vertical traversal of binary tree : ";
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;*/
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 8 -1 -1 7 -1 9 -1 -1

    // ----->TOP VIEW OF BINARY TREE<-----
    /* vector<int>tv=topview(root);
     cout<<"top view of a binary tree"<<endl;
    for(auto i:tv)
    cout<<i<<" ";
    cout<<endl;
    // ----->BUTTOM VIEW OF BINARY TREE<-----
     vector<int>bv=buttomview(root);
     cout<<"top view of a binary tree"<<endl;
    for(auto i:bv)
    cout<<i<<" ";
    cout<<endl;*/
    //1 2 4 -1 -1 5 -1 -1  3 6 -1 -1 7 -1 -1

    // ------>LEFT VIEW OF A BINARY TREE<------
    vector<int> lv=leftView(root);
    cout<<"left view of a binary tree"<<endl;
    for(auto i:lv)
    cout<<i<<" ";
    cout<<endl;
    //1 2 3 -1 -1 4 -1 7 -1 -1 5 -1 6 -1 8 -1 9 -1 -1
     // ------>RIGHT VIEW OF A BINARY TREE<------
    vector<int> rv=rightView(root);
    cout<<"right view of a binary tree"<<endl;
    for(auto i:rv)
    cout<<i<<" ";
    cout<<endl;

    // HW : Disgonal traversal of a binary tree
    
    return 0;
}