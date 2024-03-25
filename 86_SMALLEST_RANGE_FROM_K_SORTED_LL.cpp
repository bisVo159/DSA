#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;

    node(int d,int r,int c){
        data=d;
        row=r;
        col=c;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data>b->data;
    }
};

int Ksorted(vector<vector<int>>&a,int k,int n){
    int mini=INT_MAX,maxi=INT_MIN;
    priority_queue<node*,vector<node*>,compare>minHeap;

    //step1: create minHeap for starting element of each list and tracking mini/maxi value
    for(int i=0;i<k;i++){
        int element=a[i][0];
        mini=min(mini,element);
        maxi=max(maxi,element);
        minHeap.push(new node(element,i,0));
    }

    int start=mini,end=maxi;

    //step2 : process ranges
    while(!minHeap.empty()){
        node* tmp=minHeap.top();
        minHeap.pop();
        mini=tmp->data;

        if(maxi-mini<end-start){
            start=mini;
            end=maxi;
        }

        //next element exists
        if(tmp->col+1<n){
            maxi=max(maxi,a[tmp->row][tmp->col+1]);
            minHeap.push(new node(a[tmp->row][tmp->col+1],tmp->row,tmp->col+1));
        }
        else{
            //next element does not exists
            break;
        }
    }
    return (end-start+1);
}

int signam(int a,int b){
    if(a==b)
    return 0;
    else if(a>b)
    return 1;
    else
    return -1;
}

void callMedian(int element,priority_queue<int>&maxi,priority_queue<int,vector<int>,greater<int>>&mini,int &median){
    switch (signam(maxi.size(),mini.size()))
    {
    case 0: if(element>median){
        mini.push(element);
        median=mini.top();
    }
    else{
        maxi.push(element);
        median=maxi.top();
    }
        break;

    case 1: if(element>median){
        mini.push(element);
        median=(mini.top()+maxi.top())/2;
        }
        else{
            mini.push(maxi.top());
            maxi.pop();
            maxi.push(element);
            median=(mini.top()+maxi.top())/2;
        }
        break;
    case -1:if(element>median){
        maxi.push(mini.top());
        mini.pop();
        mini.push(element);
        median=(mini.top()+maxi.top())/2;
    }
        else{
            maxi.push(element);
            median=(mini.top()+maxi.top())/2;
        }
        break;
    }
}

vector<int> findMedian(vector<int>&arr,int n){
    vector<int>ans;
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    int median=0;

    for(int i=0;i<n;i++){
        callMedian(arr[i],maxheap,minheap,median);
        ans.push_back(median);
    }
    return ans;
}

int main(){
    // ----->SMALLEST RANGE IN K SORTED ARRAY<-----
    vector<vector<int>>arr={{1,10,5},{2,3,20},{5,6,12}};
    cout<<"Smallest in K sorted array "<<Ksorted(arr,3,3)<<endl;

    // ----->MEDIAN IN A STREAM<-----
    vector<int>a={1,2,3};
    vector<int>ans=findMedian(a,3);
    cout<<"Medians in a stream "<<" : ";
    for(auto i:ans)
    cout<<i<<" ";
    cout<<endl;
    //HW : leetcode -> reorgemise stream
    
    return 0;
}