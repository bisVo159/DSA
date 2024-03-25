#include<stdio.h>
#include<math.h>
int main(){
   // printf("Hello World");

   /*int a,b,x,y,z,d;
   printf("Enter 2 numbers\n");
   scanf("%d%d",&a,&b);
   x=a+b;
   y=a-b;
   z=a*b;
   d=a/b;
   printf("addition = %d, substruction =%d , multiplication = %d, division = %d ",x,y,z,d);*/

/*int a,b,c,d,e;
printf("Enter 2 numbers\n");
/*scanf("%d%d",&a,&b);
printf("swapping using 2 variables\n");
c=a;
a=b;
b=c;
printf("swapped numbers are %d and %d\n",a,b);

scanf("%d%d",&d,&e);
printf("swapping without using 3rd variables\n");
e=e+d;
d=e-d;
e=e-d;
printf("swapped numbers are %d and %d\n",d,e);
return 0;*/

/*float base,height,area;
printf("Enter base and height of the right angle triangle\n");
scanf("%f%f",&base,&height);
area=.5*base*height;
printf("area of the triangle is %f",area);*/

/*float c=M_PI;
printf("value of pi upto 36 decimal is:\n%.36f",c);
return 0;*/

//------>EVEN OR ODD<------
/*int a;
printf("Enter a number\n");
scanf("%d",&a);
if(a%2==0){
    printf("The number is even");
}
else{
    printf("The number is odd");
}*/

//------>LEAP OR NOT<------
/*int year;
printf("Enter a number\n");
scanf("%d",&year);
if((year%4==0&&year%100!=0)||(year%400==0)){
    printf("%d is a leap year",year);
}
else{
    printf("%d is not a leap year",year);
}*/

// ---->LARGEST AMONG 3 NUMBERS<-----
/*int a,b,c;
printf("Enter  3 numbers");
scanf("%d%d%d",&a,&b,&c);
if(a>b&&a>c){
    printf("%d is the largest",a);
}
else if(b>a&&b>c){
    printf("%d is the largest",b);
}
else
    printf("%d is the largest",c);*/

//----->REVERSE A NUMBER<------
/*int num,rev=0,rem;
printf("Enter a number\n");
scanf("%d",&num);
while(num>0){
    rem=num%10;
    rev=rev*10+rem;
    num=num/10;
}
printf("%d",rev);*/

//------>PRIME NUMBER<------
/*int n;
int flag=0;
printf("Enter a number\n");
scanf("%d",&n);
for(int i=2;i<n;i++){
    if(n%i==0){
        printf("%d is not a prime number",n);
        flag=1;
        break;
    }
}
if(flag==0){
    printf("%d is a prime",n);
}*/

//------->PRIME NUMBER IN A GIVEN RANGE<-------
/*int a,b;
printf("Enter the begining number\n");
scanf("%d",&a);
printf("Enter the last number\n");
scanf("%d",&b);
for(int j=a;j<=b;j++){
    int f=0;
    for(int i=2;i<j;i++){
        if(j%i==0){
            f=1;
        }
        }
          if(f==0){
            printf("\n%d",j);
    }
}*/

//------->ARMSTRONG NUMBER<-------
/*int rem,i;
printf("print all armstrong number upto 1000\n");
for( i=1;i<=1000;i++){
    int sum=0;
 int num=i;
while(num>0){
    rem=num%10;
    sum=sum+pow(rem,3);
    num=num/10;
}
if(i==sum){
    printf("%d\n",i);
}
}*/

//------>FACTORIAL<------
/*int n,fact=1;
printf("Enter a number\n");
scanf("%d",&n);
for(int i=n;i>=1;i--){
    fact=fact*i;
}
printf("factorial of the given number is %d",fact );*/

//------->MULTIPLICATION TABLE<----------
/*int n;
printf("Enter an integer\n");
scanf("%d",&n);
for(int i=1;i<=50;i++){
    printf("%d*%d=%d\n",n,i,n*i);
}*/

//------>FIBONACCI SERIES<-------
// int a=0,b=1,n,nextterm;
// printf("Enter the limit of the fibonacci series:\n");
// scanf("%d",&n);
// while(a<=n){
//     printf("%d\n",a);
//     nextterm=a+b;
//     a=b;
//     b=nextterm;
// }

//------->ARMSTRONG NUMBER<-------
/*int rem,i,originalno;
printf("print all armstrong number upto 10000\n");
for( i=1;i<=10000;i++){
    int n=0;
    originalno=i;
    while(originalno>0){
        originalno/=10;
        n++;
    }
    int sum=0;
 int num=i;
while(num>0){
    rem=num%10;
    sum=sum+pow(rem,n);
    num=num/10;
}
if(i==sum){
    printf("%d\n",i);
}
}*/

int k=2;
for(int i=1;i<=5;i++){
    i*=k;
    printf("%d",i);
}
return 0;
}