#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n){
    // Write your code here
    vector<int>res(n);
    stack<int>st;
    for(int i = 0 ; i< n ; i++){
        if(st.empty() || arr[st.top()] > arr[i])st.push(i);
        else{
            while(!st.empty() && arr[i] > arr[st.top()]){
                res[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        res[st.top()] = -1;
        st.pop();
    }
    return res;
}