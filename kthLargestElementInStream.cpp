/*
Time Complexity
O(N * log(K)), where ‘N’ is the maximum number of integers we are reading at run time and ‘K’ is the order of the required number in sorted order.

 

To insert an element into the queue of size N takes logN time, and as per the approach, the maximum size of the queue will be equal to ‘K’.

Space Complexity
O(N), where ‘N’ is the maximum number of integers we are reading at run time.

 

As priority queue Is being used to store the elements of the array Therefor, overall space complexity will be O(N)

*/
#include<bits/stdc++.h>
class Kthlargest {
public:
    int size;
    int K;
    priority_queue<int, vector<int>, greater<int>>q;
    Kthlargest(int k, vector<int> &arr) {
        size = arr.size();
        K = k;
        int i;
        for(i = 0 ; i < K && i < size; i++){
            q.push(arr[i]);
        }
        if(i != size){
            for(int i = K ;i < size; i++){
                if(q.top() < arr[i]){
                    q.pop();
                    q.push(arr[i]);
                }
            }
        }
       // Write your code here.
    }

    void add(int num) {
        if(size < K){
            q.push(num);
            return ;
        }
        if(q.top() < num){
            q.pop();
            q.push(num);
        }
        // Write your code here.
    }

    int getKthLargest() {
        return q.top();
       // Write your code here.
    }

};