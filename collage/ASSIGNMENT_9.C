#include<stdio.h>
#include<string.h>
int main(){
    /*char str[100];
    printf("Enter the string: ");
    scanf("%s",&str);
    printf("length of str is %d\n",strlen(str));
    int i=0;
    while(str[i]!='\0'){
        i++;
    }
    printf("length of %s is %d",str,i);*/

   /*char s1[]="pnik",s2[]="anik";
    printf("strcmp(s1,s2)=%d",strcmp(s1,s2));*/

    /*char s1[10],s2[10];
    printf("Enter a string:");
    gets(s1);
    printf("\ns1=%s\n",s1);
    strcpy(s2,s1);
    printf("s2=%s",s2);*/

    char s[]="anik",rev[10];
    int count=0;
    while(s[count]!='\0'){
        count++;
        }
    int j=count-1;
    for(int i=0;i<count;i++){
         rev[i]=s[j];
        j--;
    }
    rev[j]='\0';
    printf("%s",rev);
/*char a[10];
printf("Enter a string\n");
scanf("%s",&a);
          bool check =1;
          int n=strlen(a);
      for(int i=0;i<n/2;i++){
          if(a[i]!=a[n-1-i]){
              check = 0;
              break;
          }
      }
      if(check){
          printf("string is a palindrome");
      }
      else{
          printf("string is not a palindrome");
      }*/
}