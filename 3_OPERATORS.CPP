#include<iostream>
using namespace std;

int main(){
   /* int i=1;
    i=i++ + ++i;
    cout<<i<<endl;*/
   /* int i,j,k;
    i=1;
    j=2;
    k=i + j  + i++ + j++ + ++i + ++j;
    cout<<i<<" "<<j<<" "<<k<<endl;*/
    /*int i=0;
    i=i++ - --i + ++i - i--;
    cout<<i<<endl;*/
    int i=10,j=20,k;

    k= i-- - i++ + --j - ++j + --i - j-- + ++i - j++;
    cout<<i<<endl<<j<<endl<<k;

    return 0;
}