// next greater element concept used in this question from n-1 to 0
#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    int n = price.size();
    vector<int>res(n);
    
    stack<int>st;
    for(int i = n-1 ; i >= 0; i--){
        if(st.empty() || price[i] < price[st.top()])st.push(i);
        else{
            while(!st.empty() && price[i] > price[st.top()]){
                res[st.top()] = st.top() - i;
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        res[st.top()] = st.top() + 1;
        st.pop();
    }
    return res;
}