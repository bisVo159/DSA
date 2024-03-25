#include<iostream>
#include<vector>
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
void insertAtTail(node* tail, int d)
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

bool checkpalindrome(vector<int>arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        if(arr[s]!=arr[e])
        return false;
            s++;
             e--;
    }
return 1;
}

bool isPalindrome(node* head){
    vector<int>arr;
    node* temp=head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }
    return checkpalindrome(arr);

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

node* getmid(node* head){
      node* slow=head;
    node* fast=head->next;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

//2nd approach
bool isPalindrome2(node* head){
   if(head==NULL||head->next==NULL){
       return true;
   }
   //step 1->find middle
   node* middle=getmid(head);

   //step 2 -> reverse list after middle
   node* temp=middle->next;
   middle->next=reverse(temp);

   //step3 -> compare both halves
   node* head1=head;
   node* head2=middle->next;
   while(head2!=NULL){
       if(head1->data!=head2->data){
        return false;
   }
       head1=head1->next;
       head2=head2->next;
   }
//    step4 -> repeat step2(optional)
temp=middle->next;
middle->next=reverse(temp);
   return true;
}

int main(){
     node *node1 = new node(1); 
 node *head = node1;
node *tail = node1;
  insertAtTail(tail, 2);
  insertAtTail(tail, 3);
  insertAtTail(tail, 3);
  insertAtTail(tail, 2);
  insertAtTail(tail, 1);
    print(head);
  //if(isPalindrome(head))
//   cout<<"LL is palindrome"<<endl;
//   else
//   cout<<"LL is not palindrome"<<endl;
  if(isPalindrome2(head))
  cout<<"LL is palindrome"<<endl;
  else
  cout<<"LL is not palindrome"<<endl;
  print(head);
    
    return 0;
}