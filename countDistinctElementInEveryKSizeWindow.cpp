/*Time Complexity
O(N), Where N denotes the number of elements in the array.
 

We are traversing through the array ARR to find the number of distinct elements in all windows that take O(N) time. The Time Complexity to insert an element in the HashMap and delete an element from the HashMap is O(1). Hence, the overall Time Complexity is O(N).

Space Complexity
O(K), Where K denotes the size of the window.

 

The Space Complexity O(K) is used to store distinct elements present in the window in the HashMap. Hence, the overall Space Complexity is O(K).

*/


#include<unordered_map>

vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n = arr.size();

    // Create an array to store the number of distinct elements in all windows
    vector <int> answer(n - k + 1);

    // Maintain a HashMap to store the frequency of elements in the current window
    unordered_map<int,int> hashMap;

    // Add the frequency of first K element in the HashMap
    for (int i = 0; i < k; i++) 
    {
        hashMap[arr[i]] = hashMap[arr[i]] + 1;
    }

    // Insert the number of distinct elements present in the first window in the array answer
    answer[0] = hashMap.size();

    //  Iterate through all remaining windows
    for (int index = k; index < n; index++) 
    {
        // Decrement the frequency of element in the HashMap by 1
        int element = arr[index - k];
        hashMap[element] -= 1;

        // Check if the frequency of element in the HashMap is 0
        if (hashMap[element] == 0) 
        {
            hashMap.erase(element);
        }

        // Increment the frequency of ARR[index] in the HashMap by 1
        hashMap[arr[index]] = hashMap[arr[index]] + 1;

        // Insert the number of distinct elements present in the window in the array answer
        int windowNumber = index - k + 1;
        answer[windowNumber] = hashMap.size();
    }

    // Return the array answer
    return answer;
}
