#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int XOR = 0, count = 0;
    int n = arr.size();
    map<int,int>mp;
    for(int i = 0 ; i<n ;i++){
        XOR = XOR ^ arr[i];
        if(XOR == x)count++;
        if(mp.find(XOR ^ x) != mp.end()){
            count += mp[XOR ^ x];
        }
        mp[XOR]++;
    }
    return count;
    //    Write your code here.
}