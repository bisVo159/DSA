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
    if(tail==NULL){
        node* temp=new node(d);
        tail=temp;
        return;
    }
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

node* reverse(node* head){
    node* curr =head;
    node* prev=NULL;
    node* next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void insertatTail(node* &head,node* &tail,int val){
    node* temp=new node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

/*node* add(node* first,node* second){
    int carry=0;
    node* anshead=NULL;
    node* anstail=NULL;
    while(first!=NULL&&second!=NULL){
        int sum=carry+first->data+second->data;
        int digit=sum%10;
         insertatTail(anshead,anstail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }
    while(first!=NULL){
       int  sum=carry+first->data;
        int digit=sum%10;
         insertatTail(anshead,anstail,digit);
        carry=sum/10;
         first=first->next;
    }
    while(second!=NULL){
       int  sum=carry+second->data;
        int digit=sum%10;
         insertatTail(anshead,anstail,digit);
        carry=sum/10;
         second=second->next;
    }
    while(carry!=0){
        int sum=carry;
          int digit=sum%10;
         insertatTail(anshead,anstail,digit);
        carry=sum/10;
    }
    return anshead;
}*/

//using single loop
node* add(node* first,node* second){
    int carry=0;
    node* anshead=NULL;
    node* anstail=NULL;
while(first!=NULL||second!=NULL||carry!=0){
    int val1=0;
    int val2=0;
    if(first!=NULL)
    val1=first->data;
    if(second!=NULL)
    val2=second->data;
    int sum=carry+val1+val2;
        int digit=sum%10;
         insertatTail(anshead,anstail,digit);
        carry=sum/10;
        if(first!=NULL)
        first=first->next;
        if(second!=NULL)
        second=second->next;
}
return anshead;
    }


node* addTwoLists(node* first,node* second){
    //step1 -> reverse input LL
         first=reverse(first);
         second=reverse(second);

         //step2 -> add 2 LL
         node* ans=add(first,second);

         //step3
        return ans=reverse(ans);
}

int main(){
 node *node1 = new node(4); 
 node *head1 = node1;
node *tail1 = node1;
insertAtTail(tail1, 5);
print(head1);

node *node2 = new node(3) ;
node *head2 = node2;
node *tail2 = node2;
insertAtTail(tail2, 4);
insertAtTail(tail2, 5);
   print(head2);

   node*add= addTwoLists(head1,head2);
   cout<<"Addition of two Linked Lists ";
   print(add);
    return 0;
}