#include<stdio.h>
#include<limits.h>
int main(){
    /*int n;
    printf("Enter size of an array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter %d elements in the array: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("\nElements in array are: ");
    for(int i=0;i<n;i++){
        printf("\n%d",a[i]);
    }*/

   /* int a[5],sum=0;
    float avg;
    printf("Enter 5 numbers\n");
    for(int i=0;i<5;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<5;i++){
        sum=sum+a[i];
    }
    avg=sum/5;
    printf("sum of 5 given numbers= %d\n",sum);
    printf("average of 5 given numbers= %.2f",avg);*/

    /*int a[10],maxNo=INT_MIN;
    printf("Enter 10 numbers\n");
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<10;i++){
        if(a[i]>maxNo)
        maxNo=a[i];
    }
    printf("maximun  among 10 given numbers is %d",maxNo);*/

/*int a[10],key,i;
printf("Enter array elements\n");
for( i=0;i<10;i++){
    scanf("%d",&a[i]);
}
printf("Enter an element to be searched\n");
scanf("%d",&key);
for( i=0;i<10;i++){
    if(a[i]==key)
    break;
}
if(i<10)
printf("Element found at index %d",i);
else
printf("Element not found");*/

/*int n,a[100],s,e,mid,key;
printf("Enter number of arrray elements\n");
scanf("%d",&n);
printf("Enter array elements\n");
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("Enter an element to be  searched\n");
scanf("%d",&key);
s=0;
e=n;
while(s<=e){
    mid=(s+e)/2;
    if(a[mid]==key){
        printf("%d found at index %d",key,mid);
        break;
    }
    else if(a[mid]>key)
    e=mid-1;
    else
    s=mid+1;
}
if(s>e)
printf("%d is not present in the list",key);*/

int n,counter=1;
printf("Enter length of array\n");
scanf("%d",&n);
printf("Enter array elements\n");
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
while(counter<n){
    for(int i=0;i<n-counter;i++){
        if(a[i]>a[i+1]){
            int temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    counter++;
}
printf("Array after implementing bubble sort:\n");
for(int i=0;i<n;i++){
    printf("%d\n",a[i]);
}
}