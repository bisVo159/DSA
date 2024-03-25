#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>&arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}
vector<int> prevSmallerElement(vector<int>&arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(curr);
    }
    return ans;
}

vector<int> nextSmallerElement2(vector<int>&arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        int curr=arr[i];
        while(s.top()!=-1&&arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmallerElement2(vector<int>&arr,int n){
    stack<int>s;
    s.push(-1);
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        int curr=arr[i];
        while(s.top()!=-1&&arr[s.top()]>=curr){
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>&heights){
    int n=heights.size();

    vector<int>next(n);
    next=nextSmallerElement2(heights,n);
    vector<int>prev(n);
    prev=prevSmallerElement2(heights,n);
    int Area=INT_MIN;
    for(int i=0;i<n;i++){
        int l=heights[i];
        if(next[i]==-1){
            next[i]=n;
        }
        int b=next[i]-prev[i]-1;
        int newArea=l*b;
        Area=max(Area,newArea);
    }
    return Area;
}

int main(){
    //----->NEXT SMALLER ELEMENT<------
   /*vector<int>v;
   v.push_back(2);
   v.push_back(1);
   v.push_back(4);
   v.push_back(3);
   vector<int>ans=nextSmallerElement(v,v.size());
  for(int i:ans){
    cout<<i<<" "; 
  }cout<<endl;*/

  //----->LARGEST RECTANGLE IN HISTOGRAM<-------
  vector<int>heights;
  heights.push_back(2);
  heights.push_back(1);
  heights.push_back(5);
  heights.push_back(6);
  heights.push_back(2);
  heights.push_back(3);
cout<<"largest Rectangular area: "<<largestRectangleArea(heights);
    return 0;
}