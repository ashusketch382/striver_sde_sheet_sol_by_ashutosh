//Brute Force
// T. C. = O(2^n)
//S.C. = O(n)


void f(vector<int> &num, int sum, int ind, vector<int> &res){
    //base case
    if(ind < 0){
        res.push_back(sum);
        return;
    }
    
    //notTake
    f(num, sum, ind - 1, res);
    //take
    f(num, sum + num[ind], ind - 1, res);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int>res;
    int n = num.size();
    sort(num.begin(), num.end());
    f(num, 0, n - 1, res);
    sort(res.begin(), res.end());
    return res;
    // Write your code here.
}



//optimisatoin(bitmasking + iteration)
/*
    Time Complexity:  O( (2^N)*N ).
    Space Complexity:O( 1 ).

    Where 'N' is the size of the array.
*/

vector<int> subsetSum(vector<int> &num)
{
    int n = num.size();
    // Ans vector contains all the subset sums.
    vector<int> ans;

    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            // Checking wheather the element is present the subset or not.
            if ((1 << j) & i)
            {
                sum += num[j];
            }
        }
        ans.push_back(sum);
    }
    // Sort the vector and finally return it.
    sort(ans.begin(), ans.end());
    return ans;
}