//dp can be optimized using tabulation

bool subsetSum(vector<int>&arr, int ind, int target, vector<vector<int>> &dp){
    //base 
    if(target == 0)return 1;
    if(ind == 0)return dp[ind][target] = arr[ind] == target;
    if(dp[ind][target] != -1)return dp[ind][target];
    
    //possibility
    bool notTake = subsetSum(arr, ind - 1, target, dp);
    bool take = false;
    if(arr[ind] <= target)take = subsetSum(arr, ind - 1, target - arr[ind], dp);
    return dp[ind][target] = take | notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n , vector<int>(k + 1, -1));
    return subsetSum(arr, n -1, k, dp);
}