#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;
    node(int data ,int row,int col){
        this->data=data;
        i=row;
        j=col;
    }
};

class LL{
    public:
    int data;
    LL* next;

    LL(int data){
        this->data=data;
        next=NULL;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};

int getKthLargest(vector<int>&arr,int k){
    vector<int>sumStore;
    int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }
    sort(sumStore.begin(),sumStore.end());

    return sumStore[sumStore.size()-k];
}

int getKthLargest2(vector<int>&arr,int k){
    priority_queue<int,vector<int>,greater<int>>mini;

int n=arr.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            if(mini.size()<k){
                mini.push(sum);
            }
            else{
                if(sum>mini.top()){
                    mini.pop();
                    mini.push(sum);
                }
            }
        }
    }
    int ans=mini.top();
    return ans;
}

vector<int> mergeSortedArrays(vector<vector<int>>&arr,int k){
    priority_queue<node*,vector<node*>,compare>minHeap;
    //step1 : saare arrays ka first element insert h
    for(int i=0;i<k;i++){
        node* tmp=new node(arr[i][0],i,0);
        minHeap.push(tmp);
    }
    vector<int>ans;
    //step2
    while(minHeap.size()>0){
    node* tmp=minHeap.top();
    ans.push_back(tmp->data);
    minHeap.pop();
    int i=tmp->i;
    int j=tmp->j;
    if(j+1<arr[i].size()){
        node* next=new node(arr[i][j+1],i,j+1);
        minHeap.push(next);
    }
    }
    return ans;
}

LL* mergeKLists(vector<LL*>&arr){
    priority_queue<LL*,vector<LL*>,compare>minHeap;
    int k=arr.size();

    if(k==0)
    return NULL;

    for(int i=0;i<k;i++){
        if(arr[i]!=NULL){
            minHeap.push(arr[i]);
        }
    }

    LL* head=NULL;
    LL* tail=NULL;
    while(minHeap.size()>0){
        LL* top=minHeap.top();
        minHeap.pop();

        if(top->next!=NULL){
            minHeap.push(top->next);
        }

        //answer LL is empty
        if(head==NULL){
            head=top;
            tail=top;
        }
        else{//insert at Linked List
            tail->next=top;
            tail=top;
            }
    }
    return head;
}

int main(){
    // ----->Kth LARGEST SUM SUBARRAY<-----
    vector<int>arr={1,2,6,4,3};
    // cout<<"Kth largest sum subarray "<<getKthLargest(arr,3)<<endl;
    // ----->Approach 2<-----
    cout<<"Kth largest sum subarray "<<getKthLargest2(arr,3)<<endl;

    // ----->MERGE K SORTED ARRAYS<-----
    vector<vector<int>>a={{1,4,7},{2,5,8},{3,6,9}};

    vector<int>ans=mergeSortedArrays(a,3);
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;

    // ----->MERGE K SORTED LINKED LIST<-----
    
    return 0;
}