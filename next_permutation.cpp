// T.C. = O(3*N);
// S.C. = O(1)

#include <bits/stdc++.h> 
void reverse_permutation(vector<int> &arr, int s, int e){
    while(s < e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //finding break point
    int ind1 = -1;
    for(int i = n - 2; i >= 0; i--){
        if(permutation[i] < permutation[i + 1]){
            ind1 = i;
            break;
        }
    }
    // if this is last permuation then we will not get any ind1 such that arr[ind1] < arr[ind1 + 1]
    if(ind1 < 0){
        reverse_permutation(permutation, 0, n - 1);
        return permutation;
    }
    else{
        //finding just greater pefix
        int ind2;
        for(int i = n - 1; i >= 0 ;i--){
            if(permutation[i] > permutation[ind1]){
                ind2 = i;
                break;
            }
        }
        swap(permutation[ind1], permutation[ind2]);
        reverse_permutation(permutation, ind1 + 1, n - 1);
        return permutation;
    }
    
    //  Write your code here.
}