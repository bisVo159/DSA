#include<iostream>
#include<queue>
using namespace std;

class Dqueue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Dqueue(int n){
        size=n;
        arr=new int[n];
        front=-1;
        rear=-1;
    }

    bool pushFront(int x){
        //check full or not
        if((front==0&&rear==size-1)||(rear==(front-1)%(size-1)))
        return false;
        else if(front==-1){
            front=rear=0;
        }
        else if(front==0){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=x;
        return true;
    }

    bool pushRear(int x){
            //check full or not
        if((front==0&&rear==size-1)||(rear==(front-1)%(size-1)))
        return false;
        else if(front==-1){
            front=rear=0;
        }
        else if(rear==size-1 && front !=0){
           rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=x;
        return true;
    }

    bool popFront(){
       if(front==-1){
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

    bool popRear(){
           if(front=-1){
        cout<<"queue is empty"<<endl;
        return -1;
       }
       int ans=arr[rear];
       arr[rear]=-1;
       if(front==rear){
        front=rear=-1;
       }
       else if(rear==0){
           rear=size-1;
       }
       else{
        rear--;
       }
       return ans;
    }

    int getFront(){
        if(isEmpty())
        return -1;
        return front;
    }
    int getRear(){
        if(isEmpty())
        return -1;
        return rear;
    }

    bool isEmpty(){
        if(front==-1)
        return true;
        return false;
    }

    bool isFull(){
        if((front==0&&rear==size-1)||(front!=0&&rear==(front-1)%(size-1)))
        return true;
        return false;
    }
};

int main(){
    
        //---->STL FOR DOUBLY ENDED QUEUE<------
        /*deque<int>d;
        d.push_front(12);
        d.push_back(14);
        cout<<d.front()<<endl;
        cout<<d.back()<<endl;
        d.pop_front();
        cout<<d.front()<<endl;
        cout<<d.back()<<endl;
        d.pop_back();
        if(d.empty()){
            cout<<"queue is empty"<<endl;
        }*/
    
    return 0;
}