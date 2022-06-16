//dp question
//can optimized using tabulation also and space optimization also can be applied


#include<bits/stdc++.h>
int profit(vector<int>& values, vector<int> &weights, int ind, int w, vector<vector<int>>&dp){
    //base case
    if(ind < 0 || w == 0)return 0;
    if(dp[ind][w] != -1)return dp[ind][w];
    //explporing possibilities
    int notTake = profit(values, weights, ind - 1, w,dp);
    int take = INT_MIN;
    if(weights[ind] <= w)take =values[ind] + profit(values, weights, ind - 1, w - weights[ind],dp);
    return dp[ind][w] = max(take, notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>>dp(n, vector<int>(w+1, -1));
    int max_profit = profit(values, weights, n - 1, w,dp);
    if(max_profit == INT_MIN)return 0;
    return max_profit;
	// Write your code here
}