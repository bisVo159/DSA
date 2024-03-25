#include <iostream>
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
    //destructor
    ~node(){
        int value=this->data;
        //memory free
       /* if(this->next!=NULL){
            delete next;
               this-> next=NULL;
        }*/
        cout<<" memory is free for node with data "<<value<<endl;
    }
};
// Insertion
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

int main()
{

    // created a new node
    node *node1 = new node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // head pointed to node1
    node *head = node1;
    print(head);
//----->INSERT AT HEAD<------
    //    insertAtHead(head,12);
    //       print(head);
    // insertAtHead(head,15);
    //    print(head);
//---->INSERT AT TAIL<-----
    node *tail = node1;
    insertAtTail(tail, 12);
    print(head);
    insertAtTail(tail, 15);
    print(head);

    //----->INSERT AT MIDDLE<------
     insertAtPosition(head,4,22,tail);
     print(head);

     cout<<"head "<<head->data<<endl;
     cout<<"tail "<<tail->data<<endl;

     //----->DELETION OF LINKLIST<-------
    deleteNode(3,head);
     print(head);
      cout<<"head "<<head->data<<endl;
     cout<<"tail "<<tail->data<<endl;        //HW while deleting last node
    return 0;
}