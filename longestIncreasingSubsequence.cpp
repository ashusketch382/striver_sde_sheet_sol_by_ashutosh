
#include<vector>
int lowerBound(vector<int> &v, int x){
    int n = v.size();
    int ans = 0;
    int l = 0, h = n - 1;
    while(l <= h){
        int mid = (l+h)/2;
        if(v[mid]  >= x){
            ans = mid;
            h = mid -1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int>v;
    int len = 0;
    for(int i = 0 ; i < n ; i++){
        if(v.empty() || v.back() < arr[i]){
            v.push_back(arr[i]);
            len++;
        }
        else{
            int ind = lowerBound(v, arr[i]);
            v[ind] = arr[i];
        }
    }
    return len;
    // Write Your Code here
}
