#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    set<char>s;
    int n = input.length();
    int i = 0, j = 0;
    int max_len = 0;
    while(j < n){
        while(s.find(input[j]) != s.end()){
            s.erase(input[i]);
            i++;
        }
        max_len = max(max_len, j - i + 1);
        s.insert(input[j]);
        j++;
    }
    return max_len;
    //Write your code here
}