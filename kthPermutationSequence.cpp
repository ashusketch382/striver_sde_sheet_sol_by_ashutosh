/*
Time Complexity
O(N ^ 2), where ‘N’ is the length of each string. 

 

In each case, we are removing the chosen digit from the array of digits which takes O(N) time and there are ‘N’ such digits. Hence the time complexity is O(N ^ 2).

Space Complexity
O(N), where N is the length of each string.

 

Since we are storing all numbers from 1 to ‘N’ in the array. Hence the space complexity is O(N). 


*/
string kthPermutation(int n, int k) {
    // Write your code here.
    vector<int>numbers;
    int fact = 1;
    for(int i = 1; i <= n ; i ++){
        numbers.push_back(i);
        fact *= i;
    }
//     numbers.push_back(n);
    k--;
    string ans = "";
    while(n){
        fact /= n;
        int index = k / fact;
        ans += to_string(numbers[index]);
        for(int i = index; (i+1) < n ; i++)numbers[i] = numbers[i+1];
        k = k % fact;
        n--;
    }
    return ans;
}