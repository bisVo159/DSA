#include<iostream>
#include<stack>
using namespace std;

class specialStack{
    stack<int>s;
   int  mini;
   public:
   void push(int data){
    //for first element
    if(s.empty()){
        s.push(data);
        mini=data;
    }
    else{
        if(data<mini){
            s.push(2*data-mini);
            mini=data;
        }
        else{
            s.push(data);
        }
    }
   }

   int pop(){
    if(s.empty()){
        return -1;
    }
    int curr=s.top();
    s.pop();
    if(curr>mini){
        return curr;
    }
    else{
        int prevMin=mini;
        int val=2*mini-curr;
        mini=val;
        return prevMin;
    }
   }

   int top(){
    if(s.empty()){
        return -1;
    }
    int curr=s.top();
    if(curr<mini){
        return mini;
    }
    else{
        return curr;
    }
   }

    bool isEmpty(){
        return s.empty();
    }

    int getMini(){
        if (s.empty())
        return -1;

        return mini;
    }
   
};

int main(){
    //---->DESIGN A STACK THAT SUPPORTS getMin() IN O(1) TIME AND O(1) EXTRA SPACE
    specialStack stack;
    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.push(2);
    stack.push(4);
    cout<<stack.pop()<<endl;
  cout<<stack.getMini()<<endl;
    cout<<stack.pop()<<endl;
  cout<<stack.getMini()<<endl;

    return 0;
}