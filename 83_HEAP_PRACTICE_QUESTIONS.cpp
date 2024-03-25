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

int KthSmallest(int arr[],int n,int k){
    priority_queue<int>pq;
    //step1
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    //step2
    for(int i=k;i<n;i++){
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    //ans = pq.top()
    int ans=pq.top();
    return ans;
}

int countNode(node* root){
    // base case
    if(root==NULL)
    return 0;

    int ans=1+countNode(root->left)+countNode(root->right);
    return ans;
}

bool isCBT(node* root,int index,int cnt){
    if(root==NULL)
    return true;
    if(index>=cnt)
    return false;

    bool left=isCBT(root->left,2*index+1,cnt);
    bool right=isCBT(root->right,2*index+2,cnt);

    return left&&right;
}

bool ismaxOrder(node* root){
    // leaf node
    if(root->left==NULL&&root->right==NULL)
    return true;

    if(root->right==NULL)
    return root->data>root->left->data;
    else{
    bool left=ismaxOrder(root->left);
    bool right=ismaxOrder(root->right);
    return ((root->data>root->left->data)&&(root->data>root->right->data))&&(left&&right);
    }
}

bool isHeap(node* root){
    int index=0;
    int totalCount=countNode(root);
    if(isCBT(root,index,totalCount)&&ismaxOrder(root)){
        return true;
    }
    else
    return false;
}

int main(){
    // ----->Kth SMALLEST ELEMENT<-----
    int arr[5]={7,10,4,20,15};
    cout<<"Kth smallest element in the array "<<KthSmallest(arr,5,4)<<endl;

    // ----->IS BINARY TREE HEAP<-----
    //70 60 45 -1 -1 50 -1 -1 55 -1 -1
    //70 60 45 -1 -1 61 -1 -1 55 -1 -1
    node* root=buildTree(NULL);
    if(isHeap( root))
    cout<<"Binary tree is a heap"<<endl;
    else
    cout<<"BInary tree is not a heap"<<endl;
    
    return 0;
}