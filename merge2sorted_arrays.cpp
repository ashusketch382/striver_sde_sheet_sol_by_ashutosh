#include <bits/stdc++.h> 
int getGap(int gap){
    if(gap <= 1)return 0;
    return (gap/2) + (gap%2);
}
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    for(int gap = getGap(m+n); gap>0; gap=getGap(gap)){
        int i,j;
        for(i=0;i+gap<m;i++){
            if(arr1[i] > arr1[i+gap])swap(arr1[i],arr1[i+gap]);
        }
        for(j = gap>m?gap-m:0; i<m && j<n; j++, i++){
            if(arr1[i] > arr2[j])swap(arr1[i], arr2[j]);
        }
        if(j<n){
            for(int j = 0 ; j + gap< n ;j++){
                if(arr2[j]> arr2[j+gap])swap(arr2[j], arr2[j+gap]);
            }
        }
    }
    vector<int>res;
    for(int i = 0 ; i <m ; i++)res.push_back(arr1[i]);
    for(int j = 0 ; j < n; j++)res.push_back(arr2[j]);
    return res;
	// Write your code here.
}