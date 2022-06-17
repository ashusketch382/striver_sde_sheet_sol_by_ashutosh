/* dp question, can be optimized using tabulation, space can ALSO BE OPTIMIZED
    Time Complexity : O(N * M)
    Space Complexity : O(N * M)
    where N and M are the lengths of str1 and str2 respectively.
*/

#include<vector>
int lcs_util(string &s, string &t, int ind1, int ind2, vector<vector<int>> &dp){
    //base
    if(ind1 <0 || ind2 < 0)return 0;
    if(dp[ind1][ind2] != -1)return dp[ind1][ind2];
    
    //possibility
    if(s[ind1] == t[ind2])return dp[ind1][ind2] = 1 + lcs_util(s, t, ind1 - 1, ind2 - 1, dp);
    return dp[ind1][ind2] = max(lcs_util(s, t, ind1 - 1, ind2, dp), lcs_util(s, t, ind1, ind2 - 1, dp));
}
int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return lcs_util(s, t, n - 1, m - 1, dp);
	//Write your code here
}