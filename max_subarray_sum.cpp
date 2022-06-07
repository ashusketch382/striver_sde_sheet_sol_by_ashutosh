#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long maxi = -1e18;
    long long maxi_so_far = 0;
    for(int i = 0; i < n ; i++){
        maxi_so_far += arr[i];
        if(maxi_so_far < 0)maxi_so_far = 0;
        maxi = max(maxi, maxi_so_far);
    }
    return maxi;
}