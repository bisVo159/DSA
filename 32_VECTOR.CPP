#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool mycompare(pair<int,int>p1,pair<int,int>p2){
return p1.first<p2.first;
}

int main(){
   /* vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
    for(auto element:v){
        cout<<element<<endl;
    }
    v.pop_back();//1 2
      vector<int> v2(3,50);
      swap(v,v2);
    for(auto element:v){
        cout<<element<<endl;
    }
    for(auto element:v2){
        cout<<element<<endl;
    }
    sort(v.begin(),v.end());*/

   /* pair<int,char> p;
    p.first=3;
    p.second='f';*/

     int arr[]={10,16,7,14,5,3,12,9};
    vector<pair<int,int>>v;
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end(),mycompare);
    for(int i=0;i<v.size();i++){
        arr[v[i].second]=i;
    }
    for(int i=0;i<v.size();i++){
    cout<<arr[i]<<" ";
    }
    return 0;
}