#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

queue<int> rev(queue<int>q){
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}

vector<long long> printFirstNegativeInteger(int a[],int n,int k){
    deque<int>dq;
    vector<long long>ans;

    //process first window of k size
    for(int i=0;i<k;i++){
        if(a[i]<0){
            dq.push_back(i);
        }
    }

    //store ans of first k size window
    if(dq.size()>0){
        ans.push_back(a[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    //process for remaining windows
    for(int i=k;i<n;i++){
       //removal
       if(!dq.empty() && i-dq.front()>=k){
        dq.pop_front();
       }
       //addition
       if(a[i]<0){
            dq.push_back(i);
       }
       //ans store
           if(dq.size()>0){
        ans.push_back(a[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }
    }
return ans;
}

queue<int> reverseKelement(queue<int>q,int k){
    stack<int>s;
    int n=q.size();
    //step1 :pop k element from Q and put into stack
   for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    //step2 : fetch from stack and push int Q
    while(!s.empty()){
          q.push(s.top());
          s.pop();
    }
    //step3 : fetch first n-k elements from q and push back
    int a=q.size()-k;
    while(a--){
        q.push(q.front());
        q.pop();
            }
    return q;
}

int main(){
    //----->QUEUE REVERSAL<------
    /*queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int> reverse= rev(q); 
    int n=reverse.size();
    for(int i=0;i<n;i++){
         cout<<reverse.front()<<" ";
         reverse.pop();
    }cout<<endl;*/
    
    //------>FIND NEGATIVE INTEGER IN EVERY WINDOW OF SIZE K<-------
    /*int a[5]={-8,2,3,-6,10};
    vector<long long>v=printFirstNegativeInteger(a, 5,2);
    for(auto e:v)
    cout<<e<<" ";
    cout<<endl;*/

    //----->REVERSE FIRST K ELEMENTS OF QUEUE<------
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    queue<int> reverse=reverseKelement(q,3);
     int n=q.size();
     for(int i=0;i<n;i++){
        cout<<reverse.front()<<" ";
        reverse.pop();
     }cout<<endl;
 
    return 0;
}