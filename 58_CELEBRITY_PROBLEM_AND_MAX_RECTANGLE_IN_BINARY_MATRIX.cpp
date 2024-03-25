#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<limits.h>

using namespace std;

bool knows(vector<vector<int>>&m,int a ,int b,int n){
    if(m[a][b]==1)
    return true;
    else
    return false;
}


int celebrity(vector<vector<int>>&m,int n){
      stack<int>s;
      //step1: push all element in stack
      for(int i=0;i<n;i++){
        s.push(i);
      }

      //step2: get 2 elements and compare them
      while(s.size()!=1){
        int a=s.top();
        s.pop();
        int b=s.top();
        s.pop();

        if(knows(m,a,b,n)){
            s.push(b);
        }
        else{
            s.push(a);
        }
      }
    int candidate=s.top();
      //step3: Single element in stack is poential celebrity
      //so verify it
      int zerocount=0;
      for(int i=0;i<n;i++){
           if(m[candidate][i]==0)
           zerocount++;
      }
      if(zerocount!=n)
      return -1;

      //column check
      int onecount=0;
     for(int i=0;i<n;i++){
           if(m[i][candidate]==1)
           onecount++;
    }
    if(onecount!=n-1)
    return -1;
return candidate;
}


int main(){
    vector<vector<int>>v={{0,1,0},
                                              {0,0,0},
                                              {0,1,0}
                                             };
    cout<<"celebrity is: "<<celebrity(v,v.size());   
    return 0;

}