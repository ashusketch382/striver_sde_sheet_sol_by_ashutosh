#include <bits/stdc++.h> 

long long merge(long long *arr, int left, int mid, int right){
    long long inv = 0;
    long long temp[right - left + 1];
    int i = left, j = mid, k = 0;
    while(i <= (mid - 1) && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            inv += mid - i;
        }
    }
    while(i <= mid - 1){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for(int i = 0; i <= right - left ; i ++){
        arr[i + left] = temp[i];
    }
    return inv;
}
long long mergeSort(long long *arr, int s, int e){
    //base case
    if(s >= e)return 0;
    
    int mid = s + (e-s)/2;
    long long left = mergeSort(arr, s, mid);
    long long right = mergeSort(arr, mid + 1, e);
    
    long long inversions = merge(arr, s, mid+1, e);
    return left + right + inversions;
    
}
long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n - 1);
}