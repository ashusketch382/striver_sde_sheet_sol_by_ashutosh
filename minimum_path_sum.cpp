//dp question, can be optimized using tabulation

#include<bits/stdc++.h>
int path(vector<vector<int>> &grid, int row, int col, vector<vector<int>> &dp){
    //base 
    if(row < 0 || col < 0)return INT_MAX;
    if(row == 0 && col == 0)return dp[row][col] = grid[row][col];
    if(dp[row][col] != -1)return dp[row][col];
    
    int left = path(grid, row - 1, col, dp);
    int up = path(grid, row, col - 1, dp);
    return dp[row][col] = min(left, up) + grid[row][col];
    
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m, -1));
    return path(grid, n-1, m -1, dp);
}