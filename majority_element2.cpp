#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    vector<int>res;
    int n = arr.size();
    int firstMajor = 0, secondMajor = 0;
    int firstCount = 0,secondCount = 0;
    for(int i = 0 ; i<n ;i++){
        if(firstMajor == arr[i])firstCount++;
        else if(secondMajor == arr[i])secondCount++;
        else if(firstCount == 0){
            firstMajor = arr[i];
            firstCount = 1;
        }
        else if(secondCount == 0){
            secondMajor = arr[i];
            secondCount = 1;
        }
        else{
            firstCount--;
            secondCount--;
        }
    }
        secondCount = 0;
        firstCount = 0;
        for(int i = 0 ; i < n; i++){
            if(secondMajor == arr[i])secondCount++;
            else if(firstMajor == arr[i])firstCount++;
        }
        if(firstCount > n/3)res.push_back(firstMajor);
        if(secondCount > n/3)res.push_back(secondMajor);
        return res;
    // Write your code here.

}