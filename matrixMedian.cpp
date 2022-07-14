// Time Complexity
// O(N * log(M) * log(MAX - MIN) ), where ‘N’ is the number of rows and ‘M’ is the number of columns in the given matrix. And MAX and MIN are the minimum and maximum elements of the matrix, respectively.

 

// At each iteration of the outer loop (which runs until “low” is equal to “high”), we are iterating through every row and doing a binary search on it. Since there are ‘M’ elements in each row, the upper_bound() function will take O(log(M)) time. And we’ll be doing ‘N’ number of such operations in each iteration. Therefore, it will take O(N * log(M) ) time for each iteration. 


// And the outer loop which is again a binary search will run for O(log(MAX - MIN)) time. Therefore, the overall time complexity will be O(N * log(M) * log(MAX - MIN) ).

// Space Complexity
// O(1).

 

// Since we are not using any extra space, we are only doing the binary search. So, the overall space complexity will be O(1).


int matrixCount(vector<int>&row, int x){
    int ans = 0;
    int l = 0;
    int r = row.size() - 1;
    
    while(l <= r){
        int mid = (l+r) >> 1;
        if(x >= row[mid]){
            ans = mid + 1;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return ans;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    int l = 1;
    int r = 10e5;
    while(l <= r){
        int mid = (l + r)>>1;
        int count = 0;
        for(int i = 0 ; i < n; i++){
            count += matrixCount(matrix[i], mid);
        }
        if(count <= (m*n)/2) l = mid + 1;
        else r = mid - 1;
    }
    return l;
    // Write your code here.
}