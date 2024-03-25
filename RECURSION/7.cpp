#include<iostream>
using namespace std;

int kthGrammer(int n,int k){
    if(n==1)
    return 0;

    int parent=kthGrammer(n-1,k/2+k%2);
    if(parent==0&&k%2==0)
    return 1;
    if(parent==0&&k%2!=0)
    return 0;
    if(parent==1&&k%2==0)
    return 0;
    if(parent==1&&k%2!=0)
    return 1;
}

int solve(int n,int k){
        if(n==1)
        return 0;

        return (solve(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        int ans=solve(n,k)+1;
        return ans;
        
    }

int main(){
//  Kth Symbol Grammer
// cout<<kthGrammer(4,7)<<endl;

// Find the winner of the circular game
    cout<<"Winner of the circular game "<<findTheWinner(4,2)<<endl;

    return 0;
}