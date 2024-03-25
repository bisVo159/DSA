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
node* buildTree(node* root){
     cout<<"Enter the data"<<endl;
     int data;
     cin>>data;
     root = new node(data);
     if(data==-1){
        return NULL;
     }
     cout<<"Enter data for inserting in left of "<<data<<endl;
     root->left=buildTree(root->left);
     cout<<"Enter data for inserting in right of "<<data<<endl;
     root->right=buildTree(root->right);
     return root;
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

bool isIdentical(node* r1,node* r2){
    //base case
    if(r1==NULL&&r2==NULL)
    return true;
    if(r1==NULL&&r2!=NULL)
    return false;
    if(r1!=NULL&&r2==NULL)
    return false;
    if(r1->data==r2->data){
        return isIdentical(r1->left,r2->left);
        return isIdentical(r1->right,r2->right);
    }
    else{
        return false;
    }
}

pair<bool,int> isSumFast(node* root){
  //base case
  if(root==NULL){
    pair<bool,int>p=make_pair(true,0);
    return p;
  }
  if(root->left==NULL&&root->right==NULL){
    pair<bool,int>p=make_pair(true,root->data);
    return p;
  }

  pair<bool,int>left=isSumFast(root->left);
  pair<bool,int>right=isSumFast(root->right);

  pair<bool,int>ans;
  ans.first=left.first&&right.first&&(root->data==left.second+right.second);
  ans.second=root->data+left.second+right.second;
  return ans;
  }

bool isSumTree(node* root){
    return isSumFast(root).first;
}

int main(){
    //----->DETERMINE IF TWO TREE ARE IDENTICAL<----- 
    node* r1=NULL;
    r1=buildTree(r1);
    levelOrderTraversal(r1); 
    // 1 2 4 -1 -1 5 7 -1 -1 -1 3  6 9 8 -1 -1 -1 -1 -1

   /* node* r2=NULL;
    r2=buildTree(r2);
    levelOrderTraversal(r2); 
     //1 10 5 -1 -1 -1 39 -1 -1
   if(isIdentical(r1,r2))
   cout<<"Trees are identical"<<endl;
   else
   cout<<"Trees are not identical"<<endl;*/

  //  ----->CHECK SUM TREE OR NOT<-----
   if(isSumTree(r1))
   cout<<"Sum Tree"<<endl;
   else
   cout<<"Not Sum Tree"<<endl;
   
    return 0;
}