#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>p1,pair<int,int>p2){
    if(p1.first!=p2.first)
    return p1.first<p2.first;
    return p1.second>p2.second;
}

int russianDollEnvelope(vector<pair<int,int>>Envelopes){
    sort(Envelopes.begin(),Envelopes.end(),compare);
    vector<int>ans;
    ans.push_back(Envelopes[0].second);
    for(int i=1;i<Envelopes.size();i++){
        if(Envelopes[i].second>ans.back())
        ans.push_back(Envelopes[i].second);
        else{
            int index=lower_bound(ans.begin(),ans.end(),Envelopes[i].second)-ans.begin();
            ans[index]=Envelopes[i].second;
        }
    }
    return ans.size();
}

int main(){
    vector<pair<int,int>>v={{5,4},{6,4},{6,7},{2,3}};
    cout<<"Maximum number of envelope that can be merged "<<russianDollEnvelope(v)<<endl;
    
    return 0;
}