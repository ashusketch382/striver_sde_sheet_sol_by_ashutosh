#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long int>>res(n);
//     res[0].push_back(vector<long long int>(1,1));
    for(int i = 1; i <= n ; i++){
        vector<long long int>temp(i);
        temp[0] = 1;
        temp[i-1] = 1;
        for(int j = 1; j < i-1; j++){
            temp[j] = res[i-2][j] + res[i-2][j-1];
        }
        res[i-1] = temp;
    }
    return res;
  // Write your code here.
}
