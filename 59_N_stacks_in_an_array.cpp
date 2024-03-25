#include<iostream>
using namespace std;

class NStack{
    int *arr;
    int *top;
    int *next;
    int n,s;
    int freespot;

    public:
    NStack(int n,int s){
        this->n=n;
        this->s=s;
        arr=new int[s];
        top=new int[n];
        next=new int[s];
        //top initialise
        for(int i=0;i<n;i++){
            top[i]=-1;
        }

        //next initialise
        for(int i=0;i<s-1;i++){
            next[i]=i+1;
        }
            //update last index to -1
            next[s-1]=-1;

            //initialize freespot
            freespot=0;
    }

    bool push(int x,int m){
        if(freespot==-1){
            return false;
        }
        //find index
        int index=freespot;
        //update freespot
        freespot=next[index];
        //insert element into array
        arr[index]=x;
        //update next
        next[index]=top[m-1];
        //update top
        top[m-1]=index;

        return true;
    }
    int pop(int m){
       if(top[m-1]==-1)
       return -1;

      int index=top[m-1];

      top[m-1]=next[index];

      next[index]=freespot;

      freespot=index;

      return arr[index];
    }
};

int main(){
    NStack s(3,6);
    s.push(10,1);
    s.push(11,1);
    s.push(12,3);
    s.push(13,2);
    s.push(14,3);
    s.push(15,1);
    cout<<s.pop(1)<<" ";
    cout<<s.pop(3)<<" ";
    // cout<<s.pop(3)<<" ";
    // cout<<s.pop(1)<<" ";
    // cout<<s.pop(2)<<" ";
    
    return 0;
}