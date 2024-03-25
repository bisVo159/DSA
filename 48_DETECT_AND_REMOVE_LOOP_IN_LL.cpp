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
};

void insertAtTail(node *&tail, int d)
{
    // new node create
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

bool detectLoop(node* head){
    if(head==NULL)
    return false;

    map<node*,bool>visited;
    node* temp=head;
    //cycle is present
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"Present on element "<<temp->data<<endl;
             return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
}

node* floydDetectLoop(node* head){
    if(head==NULL)
    return NULL;

    node* slow=head;
    node* fast=head;
    while(slow!=NULL&&fast!=NULL){
        fast=fast->next;
        if(fast!=NULL)
        fast=fast->next;
        slow=slow->next;
        if(slow==fast){
        return slow;
        }
    }
    return NULL;
}

node* getStartingNode(node* head){
    if(head==NULL)
    return NULL;

node* intersection=floydDetectLoop(head);
if(intersection==NULL)
return NULL;
node* slow=head;
while(slow!=intersection){
    slow=slow->next;
    intersection=intersection->next;
}
return slow;
}

void removeLoop(node* head){
    if(head==NULL)
    return;

    node* startOfLoop=getStartingNode(head);
    node* temp=startOfLoop;
    while(temp->next!=startOfLoop){
        temp=temp->next;
    }
    temp->next=NULL;
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
int main(){
 node *node1 = new node(10); 
   node *head = node1;
       node *tail = node1;
    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    insertAtTail(tail, 22);
    print(head);
    tail->next=head->next;
    cout<<"head->"<<head->data<<endl;
    cout<<"tail->"<<tail->data<<endl;
    // print(head);
    // if(detectLoop(head))
    // cout<<"cycle is present"<<endl;
    // else
    //     cout<<"no Cycle"<<endl;

//----->FLOYD CYCLE DETECTION<------
    if(floydDetectLoop(head)!=NULL)
    cout<<"cycle is present"<<endl;
    else
        cout<<"no Cycle"<<endl;

    //----->FIND STARTING NODE OF LOOP<------
    cout<<"staring node of loop "<<getStartingNode(head)->data<<endl;

    //------->REMOVE  LOOP FROM LL<-------
    removeLoop(head);
    print(head);

    return 0;
}