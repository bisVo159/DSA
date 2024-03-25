//#include<bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

void reverse(string s){
    if(s.length()==0)
    return;
    string ros=s.substr(1);
    reverse(ros);
    cout<<s[0];
}

void reverse2(string& s,int i,int j){
    cout<<"call received for "<<s<<endl;
    if(i>j){ 
       // cout<<s;
        return;
    }
    swap(s[i],s[j]);
    reverse2(s,++i,--j);
}

void replacepi(string s){
    if(s.length()==0)
    return;
    if(s[0]=='p'&&s[1]=='i'){
        cout<<"3.14";
         replacepi(s.substr(2));
    }
    else{
        cout<<s[0];
         replacepi(s.substr(1));
    }
}

void towerofHonoi(int n,char src,char helper,char dest){
    if(n==0){
    return;
    }
     towerofHonoi(n-1,src,dest,helper);
     cout<<"Move from "<<src<<" to "<<dest<<endl;
     towerofHonoi(n-1,helper,src,dest);
}

string removeDup(string s){
    if(s.length()==0)
    return "";
    char ch=s[0];
    string ans=removeDup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return (ch+ans);
}

string moveallx(string s){
    if(s.length()==0)
    return "";
    char ch=s[0];
    string ans=moveallx(s.substr(1));
    if(ch=='x')
    return ans+ch;
    return ch+ans;
}

void subseq(string s,string ans){
    if(s.length()==0){
    cout<<ans<<endl;
    return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    subseq(ros,ans);
    subseq(ros,ans+ch);
}
void subsequences(string str,int idx,string newstring){
    if(idx==str.length()){
        cout<<newstring<<endl;
        return;
    }
     char currchar=str[idx];
    //to be
    subsequences(str,idx+1,newstring+currchar);
    //not to be
    subsequences(str,idx+1,newstring);
}

void subseqAscii(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    int code=ch;
    string ros=s.substr(1);
    subseqAscii(ros,ans);
    subseqAscii(ros,ans+ch);
    subseqAscii(ros,ans+to_string(code));
}

/*string keypadArr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string s,string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    string code=keypadArr[ch-'s0'];
    string ros=s.substr(1);
    for(int i=0;i<code.length();i++){
        keypad(ros,ans+code[i]);
    }
}*/

int main(){
    //----->REVERSE A STRING<-----
  //reverse("anik");
  /*string name;
  cin>>name;
  reverse2(name,0,name.length()-1);
  cout<<name;*/
  
  //----->REPLACE PI WITH 3.14 IN STRING<------
    //replacepi("pippxxppiixipi");

    //----->TOWER OF HONOI<------
//towerofHonoi(2,'A','B','C');

//------>REMOVE ALL DUPLICATES FROM THE STRING<------
//cout<<removeDup("aaaabbbeeecddd");

//----->MOVE ALL x TO THE END OF THE STRING<-----
//cout<<moveallx("axxbdxcefxhix");

//---->GENERATE ALL SUBSTRING OF A STRING<-----
//subseq("ABC","");
//subsequences("ABC",0,"");

//----->GENERATE SUBSTRINGS WITH ASCII<-----
//subseqAscii("AB","");

//---->PRINT ALL THE POSSIBLE WORDS FROM PHONE DIGITS<----
//keypad("23","");
    return 0;
}