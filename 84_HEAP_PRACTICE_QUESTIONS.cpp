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
void inorder(node* root,vector<int>&in){
    if( root==NULL)
    return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
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
void heapify(vector<int>&arr,int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[largest]<arr[left]){
        largest=left;
    }
    if(right<n&&arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
       heapify(arr,n,largest);
    }
}

vector<int> mergeHeaps(vector<int>&a,vector<int>&b,int n,int m){
    //step1 : merge both heaps into one
    vector<int>ans;
    for(auto i:a)
    ans.push_back(i);
    for(auto i:b)
    ans.push_back(i);

    //step2 : build heap using merged array
    for(int i=(n+m)/2-1;i>=0;i--)
    heapify(ans,n+m,i);

    return ans;
}

int minCost(int arr[],int n){
    //create a minHeap
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++)
    pq.push(arr[i]);

    int cost=0;
    while(pq.size()>1){
        int a=pq.top();
        pq.pop();
        int b=pq.top();
        pq.pop();
        int sum=a+b;
        cost+=sum;
        pq.push(sum);
    }
    return cost;
}

void BSTtoMinHeap(node* &root,int &i,vector<int>in){
        if(root==NULL)
        return;

        root->data=in[i++];
        BSTtoMinHeap(root->left,i,in);
        BSTtoMinHeap(root->right,i,in);
}

int main(){
    // ----->MERGE TWO BINARY MAX HEAPS<-----
   /* vector<int>a={10,5,6,2};
    vector<int>b={12,7,9};
    vector<int>ans=mergeHeaps(a,b,a.size(),b.size());
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;*/

    // ----->MINIMUM COST OF ROPES<-----
    /*int arr[4]={4,3,2,6};
    cout<<"Minimum cost to connect the ropes is "<<minCost(arr,4)<<endl;*/

    // ----->CONVERT BST(CBT) TO MINHEAP(L<R)<-----
    node* root=NULL;
    takeInput(root);
    //4 2 1 3 6 5 7 -1
    levelOrderTraversal(root);
    vector<int>in;
    inorder(root,in);
    int i=0;
    BSTtoMinHeap(root,i,in);
    levelOrderTraversal(root);

    return 0;
}