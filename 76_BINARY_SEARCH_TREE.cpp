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
void inorder(node* root){
    //Base case
    if( root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    // Base Case
    if(root==NULL)
    return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    if(root==NULL)
    return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

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

bool searchInBST(node* root,int x){
    if(root==NULL)
    return false;
    if(root->data==x)
    return true;

    if(x>root->data)
    return   searchInBST(root->right,x);
    else
    return  searchInBST(root->left,x);  
}

//iterative
bool searchInBST2(node* root,int x){
    node* temp=root;
    while(temp!=NULL){
        if(temp->data==x)
        return true;

        if(temp->data>x){
            temp=temp->left;
        }

        if(temp->data<x){
            temp=temp->right;
        }
    }
    return false;
}

node* minVal(node* root){
    node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node* maxVal(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node* deleteFromBST(node* root,int val){
    //base case
    if((root==NULL))
    return root;
    if(root->data==val){
        //0 child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }

        //1 child
        //left child
        if(root->left!=NULL&&root->right==NULL){
            node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right!=NULL&&root->left==NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL&&root->right!=NULL){
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
     else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

node* inorderSuccessor(node* root,int x){
    node* successor=NULL;
    while(root!=NULL){
        if(root->data<=x){
            root=root->right;
        }
        else{
            successor=root;
            root=root->left;
        }
    }
    return successor;
}
node* inorderPredeccessor(node* root,int x){
    node* Predeccessor=NULL;
    while(root!=NULL){
        if(root->data>=x){
            root=root->left;
        }
        else{
            Predeccessor=root;
            root=root->right;
        }
    }
    return Predeccessor;
}

int main(){
    // ----->INSERTION A NODE IN BST<-----
    node* root=NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
   /* cout<<"Printing the BST : "<<endl;
    levelOrderTraversal(root);
    cout<<"Printing Inorder : ";
    inorder(root);cout<<endl;
    cout<<"Printing preorder : ";
    preorder(root);cout<<endl;
    cout<<"Printing postorder : ";
    postorder(root);cout<<endl;*/

    // -----SEARCH IN BST<-----
  /*  if(searchInBST2(root,25))
    cout<<"element present in tree"<<endl;
    else
    cout<<"element is not present"<<endl;*/

    // ----->MIN AND MAX VALUE IN BST<-----
   /* cout<<"Min value of BST is : "<<minVal(root)->data<<endl;
    cout<<"Max value of BST is : "<<maxVal(root)->data<<endl;*/

    //HW : Inorder predecessor ? InordervSucessor ?

    //------>DELETION<------
    //100 50 110 25 70 120 60 115 -1
    /*root=deleteFromBST( root, 100);
     cout<<"Printing the BST after deletion : "<<endl;
    levelOrderTraversal(root);
    cout<<"Printing Inorder : ";
    inorder(root);cout<<endl;*/

    //------>INORDER PREDECESSOR AND SUCCESSOR<------
    // 21 10 50 5 15 40 60 35 55 70 -1
    cout<<inorderSuccessor(root,50)->data<<endl;
    cout<<inorderPredeccessor(root,50)->data<<endl;
    
    return 0;
}