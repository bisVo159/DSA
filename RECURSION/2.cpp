#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory free fornode with data "<<value<<endl;
    }
};
void insertAtHead(node *&head, int d)
{
    // new node create
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(node *&tail, int d)
{
    // new node create
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(node* &head,int position ,int d,node* &tail){
    //Insert at the start
    if(position==1){
        insertAtHead(head,d);
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
        insertAtTail(tail,d);
        return;
    }
    //creating a node for d
    node* nodeToinsert=new node(d);
       nodeToinsert->next=temp->next;
    temp->next=nodeToinsert;
}

void deleteNode(int position,node* &head){
    //Deleting start node
    if(position==1){
        node* temp=head;
         head=head->next;
         //memory free of start node
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
           prev->next=curr->next;
           curr->next=NULL;
           delete curr;
    }
}

void KthNodeFromEnd(node* head,int& k){
    if(head==NULL)
    return;

    KthNodeFromEnd(head->next,k);
    k=k-1;
    if(k==0)
    cout<<"kth node from end "<<head->data<<endl;
}

node* kGroupReverse(node* head,int k){
    if(head==NULL)
    return NULL;

    int count=0;
    node* curr=head;
    node* next=NULL;
    node* prev=NULL;
    while(curr!=NULL&&count<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        count++;
    }
    if(next!=NULL)
    head->next=kGroupReverse(next,k);

    return prev;
}

void print(node* root){
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    print(root->next);
}

node* reverse(node* head){
    if(head==NULL||head->next==NULL)
    return head;

    node* chotahead=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return chotahead;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    node* root=new node(5);
    head=tail=root;
    insertAtTail(tail,4);
    insertAtTail(tail,1);
    insertAtTail(tail,3);
    insertAtTail(tail,2);
    insertAtTail(tail,6);
    print(root);cout<<endl;

    // Print kth node from the end
    int k=4;
    // KthNodeFromEnd(head,k);

    // reverse LL
    // node* reverseLL=reverse(head);
    // print(reverseLL);

    // reverse k group
    print(kGroupReverse(head,2));
    
    return 0;
}