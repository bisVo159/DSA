#include<stdio.h>

void swap(int *a,int *b){
        int temp=*a;
       * a=*b;
        *b=temp;
}
int main(){
   /* int a=10;
    int *ptr_a=&a;
    printf("The address of a is %p\n",&a);
    printf("The address of a is %p",ptr_a);*/

    int n,a[10];
    for(int i=0;i<4;i++)
    scanf("%d",a+i);
    printf("Array elements are:\n");
    for(int i=0;i<4;i++){
        printf("%d\n",*(a+i));
    }

    /*int a=2,b=4;
    int* aptr=&a;
    int* bptr=&b;
   printf("Before swapping a=%d and b=%d\n",a,b);
    swap(aptr,bptr); 
    printf("After swapping a=%d and b=%d",a,b);*/
}