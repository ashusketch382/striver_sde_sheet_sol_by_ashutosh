// Time Complexity
// O(N), where N is the number of elements in the given array/list.

 

// Since we will be adding and removing every element of the array in the window at most once during the whole process and in the deque, push and the pop operation from the front or back operation takes O(1) time. So the overall time complexity will be O(N).

// Space Complexity
// O(N), where N is the length of the given array/list.

 

// Since we are using a deque to store the elements of the window, and the length of the window is K. And also we are using an array/list to store the maximum element of each window of length K. And there can be N - K + 1 such window. So the overall space complexity will be O(N).


#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    vector<int>res;
    deque<int>dq;
    for(int i = 0 ; i < n ; i++){
        if(!dq.empty() && dq.front() == (i - k))dq.pop_front();
        while(!dq.empty() && nums[dq.back()] <= nums[i])dq.pop_back();
        dq.push_back(i);
        if(i >= (k-1))res.push_back(nums[dq.front()]);
    }
    return res;
    //    Write your code here.
}