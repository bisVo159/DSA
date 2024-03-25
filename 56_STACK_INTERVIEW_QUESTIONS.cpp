#include<iostream>
#include<stack>
#include<string>
using namespace std;

void solve(stack<int>&inputstack,int count,int size){
    if(count==size/2){
        inputstack.pop();
        return;
    }
    int top=inputstack.top();
    inputstack.pop();
    solve(inputstack,count+1,size);
    inputstack.push(top);
}

void deleteMiddle(stack<int>&inputstack,int n){
      int count=0;
      solve(inputstack,count,n);
}

bool isValidParenthesis(string expression){
 stack<char>s;
for(int i=0;i<expression.length();i++){
    char ch=expression[i];
    //if opening bracket,stack push
    //if closing bracket,stacktop check and pop

    if(ch=='('||ch=='{'||ch=='['){
        s.push(ch);
    }
    else{
        if(!s.empty()){
        char top=s.top();
        if((ch==')'&&top=='(')||(ch=='}'&&top=='{')||(ch==']'&&top=='[')){
                 s.pop();
        }
        else{
            return 0;
        }
        }
        else{
            return 0;
        }
    }
}
if(s.empty()){
    return true;
}
else{
    return false;
}
}

void pushAtBottom(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int top=s.top();
    s.pop();
    pushAtBottom(s,x);
    s.push(top);
}

void reverseStack(stack<int>&s){
    if(s.empty())
    return;

    int top=s.top();
    s.pop();
    reverseStack(s);
    pushAtBottom(s,top);
}

void sortedInsert(stack<int>&s,int x){
       if(s.empty()||s.top()<x){
        s.push(x);
        return;
       }
       int top=s.top();
       s.pop();
       sortedInsert(s,x);
       s.push(top);
}

void sortStack(stack<int>&s){
    if(s.empty())
    return;

    int top=s.top();
    s.pop();
    sortStack(s);
    sortedInsert(s,top);
}

bool findRedundantBrackets(string s){
     stack<char>st;
     for(int  i=0;i<s.length();i++){
          char ch=s[i];
          if(ch=='('||ch=='+'||ch=='-'||ch=='/'||ch=='*'){
            st.push(ch);
          }
          else{
            if(ch==')'){
                bool isRedundant=true;
                  while(st.top()!='('){
                    char top=st.top();
                    if(top=='+'||top=='-'||top=='/'||top=='*'){
                          isRedundant=false;
                    }
                    st.pop();
                  }
                  if(isRedundant==true)
                  return true;
                  st.pop();
            }
          }
     }
     return false;
}

int findMinimumCost(string str){
    //odd condition
    if(str.length()%2 != 0)
    return -1;

    stack<char>s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else{
            if(!s.empty()&&s.top()=='{'){
                 s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
     //stacks contains invalid expression now
     int a=0,b=0;
     while(!s.empty()){
        if(s.top()=='{')
        a++;
        else
        b++;
        s.pop();
     }
     int ans=(a+1)/2 + (b+1)/2;
     return ans;
}

int main(){
    //----->REVERSE A STRING<------T.C=O(n)    S.C=O(n)
  /*  string str="Anik";
    stack<char>s;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        s.push(ch);
}
string ans="";
while(!s.empty()){
    char ch=s.top();
    ans.push_back(ch);
    s.pop();
}
cout<<"reversed string is "<<ans<<endl;*/

//---> DELETE MIDDLE ELEMENT FROM STACK <-----
/*stack<int>s;
s.push(1);
s.push(2);
s.push(3);
s.push(4);
s.push(5);
deleteMiddle(s,s.size());
int n=s.size();
for(int i=0;i<n;i++){
   cout<< s.top()<<" ";
   s.pop();
}*/

//------->VALID PARENTHESES<---------T.C=O(N)  S.C=O(N)
/*string expression;
cin>>expression;
if(isValidParenthesis(expression))
cout<<"Valid Parenthesis"<<endl;
else
cout<<"Not valid parethesis"<<endl;*/

//------->INSERT AN ELEMENT AT ITS BOTTOM IN A GIVEN STACK<-------
/*stack<int>s;
s.push(2);
s.push(3);
s.push(4);
s.push(5);
pushAtBottom(s,1);
int n=s.size();
for(int i=0;i<n;i++){
    cout<<s.top()<<" ";
    s.pop();
}cout<<endl;

//------>REVERSE STACK USING RECURSION<------T.C=O(N^2)    S.C=O(N^2)
stack<int>stack;
stack.push(1);
stack.push(2);
stack.push(3);
stack.push(4);
stack.push(5);
    reverseStack(stack);
    n=stack.size();
    for(int i=0;i<n;i++){
    cout<<stack.top()<<" ";
    stack.pop();
}cout<<endl;*/

//------>SORT A STACK<------
/*stack<int>s;
s.push(5);
s.push(-2);
s.push(9);
s.push(-7);
s.push(3);
sortStack(s);
int n=s.size();
for(int i=0;i<n;i++){
    cout<<s.top()<<endl;
    s.pop();
}*/

//----->REDUNDANT BRACKETS<-------
/*string str="((a+b))";
if(findRedundantBrackets(str))
cout<<"Redundant"<<endl;
else
cout<<"Not Redundant"<<endl;*/

//------>MINIMUM COST TO MAKE STRING VALID<-------
string str="}}}}{{{{";
cout<<findMinimumCost(str)<<endl;

    return 0;
}