//bitwise method

// Time Complexity
// O( N * 2^N )

// Space Complexity
// O(2^N )

#include<bits/stdc++.h>
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    
    vector<vector<int>>res;
    set<vector<int>>s;
    for(int i = 0;i < (1 << n); i++){
        vector<int>temp;
        for(int j = 0; j < n; j++){
            if((1 << j) & i){
                temp.push_back(arr[j]);
            }
        }
        sort(temp.begin(), temp.end());
        if(s.find(temp) == s.end())s.insert(temp);
    }
    for(auto it: s)res.push_back(it);
    return res;
    // Write your code here.
}

