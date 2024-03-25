#include<stdio.h>
int fact(int n){
    int f=1;
    for(int i=1;i<=n;i++){
        f*=i;
    }
    return f;
}
void fib(int n){
    int a=0,b=1,c;
    while(a<=n){
        printf("%d\n",a);
        c=a+b;
        a=b;
        b=c;
    }
}

void swap(int a,int b){
    a=a^b;
    b=a^b;
    a=a^b;
    printf("The value of a and b after swaping in swap function are %d and %d",a,b);
}
int addition(int n1,int n2){
    return(n1+n2);
}
int substruction(int n1,int n2){
    return(n1-n2);
}

int factorial(int n){
    if(n==1)
    return 1;
    return n*factorial(n-1);
}

int GCD(int n1,int n2){
    if(n2!=0)
    return GCD(n2,n1%n2);
    return n1;
}

int sum(int a[],int x,int n){
    if(x==n)
    return 0;
      return(a[x]+sum(a,x+1,n));
}
int main(){
    /*int n;
    printf("Enter a number to calculate it's factorial\n");
    scanf("%d",&n);
    printf("Factorial of %d = %d",n,fact(n));*/

    /*int n;
    printf("Enter range:");
    scanf("%d",&n);
    printf("The fibonacci series is: \n");
    fib(n);*/

    /*int a,b;
    printf("Enter two numbers:\n");
    scanf("%d%d",&a,&b);
    printf("The value of a and b in the main function before calling the swap function are %d and %d\n",a,b);
    swap(a,b);*/

   /* int n1,n2;
    printf("Enter two numbers\n");
    scanf("%d%d",&n1,&n2);
    printf("%d + %d = %d\n",n1,n2,addition(n1,n2));
    printf("%d - %d = %d\n",n1,n2,substruction(n1,n2));*/

    /*int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    printf("%d! = %d",n,factorial(n));*/

    int n1,n2;
    printf("Enter two positive integers\n" );
    scanf("%d%d",&n1,&n2);
    printf("G.C.D of %d and %d is %d",n1,n2,GCD(n1,n2));

    /*int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("sum of array elements = %d",sum(a,0,n));*/
    
}