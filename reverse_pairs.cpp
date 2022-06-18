/*
        Time Complexity: O(N * log(N))
        Space Complexity: O(N)

        Where N is the size of the array.
*/

#include <bits/stdc++.h> 
int merge(vector<int> &arr, int low, int mid, int high){
    if(low >= high)return 0;
    int inv = 0;
    int i = low, j = mid + 1;
    while(i <= mid && j <= high){
        if(arr[i] >2 * arr[j]){
            inv += mid - i + 1;
            j++;
        }
        else{
            i++;
        }
    }
    i = low, j = mid + 1;
    int ind = 0;
    vector<int>temp(high - low + 1);
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j])temp[ind++] = arr[i++];
        else temp[ind++] = arr[j++];
    }
    while(i <= mid){
        temp[ind++] = arr[i++];
    }
    while(j <= high){
        temp[ind++] = arr[j++];
    }
    
    for(int i = low; i <= mid; i++){
        arr[i] = temp[i - low];
    }
    for(int i = mid + 1; i <= high; i++){
        arr[i] = temp[i - low];
    }
    return inv;
}
int mergeSort(vector<int> &arr, int low, int high){
    //base
    if(low >= high)return 0;
    int mid = (low + high)/2;
    int left = mergeSort(arr, low, mid);
    int right = mergeSort(arr, mid + 1, high);
    
    return left + right + merge(arr, low, mid, high);
}
int reversePairs(vector<int> &arr, int n){
	// Write your code here.	
    
    int ans = mergeSort(arr, 0, n - 1);

    return ans;
}