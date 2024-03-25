#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    /*int basic[3]={1,2,3};
    array<int,4>a={1,2,3,4};
    int size=a.size();
    for(int i=0;i<size;i++){
             cout<<a[i]<<endl;
    }
    cout<<"Element at 2nd index--> "<<a.at(2)<<endl;
    cout<<"Empty or not--> "<<a.empty()<<endl;

    cout<<"First element--> "<<a.front()<<endl;
    cout<<"Last element--> "<<a.back()<<endl;*/

    //---->VECTOR<----
 /*   vector<int>v;
    cout<<"size--> "<<v.capacity()<<endl;
  v.push_back(1);
    cout<<"size--> "<<v.capacity()<<endl;
  v.push_back(2);
    cout<<"size--> "<<v.capacity()<<endl;
  v.push_back(3);
    cout<<"size--> "<<v.capacity()<<endl;
  v.push_back(4);
    cout<<"size--> "<<v.capacity()<<endl;
  v.push_back(4);
    cout<<"size--> "<<v.capacity()<<endl;
    cout<<"Size--> "<<v.size()<<endl;
    cout<<"First element--> "<<v.front()<<endl;
 cout<<"Last element--> "<<v.back()<<endl;
 cout<<"Element at 2nd index "<<v.at(2)<<endl;
 cout<<"Before pop"<<endl;
 for(int i:v){
    cout<<i<<endl;
 }
 v.pop_back();
 cout<<"after pop"<<endl;
 for(int i:v){
    cout<<i<<endl;
 }
 cout<<"Before clear"<<endl;
 cout<<v.size()<<endl;
 cout<<v.capacity()<<endl;
 v.clear();
  cout<<"after clear"<<endl;
 cout<<v.size()<<endl;
 cout<<v.capacity()<<endl;
 vector<int>v1(5,1);
 for(int i:v1)
 cout<<i<<endl;
 vector<int>last(v1);   //for copy v1 in last
  for(int i:last)
 cout<<"last "<<i<<endl;*/

 //------>  DEQUE  <-------
/* deque<int>d;
 d.push_back(1);
 d.push_back(3);
 d.push_front(2);*/
 /*for(int i:d)
 cout<<i<<" ";
 cout<<endl;
 d.pop_back();
 d.pop_front();
  for(int i:d)
 cout<<i<<" ";*/
 /*cout<<"Print first index element "<<d.at(1)<<endl;
 cout<<"front "<<d.front()<<endl;
 cout<<"back "<<d.back()<<endl;
 cout<<"Empty or not "<<d.empty()<<endl;
 cout<<"Before erase "<<d.size()<<endl;
 d.erase(d.begin()+1,d.begin()+2);
 cout<<"after erase "<<d.size()<<endl;
 for(int i:d)
 cout<<i<<" ";
 cout<<endl;*/

 //---->LIST<-----
/*list<int>l;
l.push_back(1);
l.push_front(2);
for(int i:l)
cout<<i<<" ";
cout<<endl;
l.erase(l.begin());
cout<<"after erase "<<endl;
 for(int i:l)
 cout<<i<<" ";
 cout<<endl;
 cout<<"size of list "<<l.size()<<endl;
 list<int>n(5,100);
  for(int i:n)
 cout<<i<<" ";
 cout<<endl;*/

 //---->STACK<----
/*stack<string>s;
s.push("love");
s.push("babbar");
s.push("kumar");

cout<<"Top element-> "<<s.top()<<endl;
s.pop();
cout<<"Top element-> "<<s.top()<<endl;
cout<<"size of stack "<<s.size()<<endl;
cout<<"empty or not "<<s.empty()<<endl;*/

//------>QUEUE<-----
/*queue<string>q;
q.push("love");
q.push("babbar");
q.push("kumar");
cout<<"First element "<<q.front()<<endl;
q.pop();
cout<<"First element "<<q.front()<<endl;
cout<<"size of queue "<<q.size()<<endl;
cout<<"empty or not "<<q.empty()<<endl;*/

//----->PRIORITY QUEUE<------
//max heap
/*priority_queue<int>maxi;    

//min heap
priority_queue<int,vector<int>,greater<int>>mini;

maxi.push(1);
maxi.push(3);
maxi.push(2);
maxi.push(0);
cout<<"size-> "<<maxi.size()<<endl;
int n=maxi.size();
for(int i=0;i<n;i++){
    cout<<maxi.top()<<" ";
    maxi.pop();
}cout<<endl;
mini.push(1);
mini.push(3);
mini.push(2);
mini.push(0);
cout<<"size-> "<<mini.size()<<endl;
n=mini.size();
for(int i=0;i<n;i++){
    cout<<mini.top()<<" ";
    mini.pop();
}cout<<endl;

cout<<"Khali hain kya vai "<<mini.empty()<<endl;*/

//---->SET<-----
/*set<int>s;    //one time store and sorted outpput
s.insert(5);
s.insert(5);
s.insert(5);
s.insert(1);
s.insert(6);
s.insert(6);
s.insert(0);
s.insert(0);
s.insert(0);
for(auto i:s){
  cout<<i<<endl;
}
set<int>::iterator it=s.begin();
it++;
s.erase(it);
for(auto i:s){
  cout<<i<<endl;
}
cout<<"5 is present or not "<<s.count(5)<<endl;
cout<<"-5 is present or not "<<s.count(-5)<<endl;

set<int>::iterator itr=s.find(5);
cout<<"value present at itr-> "<<*it<<endl;
for(auto it=itr;it!=s.end();it++){
  cout<<*it<<endl;
}*/

//----->MAP<------
map<int,string>m;
m[1]="babbar";
m[13]="kumar";
m[2]="love";
m.insert({5,"bheem"});
/*cout<<"before erase "<<endl;*/
for(auto i:m){
  cout<<i.first<<": "<<i.second<<endl;
}
/*cout<<"finding 13->"<<m.count(13)<<endl;
// m.erase(13);
cout<<"After erase"<<endl;
for(auto i:m){
  cout<<i.first<<": "<<i.second<<endl;
}*/

/*auto it=m.find(5);
for(auto i=it;i!=m.end();i++){
     cout<<(*i).first<<endl;
}*/

/*vector<int>v;
v.push_back(1);
v.push_back(3);
v.push_back(6);
v.push_back(7);
cout<<"finding 6"<<binary_search(v.begin(),v.end(),6)<<endl;
cout<<"lower bound--> "<<lower_bound(v.begin(),v.end(),6)-v.begin()<<endl;
cout<<"upper bound-->"<<upper_bound(v.begin(),v.end(),6)-v.begin()<<endl;
int a=3;
int b=5;
cout<<"max "<<max(a,b)<<endl;
cout<<"min "<<min(a,b)<<endl;
swap(a,b);
cout<<a<<" "<<b<<endl;
string abcd="abcd";
reverse(abcd.begin(),abcd.end());
cout<<abcd<<endl;
rotate(v.begin(),v.begin()+2,v.end());
cout<<"after rotation"<<endl;
for(int i:v){
  cout<<i<<" ";
}cout<<endl;
sort(v.begin(),v.end());
for(int i:v){
  cout<<i<<" ";
}cout<<endl;*/
    return 0;
}