#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int i = 0, j = n-1;
    while(i < m && j >= 0){
        if(target == mat[i][j])return true;
        else if(target < mat[i][j]){
            j--;
        }
        else i++;
    }
    return false;
    // Write your code here.
}