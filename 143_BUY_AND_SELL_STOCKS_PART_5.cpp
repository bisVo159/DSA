#include<iostream>
#include<vector>
using namespace std;

int solve(int index,int buy,int& fee,vector<int>&prices){
    if(index==prices.size())
    return 0;

    int profit=0;
    if(buy){
        int Buy=-prices[index]+solve(index+1,0,fee,prices);
        int Skip=solve(index+1,buy,fee,prices);
        profit=max(Buy,Skip);
    }
    else{
        int Sale=prices[index]-fee+solve(index+1,1,fee,prices);
        int Skip=solve(index+1,buy,fee,prices);
        profit=max(Sale,Skip);
    }
    return profit;
}

int solveOpt(vector<int>&prices,int fee){
    int n=prices.size();
    vector<int>curr(2,0);
    vector<int>next(2,0);

    for(int index=n-1;index>=0;index--){
    for(int buy=0;buy<=1;buy++){
        int profit=0;
        if(buy){
        int Buy=-prices[index]+next[0];
        int Skip=0+next[buy];
        profit=max(Buy,Skip);
        }
        else{
        int Sale=prices[index]+next[1]-fee;
        int Skip=0+next[buy];
        profit=max(Sale,Skip);
        }
        curr[buy]=profit;
        }
        next=curr;
    }
    return curr[1];
}

int maxProfit(vector<int>&prices,int fee){
    // return solve(0,1,fee,prices);

    // space-optimisation
    return solveOpt(prices,fee);

}

int main(){
    vector<int>price={1,3,2,8,4,9};
    int fee=2;
    // vector<int>price={1,3,7,5,10,3};
    // intfee=3;
    cout<<"Maximum profit after given fees "<<maxProfit(price,fee)<<endl;
    
    return 0;
}