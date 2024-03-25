#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0]=-1;
        size=0;
    }

    void insert(int val){
        size=size+1;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parent=index/2;
            if(arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
    }
void print(){
    for(int i=1;i<=size;i++){
              cout<<arr[i]<<" ";  
        }cout<<endl;
    }

    void deletefromHeap(){
        if(size==0){
            cout<<"nothing to delete "<<endl;
            return;
        }

        //step1 : put last element into first index
        arr[1]=arr[size];
        //step2 : remove first element
        size--;

        ///take root node to its correct position
        int i=1;
        while(i<=size){
            int leftIndex=2*i;
            int rightIndex=2*i+1;

            int temp=i;
            if(leftIndex<=size&&arr[temp]<arr[leftIndex]){
                temp=leftIndex;
             }
             if(rightIndex<=size&&arr[temp]<arr[rightIndex]){
                temp=rightIndex;
             }
             if(arr[temp]>arr[i]){
                swap(arr[temp],arr[i]);
                i=temp;
             }
             else{
                return;
             }
    }
    }
};

void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&&arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n&&arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
       heapify(arr,n,largest);
    }
}
void heapifyMin(vector<int>&arr,int n,int i){
    int smallest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n&&arr[smallest]>arr[left]){
        smallest=left;
    }
    if(right<n&&arr[smallest]>arr[right]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
       heapifyMin(arr,n,smallest);
    }
}
vector<int> buildMinHeap(vector<int>&arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapifyMin(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        //step 1
        swap(arr[size],arr[1]);
        size--;
        //step2
        heapify(arr,size,1);
    }
}

int main(){
   /* heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
    // h.deletefromHeap();
    // h.print();*/

    // ----->HEAPIFY<-----
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    // ----->HEAP SORT<-----
    heapSort(arr,n);
    cout<<"Printing heap sorted array"<<endl;
    for(int i=1;i<=n;i++){
    cout<<arr[i]<<" ";
    }cout<<endl;

    // ----->BUILD MIN HEAP<-----
    // Following 0-based indexing
   /* vector<int>a={54,55,53,52,50};
    buildMinHeap(a);
    int n=a.size();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;*/

    cout<<"Using priority queue here"<<endl;
    //max heap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"element at top "<<pq.top()<<endl;
    pq.pop();
    cout<<"element at top "<<pq.top()<<endl;
    cout<<"Size is "<<pq.size()<<endl;
    if(pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }

    //min heap
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout<<"element at top "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"element at top "<<minheap.top()<<endl;
    cout<<"Size is "<<minheap.size()<<endl;
    if(minheap.empty())
        cout<<"minheap is empty"<<endl;
    else
        cout<<"minheap is not empty"<<endl;
    
    return 0;
}