/*
    Time Complexity: O(N * ( 2 ^ N ))
    Space Complexity: O(N ^ 2)

    Where 'N' is the length of string.
*/

bool isPalindrome(string &s, int low, int high){
    while(low < high){
        if(s[low] != s[high])return false;
        low++;
        high--;
    }
    return true;
}
void part(string  &s, int ind, int size,vector<string>&ds, vector<vector<string>> &res){
    //base
    if(ind == size){
        res.push_back(ds);
        return;
    }
    
    for(int i = ind; i <size; i++){
        if(isPalindrome(s, ind, i)){
            ds.push_back(s.substr(ind, i - ind + 1));
            part(s, i + 1, size, ds,res);
            ds.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    int size = s.length();
    
    vector<vector<string>>res;
    vector<string>ds;
    part(s, 0, size, ds, res);
    return res;
    // Write your code here.
}