#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void insertAtTail(node *&tail, int d)
{
    // new node create
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseLinkedList(node* &head){
    if(head==NULL||head->next==NULL){
        return ;
    }
   else{
    node* prev=NULL;
    node* curr=head;
    while(curr!=NULL){
        node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    head= prev;
   }
}
//Recurrsive solution of reverseLinkedlist
void reverse(node* &head,node* curr,node* prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        reverse(head,curr->next,curr);
        curr->next=prev;
}

node* reverse2(node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
   node* chotahead= reverse2(head->next);
   head->next->next=head;
   head->next=NULL;
   return chotahead;
}

int getLength(node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}

node* getMiddle(node* &head){
    if(head==NULL||head->next==NULL)
    return head;
    // if(head->next->next==NULL)
    // return head->next;

    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
        fast=fast->next;
        }
        slow=slow->next;
        }
    return slow;
}

node*  reverseKgroups(node* &head,int k){
       if(head==NULL)
        return NULL;
       //step1: reverse first k nodes
       node* next=NULL;
       node* curr=head;
       node* prev=NULL;
       int count=0;
       while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
       }

       //step2:recursion dekhlega aage ka
       if(next!=NULL){
          head->next=reverseKgroups(next,k);
       }
       //step3:return head of reversed list
       return prev;
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
    node*  node1=new node(10);
    node* head=node1;
    node* tail=node1;
    // print(head);
    // insertAtTail(tail,11);
    // print(head);
    // insertAtTail(tail,12);
    // print(head);
    // insertAtTail(tail,13);
    // print(head);
    // insertAtTail(tail,14);
    // print(head);
    // insertAtTail(tail,15);
    // print(head);

//------>CHECK CIRCULAR LL<------
    // node* tail=NULL;
    if(iscircularList(tail))
    cout<<"Linked List is circular in nature"<<endl;
    else{
        cout<<"Linked List is not circular"<<endl;
    }

//---->REVERSE A LINKED LIST<-----
    /*reverseLinkedList(head);
    print(head);*/
//USING RECURRSION
  /* node* curr=head;
    node* prev=NULL;                 //HW: reverse DLL
    reverse(head,curr,prev);
    print(head);*/

//    node* rev= reverse2(head);
//     print(rev);

//----->MIDDLE OF A LL<------
/*int len=getLength(head);
int ans=len/2+1;
node* temp=head;
int cnt=1;
while(cnt<ans){
    temp=temp->next;
    cnt++;
}
cout<<"middile of the linked list "<<temp->data<<endl;*/

//more optimised
// cout<<"middle of the linked list "<<getMiddle(head)->data<<endl;

//----->REVERSE LL IN K GROUP<-------
// node* revKgrp=reverseKgroups(head,3);
// print(revKgrp);

    return 0;
}