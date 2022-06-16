//dp question, can be optimized using tabulation, also space
//optimization can be done
#include<vector>
long ways(int *denominations, int ind, int value, vector<vector<long>>&dp){
    //base 
    if(value == 0)return dp[ind][value] = 1LL;
    if(ind == 0)return dp[ind][value] = value % denominations[ind] == 0;
    if(dp[ind][value] != -1)return dp[ind][value];
    //possibility
    long notTake = ways(denominations, ind - 1, value, dp);
    long take = 0;
    if(denominations[ind] <= value)take = ways(denominations, ind, value - denominations[ind], dp);
    return dp[ind][value] = take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>>dp(n, vector<long>(value + 1, -1));
    return ways(denominations, n -1 ,value, dp);
    
    //Write your code here
}