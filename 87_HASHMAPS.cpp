#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<limits.h>
using namespace std;

/*int maximumfrequency(vector<int>&arr){
    unordered_map<int,int>count;
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    int maxi=INT_MIN;
    int ans;
    for(auto i:count){
        if(i.second>maxi){
            maxi=i.second;
            ans=i.first;
        }
    }
    return ans;
}*/
int maxfrequency(vector<int>&arr,int n){
    unordered_map<int,int>count;
    int maxFreq=0;
    int maxAns=0;
    for(int i=0;i<n;i++){
        count[arr[i]]++;
        maxFreq=max(maxFreq,count[arr[i]]);
    }
    for(int i=0;i<n;i++){
        if(maxFreq==count[arr[i]]){
            maxAns=arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
    //create
    // unordered_map<string,int>m;
   /* map<string,int>m;

    //insertion

    //1
    pair<string,int>p=make_pair("babbar",3);
    m.insert(p);

    //2
    m["mera"]=1;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    // cout<<m.at("unknownKey")<<endl;    //this will throw error
    cout<<m["unknownKey"]<<endl;
    cout<<m.at("unknownKey")<<endl; 
    //size
    cout<<m.size()<<endl;

    //to check present
    cout<<m.count("bro")<<endl;
    cout<<m.count("babbar")<<endl;
    //erase
    m.erase("babbar");
    cout<<m.size()<<endl;

    // for(auto i:m)
    // cout<<i.first<<" "<<i.second<<endl;

    //iterator
    // unordered_map<string,int>::iterator it=m.begin();
    map<string,int>::iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }*/

    // ----->MAXIMUM FREQUENCY OF A NUMBER<-----  
    /*vector<int>a={1,2,3,1,1,1,5,5,6,3,2,8,2,9,2,10,2};
    // cout<<"maximum occurance of number in the vector is "<<maximumfrequency(a)<<endl;
    cout<<"maximum occurance of number in the vector is "<<maxfrequency(a,17)<<endl;*/
    
    return 0;
}
