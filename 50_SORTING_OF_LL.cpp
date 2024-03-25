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

node* sortList(node* head){
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;
    node* temp=head;
    while(temp!=NULL){
      if(temp->data==0)
      zeroCount++;
     else if(temp->data==1)
      oneCount++;
     else if(temp->data==2)
      twoCount++;
      temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(zeroCount!=0){
            temp->data=0;
            zeroCount--;
        }
        else if(oneCount!=0){
            temp->data=1;
            oneCount--;
        }
        else if(twoCount!=0){
            temp->data=2;
            twoCount--;
        }
        temp=temp->next;
    }
    return head;
}

node* sortList2(node* head){
    node* zeroHead=new node(-1);
    node* zeroTail=zeroHead;
    node* oneHead=new node(-1);
     node* oneTail=oneHead;
    node* twoHead=new node(-1);
     node* twoTail=twoHead;

     node* curr=head;
     // create separate list 0s,1s,2s
     while(curr!=NULL){
        int value=curr->data;
        if(value==0){
            insertAtTail(zeroTail,value);
        }
         else if(value==1){
            insertAtTail(oneTail,value);
        }
         else if(value==2){
            insertAtTail(twoTail,value);
        }
        curr=curr->next;
     }
     //merge 3 sublist
     if(oneHead->next!=NULL){
        zeroTail->next=oneHead->next;
     }
     else{
        //1s list empty
        zeroTail->next=twoHead->next;
     }
     oneTail->next=twoHead->next;
     twoTail->next=NULL;
     //set head
     head=zeroHead->next;

     //delete dummynode
     delete zeroHead;
     delete oneHead;
     delete twoHead;
     return head;
}

node* solve(node* first,node* second){
    node* curr1=first;
    node* next1=curr1->next;
    node* curr2=second;
    while(next1!=NULL&&curr2!=NULL){
        if(curr2->data>=curr1->data&&curr2->data<=next1->data){
            //add node in between node of first list
            curr1->next=curr2;
            node* next2=curr2->next;
            curr2->next=next1;
            //update pointers
            curr1=curr2;
            curr2=next2;
        }
        else{
            //curr1 and next1 ko aage badane padega
            curr1=next1;
            next1=next1->next;
        }
        }
          if(next1==NULL){
        curr1->next=curr2;
        return first;
    }
    return first;
}

node* sortTwoList(node* first,node* second){
if(first==NULL)
return second;
if(second==NULL)
return first;
if(first->data<=second->data){
 return solve(first,second);
}
else{
 return solve(second,first);
}
}

int main(){
//  node *node1 = new node(1); 
//  node *head = node1;
// node *tail = node1;
//   insertAtTail(tail, 0);
//   insertAtTail(tail, 2);
//   insertAtTail(tail, 1); 
//    insertAtTail(tail, 2);
//    print(head);

   //----->SORT LL OF 0s 1s 2s<-------
//    node* sortlist=sortList(head);
//    print(sortlist);

//----->NOT REPLACING DATA<-----
// node* sortlist=sortList2(head);
//     print(sortlist);

//----->MERGE TWO SORTED LIST<-----
 node *node1 = new node(1); 
 node *head1 = node1;
node *tail1 = node1;
insertAtTail(tail1, 3);
insertAtTail(tail1, 5);
print(head1);

node *node2 = new node(2); 
node *head2 = node2;
node *tail2 = node2;
insertAtTail(tail2, 4);
insertAtTail(tail2, 5);
   print(head2);

   node* mergeSort=sortTwoList(head1,head2);
   cout<<"merged list ";
   print(mergeSort);
    return 0;
}