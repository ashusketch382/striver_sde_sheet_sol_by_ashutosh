// T.C. = O(N^2log(N^2))
// S.C. = O(N^2)

#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    vector<int>res;
    vector<int>sums;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            sums.push_back(a[i] + b[j]);            
        }
    }
    sort(sums.begin(), sums.end(), greater<int>());
    for(int i = 0 ; i < k ; i++)res.push_back(sums[i]);
    return res;
}


/*
    Time Complexity: O(N * log(N))
    Since we are sorting the given arrays/lists which takes O(N * log(N)) time. Then, we are using a max-heap which, in the worst case, can contain ‘N’ elements. The operations on heap will require O(N * log(N)) time. The look-up in the set can be done in log(N) time. Thus, the time complexity will be O(N * log(N)). 
    Space Complexity: O(N)

    Where 'N' is the number of elements the given arrays.
*/

#include<queue>
#include<set>
#include<algorithm>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Sorting the arrays.
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	// Using a max-heap.
	priority_queue<pair<int, pair<int, int>>>maxHeap; 
	maxHeap.push({a[n-1] + b[n-1], {n - 1, n - 1}});
	
	// Using a set.
	set<pair<int, int>>mySet; 
	mySet.insert({n - 1, n - 1}); 
	
	// Output array to store the K max sum combinations.
	vector<int> result; 
	
	while(k > 0){
		pair<int, pair<int, int>> top = maxHeap.top();
		
		// Remove the root of the max heap.
		maxHeap.pop();
		
		int sum = top.first;
		int x = top.second.first; 
		int y = top.second.second; 
		
		// Add the sum to the output array.
		result.push_back(sum);
		
		// Check if the indices (x-1, y) are present in the set.
		if(mySet.find({x - 1, y}) == mySet.end()){
			maxHeap.push({a[x - 1] + b[y], {x - 1, y}});
			mySet.insert({x - 1, y});
		}
		// Check if the indices (x, y-1) are present in the set.
		if(mySet.find({x, y - 1}) == mySet.end()){
			maxHeap.push({a[x] + b[y - 1], {x, y - 1}});
			mySet.insert({x, y - 1});
		}
		k -= 1; 
	}
	// Return the output array.
	return result;
}