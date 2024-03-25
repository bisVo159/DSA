#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int sum(int n){
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans+=i;
    }
    return ans;
}
bool check(int x,int y,int z){
    int a= max(x,max(y,z));
    int b,c;
    if(a==x){
        b=y;
        c=z;
    }
    else if(a==y){
         b=x;
         c=z;
    }
    else{
        b=x;
        c=y;
    }
    if(a*a==b*b+c*c){
        return true;
    }else{
    return false;
    }
}
int binaryTodecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int y=n%10;
        ans+=x*y;
        x*=2;
        n/=10;
    }
    return ans;
}

int octalTodecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int y=n%10;
        ans+=x*y;
        x*=8;
        n/=10;
    }
    return ans;
}
int hexadecimalTodecimal(string n){
    int ans=0;
    int x=1;
    int s=n.size();
    for (int i = s-1; i >=0; i--)
    {
         if(n[i]>='0'&&n[i]<='9') {
             ans+=x*(n[i]-'0');
         }
         else if(n[i]>='A'&&n[i]<='F'){
             ans+=x*(n[i]-'A'+10);
         }
         x*=16;
    }
    return ans; 
}
int decimalTobinary(int n){
    int x=1;
    int ans=0;
    while(x<=n)
         x*=2;
         x/=2;
         while(x>0){
             int lastdigit=n/x;
             n-=lastdigit*x;
             x/=2;
             ans=ans*10+lastdigit;
         }
         return ans;
    }
    void DTOB(int n){
        int rem;
        int a[10];
        int i=0;
       while(n>0){
           rem=n%2;
           n=n/2;
           a[i]=rem;
           i++;
       }
       for (int j = i-1; j >=0 ; j--)
       {
              cout<< a[j];
       }
    }
    int decimalTOoctal(int n){
         int x=1;
    int ans=0;
    while(x<=n){
         x*=8;
         x/=8;
         while(x>0){
             int lastdigit=n/x;
             n-=lastdigit*x;
             x/=8;
             ans=ans*10+lastdigit;
         }
         return ans;
    }
    }
       
int main(){
   /*int n;
   cin>>n;()
   cout<<sum(n);*/

  /* int x,y,z;
   cin>>x>>y>>z;
   if (check(x,y,z)){
       cout<<"Pythagorean triplet";
   }else{
       cout<<"Not a pythagoren triplet";
   }*/
// -----> BINARY TO DECIMAL <--------
  // int n;
  // cin>>n;
  // cout<<binaryTodecimal(n)<<endl;

  // ------->OCTAL TO DECIMAL <---------
  //cout<<octalTodecimal(n)<<endl;

  // -------> HEXADECIMAL TO DECIMAL <-------
 // string n;
 // cin>>n;
  //cout<<hexadecimalTodecimal(n);
  // -------> DECIMAL TO BINARY <--------
  int n;
  cin>>n;
  //cout<<decimalTobinary(n);
 // DTOB(n);
 cout<<decimalTOoctal(n);

    return 0;
}