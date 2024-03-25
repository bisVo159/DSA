#include<iostream>
using namespace std;

#define PI 3.14

inline int getmax(int& a,int& b){
return (a>b)? a:b;       //benefits of inline function are no extrs memory uses and no function call return value will be replaced automatically before compilation
}

void print(int arr[],int n,int start=0){
    for(int i=start;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
 int main(){
    //MACRO--> A piece of code in a program that is replaced by value of macro
   // PI=PI+1; Iis not possible
   /* int r=5;
    double area=PI*r*r;
    cout<<area;*/

    //INLINE FUNCTION are used to reduce the function calls over head
    /*int a=1,b=2,ans=0;
    ans=getmax(a,b);
    cout<<ans<<endl;
    a=a+3;
    b=b+1;
      ans=getmax(a,b);
      cout<<ans<<endl;*/

      //---->DEFAULT ARGUMENT<-----
      /*int arr[5]={1,4,7,8,9};
      int size = 5;
      print(arr,size);     //default args always should start from rightmost parameter   (right to left)
      print(arr,size,2);*/

    return 0;
}