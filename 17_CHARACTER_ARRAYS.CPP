#include"bits/stdc++.h"
using namespace std;

int main(){
  /*  char arr[100]="apple";
    int i=0;
    while(arr[i]!='\0'){
        cout<<arr[i]<<endl;
        i++;
    }*/
  //  char arr[100];
  //  cin>>arr;
   // cout<<arr;
  // cout<<arr[2];

  //----->CHECK PALINDROME<------
    /* int n;
     cin>>n;
     char arr[n+1];
     cin>>arr;
      bool check =1;
      for(int i=0;i<n/2;i++){
          if(arr[i]!=arr[n-1-i]){
              check = 0;
              break;
          }
      }
      if(check==true){
          cout<<"word is a palindrome"<<endl;
      }
      else{
          cout<<"word is not a palindrome"<<endl;
      }*/

      //------>LARGEST WORD IN A SENTENCE<-------
        int n;
        cin>>n;
        cin.ignore();
        char arr[n+1];
        cin.getline(arr,n);
       // cin.ignore();
        int i=0, currlen=0,maxlen=0;
        int st=0,maxst=0;
        while(1){
            if(arr[i]==' '||arr[i]=='\0'){
                if(currlen>maxlen){
                    maxlen=currlen;
                    maxst=st;
                }
                currlen=0;
                st=i+1;
            }
            else{
            currlen++;
            }
            if(arr[i]=='\0'){
            break;
        }
            i++;
        }
        cout<<maxlen<<endl;
        for(int i=0;i<maxlen;i++){
            cout<<arr[i+maxst];
        }
    return 0;
}