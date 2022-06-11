#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    sort(arr.begin(), arr.end());
	// Write your code here.
    vector<vector<int>>res;
    if(arr.empty())return res;
    for(int i = 0 ; i < n ;i++){
        int target = K - arr[i];
        int start = i + 1;
        int end = n - 1;
        
        while(start < end){
            if(arr[start] + arr[end] == target){
                vector<int>temp(3);
                temp[0] = arr[i];
                temp[1] = arr[start];
                temp[2] = arr[end];
                res.push_back(temp);
                while((start + 1) < end && arr[start + 1] == arr[start])start++;
                while(start < (end - 1) && arr[end] == arr[end - 1])end--;
                start++;
                end--;
            }
            else if(target < arr[start] + arr[end])end--;
            else start++;
        }
        while((i + 1) < n && arr[i + 1] == arr[i])i++;
    }
    return res;
}