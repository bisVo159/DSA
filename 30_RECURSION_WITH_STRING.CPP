#include"bits/stdc++.h"
using namespace std;
bool checkpalindrome(string s,int i,int j){
      if(i>j)
      return 1;
      if(s[i]!=s[j])
      return 0;
      i++;
      j--;
    return  checkpalindrome(s,i,j);
}

int power(int a,int b){
if(b==0)
  return 1;
  if(b==1)
  return a;
  int ans=power(a,b/2);
  if(b%2==0)
  return ans*ans;
  else
  return a*ans*ans;
}

int main(){
  /*  string name;
    cin>>name;
bool ispalindrome=checkpalindrome(name,0,name.length()-1);
if(ispalindrome)
cout<<"it is a palindrome";
else
cout<<"its not a palindrome";*/

//----->a^b<-----
/*int a,b;
cin>>a>>b;
cout<<"answer is "<<power(a,b);*/

    return 0;
}