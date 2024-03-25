#include<iostream>
#include<math.h>
using namespace std;

bool isprime(int num){
for(int i=2;i<=sqrt(num);i++){
    if(num%i==0){
        return false;
    }
}
return true;
}

void fib(int n){
    int t1=0;
    int t2=1;
    int nextterm;
    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        nextterm=t1+t2;
        t1=t2;
        t2=nextterm;
    }
    return;
}

int fact(int n){
    int factorial=1;
    for(int i=2;i<=n;i++){
        factorial=factorial*i;
    }
    return factorial;
}
int main(){
    // ---------> PRIME NUMBER < ----------
 /*int a,b;
 cin>>a>>b;
 for(int i=a;i<=b;i++){
     if(isprime(i)){
         cout<<i<<endl;
     }
 }*/

 // --------> FIB0NACCI SEQUENCE <----------
/*int n;
cin>>n;
fib(n);*/

// -------> FACTORIAL <--------
/*int n;
cin>>n;
int ans=fact(n);
cout<<ans;*/

// ---------> CALCULATE nCr <---------
/*int n,r;
cin>>n>>r;
int ans=fact(n)/(fact(r)*fact(n-r));
cout<<ans;*/

// --------> PASCAL TRIANGLE <--------
/*1
    1  1
    1  2  1
    1  3  3  1
    1  4  6  4  1*/
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<fact(i)/(fact(i-j)*fact(j))<<" ";
        }
        cout<<endl;
    }

    return 0;
}