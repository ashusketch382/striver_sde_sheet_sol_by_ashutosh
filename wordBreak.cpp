// Time Complexity
// O(N^2), where N is the length of the string target.

 

// In this case, we are generating and checking all subarrays of the target string which will take O(N) time.

// Hence the overall complexity will be O(N^2). 

// Space Complexity
// O(N),  where N is the length of the string target.

 

// We are storing all strings in a hashmap which will take O(N) space.

// Hence the space complexity will be O(N).


#include<bits/stdc++.h>
int word_break(vector<string> &arr, int ind, int size, string &target, set<string> &s, vector<int> &dp){
    if(ind == size)return true;
    if(dp[ind] != -1)return dp[ind];
    
    for(int i = ind; i < size ; i++){
        if(s.find(target.substr(ind, i - ind + 1)) != s.end() && word_break(arr, i + 1, size, target, s, dp)){
            return dp[ind] = 1;
        }
    }
    return dp[ind] = 0;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    set<string>s;
    for(int i = 0 ; i < n ; i++){
        s.insert(arr[i]);
    }

    int len = target.length();
    vector<int>dp(len, -1);
    return word_break(arr, 0, len, target, s, dp);
    
}