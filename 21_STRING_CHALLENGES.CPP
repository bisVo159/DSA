#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
   /* string str="adsfihalksdjf";
   // cout<<'s'-'S'<<endl;

    //---->CONVERT  INTO UPPER CASE<----
    for(int i=0;i<str.size();i++){
        if(str[i]>='a'&&str[i]<='z')
        str[i]-=32;
    }
    cout<<str<<endl;
    //---->CONVERT TO LOWER CASE<-----
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]+=32;
        }
    }
    cout<<str<<endl;*/

    /*string s="fakjsdfhlak";
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s<<endl;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s<<endl;*/

//--->FORM THE BIGGEST NUMBER FROM NUMERICAL STRING<-----
    /*string s="498723659";
    sort(s.begin(),s.end(),greater<int>());   //greater<char>() is also applicable
    cout<<s<<endl;*/

//----->MOST REPEATED CHARACTER<-----
/*string s="fajdkhfdslfhaoifdd";
int freq[26];
for(int i=0;i<26;i++)
    freq[i]=0;
for(int i=0;i<s.size();i++)
freq[s[i]-'a']++;

char ans='a';
int maxF=0;
for(int i=0;i<26;i++)
{
     if(freq[i]>maxF)
     {
         maxF=freq[i];
         ans=i+'a';
     }
}
cout<<maxF<<"  "<<ans<<endl;*/

//------->REMOVE THE REPEATING CONSECUTIVE CHARACTERS<-------

string str="asaaaaaassdssssss";
char a[100];
a[0]=str[0];
int j=1;
for(int i=1;i<str.length();i++){
    if(str[i]!=str[i-1]){
       a[j]=str[i];
       j++;
    }
}
cout<<a;
    return 0;
}