#include<stdio.h>
int jumble(int x,int y){
    x=2*x+y;
    return x;
}
 int main(){
    //printf("%d",strcmp("cat","cnt"));
   // int a[5]={5,1,15,20,25};
    /*int i,j,k;
    i=++a[1];
    j=a[1]++;
    k=a[i++];
    printf("%d %d %d",i,j,k);*/
    /*int i=3;
    char arr[]={'i','e','m','k','o','l','k','a','t','a'};
    printf("%c",arr[-i]);*/
    /*char* ptr;
    char mystring[]={"abcdefg"};  
    ptr=mystring;
    ptr+=5;
    printf("%s",ptr);*/
   /* int x=2,y=5;
    y=jumble(y,x);
    x=jumble(y,x);
    printf("%d",x);*/
    /*int arr[10];
    for(int i=0;i<10;i++)
    arr[i*2]=1;
    for(int i=0;i<10;i++)
    arr[i*2+1]=-1;
    for(int i=0;i<10;i++)
    printf("%d",arr[i]);*/
   /* int a[]={2,4,6,8,10};
    int i,sum=0,*b=a+4;
    for(int i=0;i<5;i++)
    sum=sum+(*b-i)-*(b-i);
    printf("%d",sum);*/
   /*int arr[]={1,2,3,4,5,6,7,8,9,0,1,2,5},*ip=arr+4;
    printf("%d\n",ip[3]);*/
   /* int a[3]={10,12,14};
    int i=0;
    while(i<3){
        printf("%d\n",i[a]);
        i++;
    }*/
   /* char s[]="anik";
    int count=0;
    while(s[count]!='\0'){
        s[count++];
    }
    printf("length of %s is %d",s,count);*/
    /*char s[]="anik",a[100];
    int i=0;
    while(s[i]!='\0'){
         a[i]=s[i];
         i++;
    }
    printf("%s",a);*/
    /*int n1,n2,max;
    scanf("%d%d",&n1,&n2);
    max=n1>n2?n1:n2;
    while(1){
        if(max%n1==0&&max%n2==0){
            printf("%d %d %d",n1,n2,max);
            break;
        }
        max++;
    }*/
}