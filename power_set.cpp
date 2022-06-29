#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
    int n = v.size();
    vector<vector<int>>res;
    for(int i = 0 ; i < (1 << n); i++){
        vector<int>temp;
        for(int j = 0 ; j < n; j++){
            if(i & (1 << j))temp.push_back(v[j]);
        }
        sort(temp.begin(), temp.end());
        res.push_back(temp);
    }
    return res;
    //Write your code here
}