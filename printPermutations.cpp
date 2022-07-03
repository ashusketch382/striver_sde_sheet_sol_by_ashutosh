// Time Complexity
// O(N*N!), where N is the length of the String.

 

// In the worst case, there will be N! Recursion calls and for each permutation, it requires O(N) time to print. Thus the overall time complexity will be O(N*N!).

// Space Complexity
// O(N), where N is the length of the string.

 

// Because O(N) extra space is required for recursion stack and thus space complexity will be O(N).



void permut(string &s, int ind, int size, vector<string> &res){
    if(ind == size - 1){
        res.push_back(s);
        return ;
    }
    for(int i = ind; i < size; i ++){
        swap(s[ind] ,s[i]);
        permut(s, ind +1, size, res);
        swap(s[ind], s[i]);
    }
    
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>res;
    int n = s.length();
    permut(s, 0, n, res);
    return res;
}