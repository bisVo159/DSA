#include"bits/stdc++.h"
using namespace std;

class petrolPump{
    public:
    int petrol;
    int distance;
};

string firstNonRepeating(string s){
   map<char,int>count;
    queue<int>q;
    string ans="";
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        //increase count
        count[ch]++;
        //queue me push karo
        q.push(ch);
        while(!q.empty()){
            if(count[q.front()]>1){
                //repeating character
                q.pop();
            }
            else{
                //non-repeating character
                    ans.push_back(q.front());
                    break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int tour(petrolPump p[],int n){
         int deficit=0;
         int balance=0;
         int start=0;
         for(int i=0;i<n;i++){
            balance+=p[i].petrol-p[i].distance;
            if(balance<0){
                deficit+=balance;
                start=i+1;
                balance=0;
            }
         }
         if(deficit+balance>=0){
            return start;
         }
         else{
            return -1;
         }
}

queue<int> interleave(queue<int>q,int n){
    stack<int>s;
    while(s.size()!=n/2){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int a=n/2;
    while(a--){
        q.push(q.front());
        q.pop();
    }
 
        while(s.size()!=n/2){
        s.push(q.front());
        q.pop();
    }
        while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main(){
    //---->FIRST NONREPEATING CHARATER IN ASTREA<-----
    /*string s="aabc";
    string A=firstNonRepeating(s);
    cout<<A<<endl;*/

    //----->CIRCULAR TOUR<-----
   /* petrolPump arr[]={{6,5},{7,6},{4,7},{10,8},{6,6},{5,4}};
    int start=tour(arr,6);
    cout<<"starting petrol pump is : "<<start<<endl;*/

    //INTERLEAVE THE FIRST HALF OF THE THE QUEUE WITH THE 2nd HALF
    queue<int>q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    int n=q.size();
   queue<int>Q= interleave(q,n);
   while(!Q.empty()){
    cout<<Q.front()<<" ";
    Q.pop();
   }cout<<endl;

    return 0;
}