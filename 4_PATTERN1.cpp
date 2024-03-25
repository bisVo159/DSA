#include<iostream>
using namespace std;
int main(){
   // int rows,columns;
   // cin>>rows>>columns;
    // -------> RACTANGLE PATTERN <--------
    /*
    for(int i=1;i<=rows;i++){
            for(int j=1;j<=columns;j++){
                cout<<"*";
            }
            cout<<endl;
    }*/
    // ---------> HOLLOW RACTANGLE PATTERN <----------
   /* for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++){
            if(i==1||i==rows){
                cout<<"*";
            }
            else if(j==1||j==columns){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }*/

    // -------> INVERTED HALF PYRAMID <----------
      
      int n;
      cin>>n;
    /*for(int i=5;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/
    // ------> HALF PYRAMID AFTER 180 ROTATION <---------
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<=n-i){
                cout<<" ";
            }
            else{
                cout<<"*";
            }
        }
        cout<<endl;
    }*/
    // -------> HALF PYRAMID USING NUMBER <-------
   /* for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }*/
    //-------> FLOYD'S TRIANGLE  <----------
    /*int count=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<count<<"  ";
            count++;
        }
        cout<<endl;
    }*/

    // ---------> BUTTERFLY PATTERN <-----------
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        int space=2*n-2*i;
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
          for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout<<"*" ;
        }
        int space=2*n-2*i;
        for(int j=1;j<=space;j++){
            cout<<" ";
        }
          for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }*/

    //------>HOLLOW DIAMOND INSCRIBED IN A RECTANGLE<-------
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++) {
            cout<<"*";
        }
    for(int j=1;j<=2*i-1;j++){
        if(j==1||j==2*i-1){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
       for(int j=1;j<=n-i;j++) {
            cout<<"*";
        } 
        cout<<endl;  
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=n-i;j++) {
            cout<<"*";
        }
    for(int j=1;j<=2*i-1;j++){
        if(j==1||j==2*i-1){
            cout<<"*";
        }
        else{
            cout<<" ";
        }
    }
       for(int j=1;j<=n-i;j++) {
            cout<<"*";
        } 
        cout<<endl;  
    }

    // --------> HOLLOW BUTTERFLY PATTERN <--------
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1||j==i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for(int j=1;j<=2*n-2*i;j++){
            cout<<" ";
        }
         for(int j=1;j<=i;j++){
            if(j==1||j==i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            if(j==1||j==i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        for(int j=1;j<=2*n-2*i;j++){
            cout<<" ";
        }
         for(int j=1;j<=i;j++){
            if(j==1||j==i){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }*/
   return 0; 
    }
    
