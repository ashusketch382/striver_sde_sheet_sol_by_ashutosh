/*
Time Complexity
O(N * LOG(N)), where 'N' is the size of the input array.

 

Building hash map takes O(N) and, in the worst case, building heap will take O(N * LOG(N)) time as adding an element to heap takes LOG(N) time. Hence, the total time complexity is O(N * LOG(N)).

Space Complexity
O(N).

 

The Hash map and the heap can have at most N elements. Hence, the total space complexity is O(N).
*/
#include<bits/stdc++.h>

struct myComp{
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2){
        if(p1.first == p2.first)return p1.second < p2.second;
        return p1.first < p2.first;
    }
};
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int,int>mp;
    for(int i = 0 ; i < n ; i ++)mp[arr[i]]++;
    priority_queue<pair<int,int>, vector<pair<int,int>>, myComp>pq;
    for(auto it: mp){
        pq.push({it.second, it.first});
    }
    vector<int>res;
    for(int i = 0 ; i < k; i++){
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());
    return res;
}

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the size of the input array.
*/

#include<map>
#include<algorithm>

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    map<int, int> mp;

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr) {

        mp[ele]++;
    }

    vector<int> bucket[n+1];

    for (auto x : mp) {

        int freq = x.second;

        // Add in correct bucket.
        bucket[freq].push_back(x.first);
    }

    vector<int> ans(k);
    int cur = 0;

    // Add 'K' elements to answer array starting from the rightmost bucket.
    for (int i = n; i > 0 && k > 0; i--) {

        if (bucket[i].size() == 0) {
            continue;
        }

        for (int num : bucket[i]) {

            ans[cur++] = num;
            k--;
            if(k == 0){
                break;
            }
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}