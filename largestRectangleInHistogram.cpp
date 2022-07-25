/*
T.C. = O(5*N) => 5 traversals
S.C. = O(3*N) 
*/
#include<bits/stdc++.h> 
int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int rect = INT_MIN;
     int n = heights.size();
     vector<int>left(n, -1);
     vector<int>right(n, n);
     stack<int>s;
     for(int i = 0; i < n; i ++){
         while(!s.empty() && heights[s.top()] > heights[i]){
             right[s.top()] = i;
             s.pop();
         }
         s.push(i);
     }
     while(!s.empty())s.pop();
     for(int i = n -1; i >= 0 ; i--){
          while(!s.empty() && heights[s.top()] > heights[i]){
             left[s.top()] = i;
             s.pop();
         }
         s.push(i);
     }
     for(int i = 0 ; i <n ; i++){
         int l = left[i];
         int r = right[i];
         if(l == -1)rect = max(rect, heights[i] * r);
         else rect = max(rect, heights[i] * (r - l - 1));
     }
     return rect;
 }


//Optimized approach
// T.C. = O(2*N)  => 2 traversals(one time pushing in stack and one time poping)
// S.C. = O(N)

#include<bits/stdc++.h>
int largestRectangle(vector < int > & heights) {
   // Write your code here.
     int rect = INT_MIN;
     stack<int>st;
     int n = heights.size();
     for(int i = 0 ; i < n ; i++){
         while(!st.empty() && heights[i] < heights[st.top()]){
             int r = i;
             int curr = st.top();
             st.pop();
             if(st.empty())rect = max(rect, heights[curr] * r);
             else{
                 int l = st.top();
                 rect = max(rect, heights[curr] * (r - l - 1));
             }
         }
         st.push(i);
     }
     while(!st.empty()){
         int r = n;
         int curr = st.top();
         st.pop();
         if(st.empty())rect = max(rect, heights[curr] * n);
         else{
            int l = st.top();
            rect = max(rect, heights[curr] * (r - l - 1));
         }
     }
     return rect;
 }
