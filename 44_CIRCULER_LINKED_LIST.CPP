#include<iostream>
using namespace std;

class node{
    public:
     int data;
     node* next;

     //constructor
     node(int d){
          this->data=d;
          this->next=NULL;
     }
     ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
     }
};

void insertNode(node* & tail,int element,int d){
         
           if(tail==NULL){
            node* newNode=new node(d);
            tail=newNode;
            newNode->next=newNode;
           }
           else{
            //non-empty list
           //assuming that element is present in the list
           node* curr=tail;
                  while(curr->data!=element){
                         curr=curr->next;
                  }
                  //element found
                  node* temp=new node(d);
                  temp->next=curr->next;
                  curr->next=temp;
           }
}

void print(node* tail){
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
       node* temp=tail;
       do{
            cout<<tail->data<<" ";
            tail=tail->next;
       }while(tail!=temp);
       cout<<endl;
}

void deleteNode(node* &tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        //Non-empty
        node* prev=tail;
        node* curr=prev->next;
        while(curr->data!=value){
                prev=curr;
                curr=curr->next;
        }
        prev->next=curr->next;

        //1 node linked list
        if(curr==prev){
            tail=NULL;
        }
        //>=2 node linked list
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

int main(){
    node* tail=NULL;
    //insert in empty list---->element does not matter
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
   /* insertNode(tail,5,7);
    print(tail);
    insertNode(tail,7,9);
    print(tail);
    insertNode(tail,5,6);
    print(tail);
    insertNode(tail,9,10);
    print(tail);
    insertNode(tail,3,4);
    print(tail);*/
    deleteNode(tail,5);
    print(tail);
    
    return 0;
}