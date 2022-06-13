// Time Complexity
// O(N * maxDeadline)

// Space Complexity
// O(maxDeadline)

#include<bits/stdc++.h>
bool comp(vector<int>v1, vector<int>v2){
    return v1[1] > v2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    int max_deadline = 0;
    for(int i = 0 ; i < n ; i++){
       max_deadline = max(max_deadline, jobs[i][0]); 
    }
    vector<bool>time(max_deadline,false);
    int totProfit = 0;
    for(int i = 0 ; i < n ; i++){
        int deadline = jobs[i][0];
        while(deadline){
            if(!time[deadline]){
                time[deadline] = true;
                totProfit += jobs[i][1];
                break;
            }
            deadline--;
        }
    }
    return totProfit;
    // Write your code here
}



// Using Set
// In the above approach, for each index in the jobs array, we may have to traverse a boolean array of slots of size maxDeadline. However, we can optimize the above approach by using a set and applying a binary search on the elements of the set. So, we store the elements from maxDeadline to 1 in the set. We traverse the jobs array, and for each job, we find the nearest element present in the set that is less than or equal to the deadline of that job. If such an element exists in the set, then we add the profit to the answer and remove this element from the set.
/*
    Time Complexity : O(N *log max(N, maxDeadline))
    Space Complexity : O(maxDeadline)

    Where 'N' is size of the array "jobs" and 
    'maxDeadline' is the maximum among all the deadlines.
*/

#include <algorithm>
#include <set>

// Custom Comparator function to sort the jobs in the decreasing order of their profit.
bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    // Find the maximum deadline among all the jobs.
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    // Create a set "slots".
    set<int, greater<int>> slots;

    // Insert all the elements from maxDeadline to 1 into the set.
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }

    for (int i = 0; i < jobs.size(); i++)
    {

        // If the set is empty or the deadline is less than the last element of the set, then ignore this job.
        if (slots.size() == 0 || jobs[i][0] < *slots.rbegin())
        {
            continue;
        }

        int availableSlot = *slots.lower_bound(jobs[i][0]);
        maxProfit = maxProfit + jobs[i][1];
        slots.erase(availableSlot);
    }

    return maxProfit;
}
