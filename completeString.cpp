#include<bits/stdc++.h>
bool completeString(string str, set<string> &s, int size){
    string currStr = "";
    for(int i = 0 ; i <size; i++){
        currStr += str[i];
        if(s.find(currStr) == s.end())return 0;
    }
    return 1;
}
string completeString(int n, vector<string> &a){
    // Write your code here.
    set<string>s;
    for(int i = 0 ; i  < n ; i++){
        s.insert(a[i]);
    }
    string ans = "";
    int ansLength = ans.length();
    for(int i = 0; i < n ; i++){
        int strLength = a[i].length();
        if(completeString(a[i], s, strLength)){
            
            
            if(strLength > ansLength){
                ans = a[i];
                ansLength = strLength;
            }
            else if(strLength == ansLength){
                if(a[i] < ans)ans = a[i];
            }
        }
    }
    if(ans == "")return "None";
    return ans;
}