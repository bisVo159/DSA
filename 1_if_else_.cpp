#include<iostream>
using namespace std;

int main(){
  /*  int a,b,c;
    cin>>a>>b>>c;
    if(a>b){
        if(a>c){
            cout<<a<<endl;
        }else{cout<<c<<endl;
        }
    }
        else{
            if(b>c){
                cout<<b<<endl;
            }
            else{
cout<<c<<endl;
            }
        }*/

     //programming to check if an alphabet is vowel or consonant

/*char c;
//int isLowervowel,isUppervowel;
cout<<"Enter an alphabet"<<endl;
cin>>c;
if((c=='a'||c=='e'||c=='i'||c=='o'||c=='u')||(c=='A'||c=='E'||c=='I'||c=='O'||c=='u')){
    cout<<"vowel"<<endl;
}else{
cout<<"consonant";
}*/

int n1,n2;
cout<<"Enter 2 numbers"<<endl;
cin>>n1>>n2;
char op;
cout<<"Enter an operator"<<endl;
cin>>op;
switch (op)
{
case '+':
   cout<<n1+n2<<endl;
    break;
case '-':
   cout<<n1-n2<<endl;
    break;
case '*':
   cout<<n1*n2<<endl;
    break;
case '/':
   cout<<n1/n2<<endl;
    break;

default:
cout<<"Enter another operator"<<endl;
    break;
}
    return 0;
}