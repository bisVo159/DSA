#include<iostream>
using namespace std;

int update(int& n){
    n++;
}

int& func(int a){
    int& ans=++a;
    return ans;
}

int getsum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=arr[i];
    return sum;
}

int main(){
  /*  int i=3;
    //create a reference variable
    int& j=i;
    cout<<i<<endl;      //3
    i++;cout<<i<<endl;    //4
    j++;cout<<i<<endl;   //5
    cout<<j<<endl;    //5
    */
   /*int n=5;
   cout<<"before "<<n<<endl;
   update(n);
   cout<<"after "<<n<<endl;
    cout<< func(n);*/

    /*char ch='q';
    cout<<sizeof(ch)<<endl;
    char* c=&ch;
    cout<<sizeof(c);*/

   /* int n;
    cin>>n;
    //variable size array
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<getsum(arr,n);*/

    //---->DYNAMIC MERORY ALLOCATION OF 2D ARRAY<-----
    /*int n;
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
    }
    //creation done

    //taking input
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    //output
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }*/

   /* int row,col;
    cin>>row>>col;
    int** arr=new int*[row];
    for(int i=0;i<row;i++)
    arr[i]=new int[col];

       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    //releasing memory
    for(int i=0;i<row;i++)
    delete []arr[i];
    delete []arr;*/

    //---->JAGGED ARRAY<-----
    int n;
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
    arr[i]=new int[i+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    //memory free
    for(int i=0;i<n;i++)
    delete []arr[i];
    delete []arr;

    return 0;
}