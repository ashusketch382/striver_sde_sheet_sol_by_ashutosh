// memoization
int edit_distance(string &str1, string &str2, int ind1, int ind2, vector<vector<int>> &dp){
    if(ind1 < 0 && ind2 < 0)return 0;
    if(ind1 < 0)return ind2 + 1;
    if(ind2 < 0)return ind1 + 1;
    if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
    
    if(str1[ind1] == str2[ind2])return dp[ind1][ind2] = edit_distance(str1, str2, ind1 - 1, ind2 - 1, dp);
    
    int del = edit_distance(str1, str2, ind1, ind2 - 1, dp);
    int repl = edit_distance(str1, str2, ind1 - 1, ind2 - 1, dp);
    int ins =  edit_distance(str1, str2, ind1 - 1, ind2, dp);
    
    return dp[ind1][ind2] = 1 + min(del ,min(repl, ins));
}
int editDistance(string str1, string str2)
{
    int n = str1.length();
    int  m = str2.length();
    
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return edit_distance(str1, str2, n - 1, m - 1, dp);
    //write you code here
}


//tabulation
int editDistance(string str1, string str2)
{
    int n = str1.length();
    int  m = str2.length();
    
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    for(int j = 1; j <= m ; j++)dp[0][j] = j;
    for(int i = 1; i <= n ; i++)dp[i][0] = i;
    for(int ind1 = 1; ind1 <= n ;ind1 ++){
        for(int ind2 = 1; ind2 <= m; ind2++){
            if(str1[ind1 - 1] == str2[ind2 - 1])dp[ind1][ind2] = dp[ind1 - 1][ind2 - 1];
            else{
                int del = dp[ind1][ind2 - 1];
                int repl = dp[ind1 - 1][ind2 - 1];
                int ins =  dp[ind1 - 1][ind2];
                dp[ind1][ind2] = 1 + min(del ,min(repl, ins));
            }
        }
    }
    return dp[n][m];
    //write you code here
}