#include<iostream>
using namespace std;

int main(){
   /* int pocketmoney = 3000;
    for(int date=1;date<=30;date++){
        if(date%2==0){
            continue;
        }
        if(pocketmoney==0){
            break;
        }
        cout<<"go out today"<<endl;
        pocketmoney=pocketmoney-300;
    }*/

   /* int n;
    cin>>n;
    int i;
    for(i=2;i<n;i++){
        if(n%i==0){
            cout<<"not prime"<<endl;
            break;
        }
    }
    if(i==n){
        cout<<"prime"<<endl;
    }*/

    /*int a,b;
    cin>>a>>b;
    for(int num=a;num<=b;num++){
        int i;
        for( i=2;i<num;i++){
            if(num%i==0){
                break;
            }
        }
        if(i==num){
            cout<<i<<endl;
        }
    }*/

    /*int n;
    cout<<"Enter a positive integer"<<endl;
    cin>>n;
    for(int i=1;i<=n;++i){
        cout<<n<<" * "<<i<<" = "<<i*n<<endl;
    }*/

int n;
int sum=0;
    cout<<"Enter a number";
    cin>>n;
    while(n>=0){
        sum+=n;
        cout<<"enter a number";
        cin>>n;
    }

    cout<<"\nthe sum is "<<sum<<endl;
    return 0;
}