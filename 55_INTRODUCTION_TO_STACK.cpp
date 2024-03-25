#include<iostream>
// #include<stack>
using namespace std;

class stack{
    public:
    int *arr;
    int top;
    int size;
    //constructor
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int element){
         if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }
    }
    void pop(){
          if(top>=0){
               top--;
          }
          else{
                cout<<"Stack underflow"<<endl;
          }
    }
    int peck(){
        if(top>=0)
           return arr[top];
           else{
           cout<<"Stack is empty"<<endl;
           return -1;
           }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

class TwoStack{
    public:
    int* arr;
    int top1;
    int top2;
    int size;

    TwoStack(int s){
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }
    //push in stack 1
    void push1(int num){
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    //push in stack 2
    void push2(int num){
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
        else{
            cout<<"stack overflow"<<endl;
        }
    }
    int pop1(){
         if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
         }
         else{
            return -1;
         }
    }
    int pop2(){
         if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
         }
         else{
            return -1;
         }
    }
};

int main(){
  /*  // creation of stack
    stack<int>s;

    // push operation
    s.push(2);
    s.push(3);

    // pop operation
    s.pop();

    cout<<"printing top element "<<s.top()<<endl;
    if(s.empty())
    cout<<"Stack is empty "<<endl;
    else
    cout<<"Stack is not empty"<<endl;

    cout<<"Size of stack is  "<<s.size()<<endl;*/

   /* stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);
 
     cout<<st.peck()<<endl;

    st.pop();
     cout<<st.peck()<<endl;
    st.pop();
     cout<<st.peck()<<endl;
    st.pop();
     cout<<st.peck()<<endl;
     if(st.isEmpty()){
         cout<<"Stack is empty"<<endl;
     }
     else{
        cout<<"Stack is not empty"<<endl;
     }*/

     //Two stacks in an array
     TwoStack s(5);
     s.push1(1);
     s.push1(2);
     s.push1(3);
     s.push2(4);
     s.push2(5);
 
    cout<<s.pop1()<<" ";
    cout<<s.pop1()<<" ";
    cout<<s.pop2()<<" ";
   cout<< s.pop2()<<" ";
    return 0;
}