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
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* merge(node* left,node* right){
    if(left==NULL)
    return right;

    if(right==NULL)
    return left;

    node* ans=new node(-1);
    node* temp=ans;
    //merge 2 sorted LL
    while(left!=NULL&&right!=NULL){
        if(left->data<right->data){
             temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
          temp->next=right;
          temp=right;
          right=right->next;
        }
    }
    while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
    }
    while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
    }
   
    ans=ans->next;
    return ans;
}

node* findMid(node* head){
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* mergeSort(node* head){
    if(head==NULL||head->next==NULL)
    return head;
    
    //break LL into two halves
    node* mid=findMid(head);
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;

   //recursive call to sort both halves
     left=mergeSort(left);
     right=mergeSort(right);

     //merge both left and right halves
     node* result=merge(left,right);
     return result;
}

int main(){
node *node1 = new node(3); 
 node *head = node1;
node *tail = node1;
  insertAtTail(tail, 5);
  insertAtTail(tail, 1);
  insertAtTail(tail, 2); 
   insertAtTail(tail, 9);
   node* mergesort=mergeSort(head);
   print(mergesort);

//    Flatten a LL
    
    return 0;
}