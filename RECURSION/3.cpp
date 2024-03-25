#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// void reverse(string &s,int i,int j){
//     if(i>=j)
//     return;

//     swap(s[i],s[j]);
//     reverse(s,i+1,j-1);
// }
void reverse(string &s,int i){
    if(i==s.length())
    return;

    reverse(s,i+1);
    cout<<s[i];
}

void subsequences(string &s,int i,string str){
    if(i==s.length()){
        cout<<str<<endl;
        return;
    }

    subsequences(s,i+1,str+s[i]);
    subsequences(s,i+1,str);
}

string add2str(string a,string b,int carry){
    if(a.length()==0&&b.length()==0&&carry==0)
        return "";
    if(a.length()==0&&b.length()==0&&carry!=0)
        return to_string(carry);

    if(a.length()==0&&b.length()!=0)
        return add2str(b,to_string(carry),0);

    if(b.length()==0&&a.length()!=0)
        return add2str(a,to_string(carry),0);

    int x=a[0]-'0';
    int y=b[0]-'0';
    string ans=to_string((x+y)%10+carry)+add2str(a.substr(1),b.substr(1),(x+y)/10);
    return ans;
}

void addstring(string a,string b,int carry,string &ans,int i,int j){
    if(i<0&&j<0&&carry==0){
        return;
    }
    int first=0;
    int second=0;
    if(i>=0)
    first=a[i]-'0';
    if(j>=0)
    second=b[j]-'0';
    int sum=first+second+carry;
    int lastdigit=sum%10;
    carry=sum/10;
    ans.push_back(lastdigit+'0');
    addstring(a,b,carry,ans,i-1,j-1);
}

int main(){
    // string s="anik";
    // reverse(s,0,s.length()-1);
    // cout<<s<<endl;
    // reverse(s,0);cout<<endl;

    // subsequences
    // string s="abc";
    // string str="";
    // subsequences(s,0,str);

    // add 2 string
    string a="87";
    string b="933";
    // reverse(a.begin(),a.end());
    // reverse(b.begin(),b.end());
    // string ans=add2str(a,b,0);
    //  reverse(ans.begin(),ans.end());
    // cout<<"Sum is "<<"Addition of 2 string "<<ans<<endl;

    string ans="";
    addstring(a,b,0,ans,a.length()-1,b.length()-1);
    reverse(ans.begin(),ans.end());
    cout<<"Sum is "<<ans<<endl;
    
    return 0;
}