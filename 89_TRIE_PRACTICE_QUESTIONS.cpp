#include<iostream>
#include<vector>
using namespace std;

/*string largestCommonPrefix(vector<string>&arr,int n){
    //for traversing all character of first string
    string ans="";
    for(int i=0;i<arr[0].length();i++){
        char ch=arr[0][i];

        bool match=true;
        //for comparing character with rest of the string
        for(int j=1;j<n;j++){
            if(arr[j].size()<i||ch!=arr[j][i]){
            match=false;
            break;
            }
        }
        if(!match)
        break;
        else
        ans.push_back(ch);
    }
    return ans;
}*/

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTarminal;
    int childCount;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
        children[i]=NULL;
        }
        childCount=0;
        isTarminal=false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(){
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTarminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->childCount++;
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch=str[i];

            if(root->childCount==1){
                ans.push_back(ch);
                //aage badh jao
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isTarminal){
                break;
            }
        }
    }
};

string largestCommonPrefix(vector<string>&arr,int n){
    Trie* t=new Trie();
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }
    string first=arr[0];
    string ans="";
    t->lcp(first,ans);
    return ans;
}

int main(){
    //----->LARGEST COMMON PREFIX<-----
    // vector<string>a={"coding","codezen","codingninja","coders"};
    vector<string>a={"ninja","night","nil"};
    string str=largestCommonPrefix(a,3);
    cout<<str<<endl;

    return 0;
}