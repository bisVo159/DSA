#include<iostream>
using namespace std;

int sum(int n){
   if(n==0){
       return 0;
   }
   int prevsum=sum(n-1);
   return n+prevsum;
}

int power(int n,int p){
    if(p==0)
    return 1;
      int prevpower=power(n,p-1);
      return n*prevpower;
}

int factorial(int n){
    if(n==0)
    return 1;
    int prevfact= factorial(n-1);
    return n*prevfact; 
}

int fib(int n){
    if(n<2)
    return n;
    return fib(n-1)+fib(n-2);
}

void print(int n){
    if(n==0)
    return ;
 cout<<n<<endl;
    print(n-1);
}

int stair(int n){
    if(n==0)
    return 1;
    else if (n<0)
    return 0;
return stair(n-1)+stair(n-2);
}

void saydigit(int n,string arr[]){
    if(n==0)
    return;
    int digit=n%10;
    n=n/10;
    saydigit(n,arr);
    cout<<arr[digit]<<" ";

}

int main(){
   // int n;
   // cin>>n;
    //----->ADD ALL NUMBER TILL n<------

      //  cout<<sum(n)<<endl;

      //---->CALCULATE n RAISE TO POWER OF p<-----
//int n,p;
//cin>>n>>p;
//cout<<power(n,p);

//---->FIND THE FACTORIAL OF A NUMBER<----
/*int n;cin>>n;
cout<<factorial(n);*/

//------>PRINT nth FIBONACCI NUMBER<------
/*int n;
cin>>n;
cout<<fib(n);*/
/*int n;
cin>>n;
print(n);*/

//------>COUNT WAYS YOU TO REACH THE Nth STAIRS<-----
/*int n;
cin>>n;
cout<<stair(n);*/

//----->SAY DIGITS<-----
int n;
cin>>n;
string arr[]={"zero","one","two","three","four","five","six","seven","eight","nine"};
saydigit(n,arr);
    return 0;
}