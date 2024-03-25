#include<iostream>
using namespace std;

bool sorted(int a[],int n){
    if(a[0]>a[1])
    return (a[0]<a[1]);
    else if(n==1)           //SELFBUILD
    return (a[0]<a[1]);
      sorted(a+1,n-1);  
}

/*bool sorted(int a[],int n){
    if(n==1)
    return true;
    bool restarray=sorted(a+1,n-1);
    return (a[0]<a[1]&&restarray);
}*/

int sumarray(int a[],int n){
    if(n==0)
    return 0;
    return a[0]+sumarray(a+1,n-1);
}
void print(int a[],int n){
    cout<<"size of array is "<<n<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    } cout<<endl;
}

bool linearsearch(int a[],int n,int k){
    print(a,n);
      if(n==0)
      return false;
      else if(a[0]==k)
      return true;
     return linearsearch(a+1,n-1,k);
}
void print2(int a[],int s,int e){
       for(int i=s;i<=e;i++)
       cout<<a[i]<<" ";
       cout<<endl;
}

int binarysearch(int a[],int s,int e,int k){
    print2(a,s,e);
    if(s>e){
        return -1;
    }
    int mid=s+(e-s)/2;
    cout<<"value of mid "<<a[mid]<<endl;
    if(a[mid]==k)
    return mid;
    if(a[mid]>k)
    return binarysearch(a,s,mid-1,k);
    else
    return binarysearch(a,mid+1,e,k);
}

void dec(int n){
    if(n==0)
    return;
    cout<<n<<endl;
    dec(n-1);
}

void inc(int n){
    if(n==0)
    return;
    inc(n-1);
    cout<<n<<endl;
}

int firstocc(int arr[],int n,int i,int key){
    if(i==n){
        return -1;
    }
    if(arr[i]==key){
        return i;
    }
    return firstocc(arr,n,i+1,key);
}

int lastocc(int arr[],int n,int i,int key){
    if(i==n)
    return -1;
   int restarray=lastocc(arr,n,i+1,key);
   if(restarray!=-1){
       return restarray;
   }
   if(arr[i]==key){
       return i;
   }
   return -1;
}

int main(){
    //---->CHECK IF AN ARRAY IS SORTED OR NOT<----
 /* int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
   /*bool ans= sorted( a,n);
    if(ans)
    cout<<"array is sorted";
    else
    cout<<"array is not sorted";*/

//---->ADDITION OF ARRAY ELEMENTS<-----
//cout<<sumarray(a,n);

//---->LINEAR SEARCH<-----
/*int key=5;
bool ans=linearsearch(a,n,key);
if(ans)
cout<<"element found";
else
cout<<"element not found";*/

//---->BINARY SEARCH<----
int arr[]={2,4,6,10,14,18,22,38,49,55,222};
int key=222;
int ans=binarysearch(arr,0,10,key);
if(ans==-1)
cout<<"absent";
else
cout<<key<<" found at index "<<ans;

//----->PRINT NUMBER TILL n<------
/*int n;
cin>>n;
dec(n);
inc(n);*/

//---->FIRST AND LAST OCCURANCE OF A NUMBER<----
/*int arr[]={4,2,1,2,5,2,7};
cout<<firstocc(arr,7,0,2)<<endl;
cout<<lastocc(arr,7,0,2)<<endl;*/
    return 0;
}