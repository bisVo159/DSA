#include<iostream>
#include<map>
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
    ~node(){
        cout<<"deleting node for data "<<this->data<<endl;
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

node* uniqueSortedList(node* head){
    if(head==NULL||head->next==NULL)
    return head;
   
   node* curr=head;
   while(curr->next!=NULL){
    if(curr->next->data==curr->data){
        node* next_next=curr->next->next;
       node* nodeToDelete=curr->next;
       nodeToDelete->next=NULL;
       delete(nodeToDelete);
        curr->next=next_next;    }
    else{
        curr=curr->next;
    }
   }
   return head;
}

node* unsortedList(node* head){
    node* curr=head;
    while(curr!=NULL){
        node* prev=curr;
        node* temp=curr->next;
        while(temp!=NULL){
            if(temp->data==curr->data){
                 node* temp_next=temp->next;
                 prev->next=temp_next;
                 temp->next=NULL;
                 delete temp;
                 temp=temp_next;
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        curr=curr->next;
        }   
        return head;
    }

    void unsortedList2(node* head){
        node* prev;
        node* temp=head;
        map<int,bool>visited;
         while(temp!=NULL){
            if(visited[temp->data]==true){
                node* temp_next=temp->next;
                  prev->next=temp->next;
                  temp->next=NULL;
                  delete temp;
                  temp=temp_next;
            }
            else{
                visited[temp->data]=true;
                prev=temp;
                temp=temp->next;
            }
         }
    }
int main(){
    //------>REMOVE DUPLICATES FROM A SORTED LL<------
     node *node1 = new node(1); 
   node *head = node1;
    node *tail = node1;
//     insertAtTail(tail, 2);
//     insertAtTail(tail, 2);
//     insertAtTail(tail, 3);
//     insertAtTail(tail, 3);
//     insertAtTail(tail, 3);
//     insertAtTail(tail, 3);
//     insertAtTail(tail, 4);
//     print(head);

// node* x=uniqueSortedList(head);
//      print(x);

    insertAtTail(tail, 4);
    insertAtTail(tail, 2);
    insertAtTail(tail, 5);
    insertAtTail(tail, 4);
    insertAtTail(tail, 2);
    insertAtTail(tail, 2);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6);
    insertAtTail(tail, 6);

//---->DELETE DUPLICATES FROM AN UNSORTED LL<------
    //  node* y=unsortedList(head);
    //  print(y);

unsortedList2(head);
print(head);

//HW:split a circular LL into 2 halves
    return 0;
}