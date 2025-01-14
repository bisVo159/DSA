#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(int* arr,int n){
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
vector<int> prevSmallerElement(int* arr,int n){
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

int largestRectangleArea(int* heights,int n){
    // int n=heights.size();

    vector<int>next(n);
    next=nextSmallerElement(heights,n);
    vector<int>prev(n);
    prev=prevSmallerElement(heights,n);
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

int maxArea(int** M,int n,int m){
    //Compute  area for the first row
    int area=largestRectangleArea(M[0],m);

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
       //row update by adding previous row's value
       if(M[i][j]!=0)
        M[i][j]=M[i][j]+M[i-1][j];
        else
        M[i][j]=0;
    }
//Entire row is updated now
int newarea=largestRectangleArea( M[i], m);
area=max(area,newarea);
}
return area;
}

int main(){
    //---->MAX RECTANGLE IN BINARY MATRIX WITH ALL 1's<-----
    int** arr=new int*[4];
    for(int i=0;i<4;i++){
       arr[i]=new int[4];
    }
     for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }

int area= maxArea(arr,4,4);     

cout<<"max  rectangle in binary matrix with all 1's "<<area;
    
    return 0;
}