#include<iostream>
#include<queue>
using namespace std;

class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;
    public:
    Queue(){
        size=100001;
        arr=new int[size];
        qfront=0;
        rear=0;
    }
    //push
    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
    //pop
    int dequeue(){
        if(qfront==rear)
        return -1;

        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
    }

    int front(){
        if(qfront==rear)
        return -1;
        else
            return arr[qfront];
    }
    bool isEmpty(){
        if(qfront==rear)
        return true;
        return false;
    }
};

class CircularQueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    CircularQueue(int n){
        size=n;
        arr=new int[size];
        front=rear=-1;
    }

    bool Enqueue(int value){
        if((front==0&&rear==size-1)||(rear==(front-1)%(size-1))){
            cout<<"Queue is full"<<endl;
            return false;
        }
        else if(front==-1){       //first element to push
                 front=rear=0;
        }
        else if(rear==size-1 && front !=0){
                rear=0;
        }
        else{
            rear++;
        }
     arr[rear]=value;
     return true;
    }
    //pop
    int deQueue(){
    if(front==-1){        //to check queue is empty
            cout<<"queue is empty"<<endl;
            return -1;
        }

       int ans=arr[front];
       arr[front]=-1;
        if(front==rear){      //single element is present
           front=rear=-1;
        }
        else if(front==size-1){
            front=0;        //to maintain cyclic nature
        }
        else{
            front++;      //normal flow
            }
            return ans;
    }
};

int main(){
    //create a queue
    /*queue<int>q;
    q.push(11);
    q.push(15);
    q.push(13);
    cout<<"front of queue is :"<<q.front()<<endl;
    cout<<"SIze of queue is  :"<<q.size()<<endl;
    q.pop();
    cout<<"front of queue is :"<<q.front()<<endl;
        cout<<"SIze of queue is  :"<<q.size()<<endl;
        if(q.empty()){
            cout<<"queue is empty"<<endl;
        }
        else{
            cout<<"queue is not empty"<<endl;
        }*/


        //------->IMPLEMENT A QUEUE USING ARRAY<-------
       /* Queue q;
        q.enqueue(1);
        q.enqueue(5);
        q.enqueue(7);
        q.enqueue(8);
        q.enqueue(12);
        cout<<q.front()<<endl;
        cout<<q.dequeue()<<endl;
        cout<<q.front()<<endl;
        cout<<q.isEmpty()<<endl;*/

        //-------->CIRCULAR QUEUE<-------
        /* CircularQueue cq(5);
         cq.Enqueue(1);
         cq.Enqueue(2);
         cq.Enqueue(3);
         cq.Enqueue(4);
         cq.Enqueue(5);
        cout<< cq. deQueue()<<endl;
        cout<< cq. deQueue()<<endl;
        cout<< cq. deQueue()<<endl;
           cq.Enqueue(5);
         cout<< cq. deQueue()<<endl;*/

    return 0;
}