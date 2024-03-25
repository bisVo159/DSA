#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;

int main(){
    // ------> PRIME NUMBER <-------
    /*int n;
    cin>>n;
    bool flag=0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            cout<<"Non-prime"<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<"Prime";
    }*/

    // ------> REVERSE A NUMBER <-------
   /* int n;
    cin>>n;
    int reverse=0;
    while(n>0){
        int lastdigit=n%10;
        reverse=reverse*10+lastdigit;
        n=n/10;
    }
    cout<<reverse;*/

    // ------> ARMSTRONG NUMBER <--------
    int n;
    cin>>n;
    float sum=0;
    int  originaln=n;
    while(n>0){
        int lastdigit=n%10;
        sum=sum+pow(lastdigit,3);
        n=n/10;
    }
    if(sum==originaln){
        cout<<"armstrong number"<<endl;
    }
    else{
        cout<<"not armstrong"<<endl;
    }
    return 0;
}