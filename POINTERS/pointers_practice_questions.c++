#include<iostream>
using namespace std;

void update(int *p){
    *p=(*p)*2;
}

void increment(int **p){
    ++(**p);
}

int main(){
    //Q1
   /* int first=8;
    int second=18;
    int *ptr=&second;
    *ptr=9;
    cout<<first<<" "<<second<<endl;*/

    //Q2
    /*int first=6;
    int *p=&first;
    int *q=p;
    (*q)++;
    cout<<first<<endl;*/

    //Q3
    /*int first=8;
    int *p=&first;
    cout<<(*p)++<<" ";
    cout<<first<<endl;*/

    //Q4
   /* int *p=0;
    int first=110;
    p=&first;
    // *p=first;
    cout<<*p<<endl;*/

    //Q5
    /*int first=8;
    int second=11;
    int *third=&second;
    first=*third;
    *third=*third+2;
    cout<<first<<" "<<second<<endl;*/

    //Q6
    /*float f=12.5;
    float p=21.5;
    float *ptr=&f;
    (*ptr)++;
    *ptr=p;
    cout<<*ptr<<" "<<f<<" "<<p<<endl;*/

    //Q7
   /* int arr[5];
    int *ptr;
    cout<<sizeof(arr)<<" "<<sizeof(ptr)<<endl;*/

    //Q8
   /* int arr[]={11,21,13,14};
    cout<<*(arr)<<" "<<*(arr+1)<<endl;*/

    //Q9
   /* int arr[6]={11,12,31};
    cout<<arr<<" "<<&arr<<endl;*/

    //Q10
   /* int arr[6]={11,21,13};
    cout<<(arr+1)<<endl;*/

    //Q11
   /* int arr[6]={11,21,31};
    int *p=arr;
    cout<<p[2]<<endl;*/

    //Q12
    /*int arr[]={11,12,13,14,15};
    cout<<*(arr)<<" "<<*(arr+3);*/

    //Q13
   /* int arr[]={11,21,31,41};
    int *ptr=arr++;
    cout<<*ptr<<endl;*/

    //Q14
   /* char ch='a';
    char* ptr=&ch;
    ch++;
    cout<<*ptr<<endl;*/

    //Q15
    /*char arr[]="abcde";
    char *p=&arr[0];
    cout<<p<<endl;*/

    //Q16
    /*char arr[]="abcde";
    char *p=&arr[0];
    p++;
    cout<<p<<endl;*/

    //Q17
   /* char str[]="babbar";
    char *p=str;
    cout<<str[0]<<" "<<p[0]<<endl;*/

    //Q18
   /* int i=10;
    update(&i);
    cout<<i<<endl;*/

    //Q19
   /* int first=110;
    int *p=&first;
    int **q=&p;
    int second=(**q)++ + 9;
    cout<<first<<" "<<second<<endl;*/

    //Q20
    /*int first=100;
    int *p=&first;
    int **q=&p;
    int second=++(**q);
    int *r=*q;
    ++(*r);
    cout<<first<<" "<<second<<endl;*/

    //Q21
    int num=110;
    int *ptr=&num;
    increment(&ptr);
    cout<<num<<endl;
    return 0;
}