#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    //constructor
    node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
             next=NULL;
        }
        cout<<"memory free for node with data "<<value<<endl;
    }
};
//traversing a linked List
 void print(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
 }
//gives length of Linked List
 int getLength(node* head){
    int len=0;
        node* temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
 }

 void insertAtHead(node* &head,node* &tail,int d){
    if(head==NULL){
            node* temp=new node(d);
            head=temp;
            tail=temp;
    }
    else{
    node* temp=new node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
 }

 void insertAtTail(node* &tail,node* &head,int d){
    if(tail==NULL){
          node* temp=new node(d);
            tail=temp;
            head=temp;
    }
    else{
    node* temp=new node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
 }

 void insertAtPosition(node* &head,int position,int d,node* &tail){
      //Insert at the start
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
        node* temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //Inserting at last position
    if(temp->next==NULL){
        insertAtTail(tail,head,d);
        return;
    }
    //creating a node for d
    node* nodeToinsert=new node(d);
       nodeToinsert->next=temp->next;
       temp->next->prev=nodeToinsert;
        temp->next=nodeToinsert;
       nodeToinsert->prev=temp;
 }

 void deleteNode(int position,node* &head){
    //Deleting start node
    if(position==1){
        node* temp=head;
        temp->next->prev=NULL;
       head=temp->next;
       temp->next=NULL;
       delete temp;
    }
    else{
        //deleting any middle or last node
           node* curr=head;
           node* prev=NULL;
           int cnt=1;
           while(cnt<position){
                 prev=curr;
                 curr=curr->next;
                 cnt++;
           }
           curr->prev=NULL;
           prev->next=curr->next;
           curr->next=NULL;
           delete curr;
    }
}
int main(){
  /*  node* node1=new node(10);
    node* head=node1;
      node* tail=node1;*/
  //  node* node1=new node(10);
    node* head=NULL;
      node* tail=NULL;
    print(head);
    //cout<<getLength(head)<<endl;

//---->INSERT AT HEAD<-----
    insertAtHead(head,tail,11);
    print(head);
    insertAtHead(head,tail,13);
    print(head);
    insertAtHead(head,tail,8);
    print(head);

    //----->INSERT AT TAIL<-----
    insertAtTail(tail,head,25);
    print(head);

//----->INSERT AT ANY POSITION<-----
    insertAtPosition(head,2,100,tail);
    print(head);
       cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    insertAtPosition(head,1,101,tail);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    /*insertAtPosition(head,8,102,tail);
    print(head);*/
    insertAtPosition(head,7,102,tail);
    print(head);

    //----->DELETION<-----
    deleteNode(7,head);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    return 0;
}