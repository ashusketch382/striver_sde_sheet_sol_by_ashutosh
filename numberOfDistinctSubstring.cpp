// T.C. = O(N^3)
// S.C. = O(N^2)
// First, we are generating all the possible substrings of ‘WORD’ it takes O(N^2) time, and then we are adding this substring into HashSet ‘ans', it takes O(N) time. Hence overall time complexity will be O(N ^ 3).

#include<bits/stdc++.h>
int distinctSubstring(string &word) {
    //  Write your code here.
    int n = word.length();
    set<string>s;
    for(int i = 0 ; i < n ; i++){
        string str = "";
        for(int j = i ; j < n ; j++){
            str += word[j];
            s.insert(str);
        }
    }
    return s.size();
}
