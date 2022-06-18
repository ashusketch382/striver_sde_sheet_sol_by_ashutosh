//memoization
//T.C = O(n^2)
// S.C = (n)
#include<vector>
bool isPalindrome(string &str, int l, int r){
    while(l<r){
        if(str[l] != str[r])return false;
        l++;
        r--;
    }
    return true;
}
int palindrome_part(string &str, int ind, int size, vector<int> &dp){
    //base
    if(ind == size)return 0;
    if(dp[ind] != -1)return dp[ind];
    //possibility
    int pal_part = 1e9;
    for(int i = ind; i <size;  i++){
        if(isPalindrome(str, ind, i)){
            pal_part = min(pal_part, palindrome_part(str, i + 1, size, dp));
        }
    }
    return dp[ind] = 1 + pal_part;
}
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.length();
    vector<int>dp(n , -1);
    return palindrome_part(str, 0, n, dp) - 1;
}


//tabulation
// T.C. = O(n^2)
// S.C = O(n)
int palindromePartitioning(string str) {
    // Write your code here
    int n = str.length();
    vector<int>dp(n + 1 , 0);
    for(int ind = n-1; ind >=0; ind--){
        int pal_part = 1e9;
        for(int i = ind; i <n;  i++){
            if(isPalindrome(str, ind, i)){
                pal_part = min(pal_part, dp[i + 1]);
            }
        }
        dp[ind] = 1 + pal_part;
    }
    return dp[0] - 1;
}
