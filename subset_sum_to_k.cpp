// Time Complexity
// O((2^N)* N)

// Space Complexity
// O( 1 )
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>>res;
    
    for(int i = 0 ; i < (1<<n); i++){
        vector<int>temp;
        int sum = 0;
        for(int j =0 ; j <n ; j++){
            if(i & (1 << j)){
                temp.push_back(arr[j]);
                sum += arr[j];
            }
        }
        if(sum == k)res.push_back(temp);
        
    }
    return res;
    // Write your code here.
}