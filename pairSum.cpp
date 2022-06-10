#include <bits/stdc++.h>
bool comp(vector<int>v1, vector<int>v2){
    if(v1[0] == v2[0])return v1[1] < v2[1];
    return v1[0] < v2[0];
}
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    map<int,int>mp;
    vector<vector<int>>res;
    int n = arr.size();
    for(int i = 0 ; i < n ; i++){
        if(mp.find(s - arr[i]) != mp.end()){
            for(int c = 0 ; c < mp[s - arr[i]] ; c++){
                vector<int>temp(2);
                temp[0] = min(arr[i], s - arr[i]);
                temp[1] = max(arr[i], s - arr[i]);
                res.push_back(temp);
            }
        }
        mp[arr[i]]++;
    }
    sort(res.begin(), res.end(), comp);
    return res;
}