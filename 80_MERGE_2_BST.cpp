#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
node* insertIntoBST(node* root,int d){
    if(root==NULL){
        root=new node(d);
        return root;
    }
    if(d>root->data){
        //insert at right part
        root->right=insertIntoBST(root->right,d);
    }
    else{
        //insert at left part
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}
void takeInput(node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
            cin>>data;
    }
}
void levelOrderTraversal(node* root){
      queue<node*>q;
      q.push(root);
      q.push(NULL);

      while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){//Old level traverse completed
            cout<<endl;
            if(!q.empty()) {     //queue still has some child nodes
                  q.push(NULL);
            }
        }
                else{
              cout<<temp->data<<" ";
            if(temp->left){
             q.push(temp->left);
        }
        if(temp->right){
             q.push(temp->right);
        }
        }
      }
} 

void convertIntoSortedDLL(node* root,node* &head){
        //base case 
        if(root==NULL)
        return ;

        convertIntoSortedDLL(root->right,head);
        root->right=head;
        if(head!=NULL)
        head->left=root;

        head=root;
        convertIntoSortedDLL(root->left,head);

}

node* mergeLinkedList(node* head1,node* head2){
    node* head=NULL;
    node* tail=NULL;
    while(head1!=NULL&&head2!=NULL){
            if(head1->data<head2->data){
                if(head==NULL){
                    head=head1;
                    tail=head1;
                    head1=head1->right;
                }
                else{
                    tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;
                }
            }
            else{
                    if(head==NULL){
                    head=head2;
                    tail=head2;
                    head2=head2->right;
                }
                else{
                    tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;
                }
            }
        }
        while(head1!=NULL){
                    tail->right=head1;
                    head1->left=tail;
                    tail=head1;
                    head1=head1->right;
        }
        while(head2!=NULL){
                    tail->right=head2;
                    head2->left=tail;
                    tail=head2;
                    head2=head2->right;
        }
        return head;
    }

    int countNodes(node* head){
        node* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->right;
        }
        return cnt;
    }

    node* sortedLLToBST(node* &head,int n){
        //base case
        if(n<=0||head==NULL)
        return NULL;
        node* left=sortedLLToBST(head,n/2);
        node* root=head;
        root->left=left;
        head=head->right;
        root->right=sortedLLToBST(head,n-n/2-1);
        return root;
    }

node* mergeBST(node* root1,node* root2){
    // step1 : convert BST into sorted DLL in-place
    node* head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left=NULL;

    node* head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left=NULL;

    // step2 : merge sorted LL
    node* head=mergeLinkedList(head1,head2);

    // convert sorted LL to BST
    return  sortedLLToBST(head,countNodes(head));
}

int main(){
    node* root1=NULL;
    cout<<"Enter data to create BST1 "<<endl;
    takeInput(root1);
     node* root2=NULL;
    cout<<"Enter data to create BST2 "<<endl;
    takeInput(root2);
    //1 2 3 4 5 -1 6 7 8 9 10 -1

   node* merge= mergeBST(root1,root2);
   levelOrderTraversal( merge);
    return 0;
}