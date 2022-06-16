//dp question, can be optimized using tabulation
int maxProfit(vector<int> &price,int ind, int len, vector<vector<int>>&dp){
    //base
    if(len == 0)return 0;
    if(ind ==0){
        return dp[ind][len] = len * price[ind];
    }
    if(dp[ind][len] != -1)return dp[ind][len];
    //possibility
    int notTake = maxProfit(price,ind - 1, len,dp);
    int take = INT_MIN;
    if(ind + 1 <= len)
        take =price[ind] + maxProfit(price,ind, len -(ind + 1), dp);
    return dp[ind][len] = max(take, notTake);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n, vector<int>(n + 1, -1));
    return maxProfit(price,n - 1, n,dp);
	// Write your code here.
}
