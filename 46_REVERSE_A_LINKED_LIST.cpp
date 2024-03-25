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

bool iscircularList(node* head){
    if(head==NULL)
    return true;

    node* temp=head->next;
    while(temp!=NULL&&temp!=head){
        temp=temp->next;
    }
    if(temp==head){
        return true;
    }
    return false;
}

int main(){
    //----->CHECK CIRCULAR LL<-----
        node* tail=NULL;
    
    insertNode(tail,5,3);
   // print(tail);
    insertNode(tail,3,5);
    print(tail);

    // if(iscircularList(tail))
    // cout<<"Linked List is circular in nature"<<endl;
    // else{
    //     cout<<"Linked List is not circular"<<endl;
    // }
    return 0;
}