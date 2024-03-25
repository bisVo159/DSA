#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *random;

    // constructor
    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random=NULL;
    }
};
void insertAtTail(node* &head,node *&tail, int d)
{
      node* newnode=new node(d);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    else{
    tail->next = newnode;
    tail = newnode;
    }
}
// void insertAtRandom(node* &head){
//     node* temp=head;
//     temp->random=temp->next->next;
//     temp->next->random=temp;
//     temp->next->next->random=temp->next->next->next;
// }
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

node *copyList(node* head){
    // step1: create a clone list
    node* cloneHead=NULL;
    node* cloneTail=NULL;

    node* temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }
    // step2:create a map
   unordered_map<node*,node*>oldTonewnode;
   node* originalnode=head;
   node* clonenode=cloneHead;
   while(originalnode!=NULL){
     oldTonewnode[originalnode]=clonenode;
     originalnode=originalnode->next;
     clonenode=clonenode->next;
   }
originalnode=head;
clonenode=cloneHead;

while(originalnode!=NULL){
clonenode->random=oldTonewnode[originalnode->random];
   originalnode=originalnode->next;
     clonenode=clonenode->next;
}
return cloneHead;
}

node* copyList2(node* head){
    //step1: create a cloneList
    node* cloneHead=NULL;
    node* cloneTail=NULL;
    node* temp=head;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp=temp->next;
    }

    //step2: clonenodes add in between originalList
    node* originalnode=head;
    node* clonenode=cloneHead;

    while(originalnode!=NULL&&clonenode!=NULL){
          node* next=originalnode->next;
          originalnode->next=clonenode;
          originalnode=next;

          next=clonenode->next;
          clonenode->next=originalnode;
          clonenode=next;
    }

    //step3: random pointer copy
     temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            temp->next->random=temp->random?temp->random->next:temp->random;
            // if(temp->random!=NULL){
            //     temp->next->random=temp->random->next;
            // }
            // else{
            //     temp->next->random=temp->random;
            // }
        }
        temp=temp->next->next;
    }

    //step4: revert changes in step 2
    originalnode=head;
    clonenode=cloneHead;
    while(originalnode!=NULL&&clonenode!=NULL){
        originalnode=clonenode->next;
        originalnode=originalnode->next;

         if(originalnode!=NULL){
        clonenode=originalnode->next;
         }
        clonenode=clonenode->next;
    }
    //step5: return ans
return cloneHead;
}

int main(){
    node* head=NULL;
    node* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    insertAtTail(head,tail,5);
    //  insertAtRandom(head);
    print(head);

//  node* copylist=copyList(head);
// cout<<"Copied list is ";
// print(copylist);
 node* copylist=copyList2(head);
cout<<"Copied list is ";
print(copylist);
    return 0;
}