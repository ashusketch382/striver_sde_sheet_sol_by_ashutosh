//brute force
int maximumXor(vector<int> A)
{
    int n = A.size();
    int res = 0;
    for(int i = 0 ; i< n - 1; i++){
        for(int j = i + 1; j < n ; j++){
            res = max(res, A[i] ^ A[j]);
        }
    }
    return res;
    // Write your code here.   
}



/*
Bit-Masking
Instead of finding two elements having maximum xor, we will focus on finding the two numbers in an array, such that xor of which equals a number ‘P’. In this case, ‘P’ will be the maximum number we want to achieve till i-th bit.


 

For ‘P’ to be maximum, we need to try to get as many bits as possible to be 1 from left to right, left-most being the biggest bit. Note that the value of left bits is greater than the sum of all the right bits, so we will try to make bits towards the left to be 1 first, then move towards the right.


 

We will iterate from left to right bits and consider only the bits from left to current bit to find the optimal answer achievable for those bits. We can store only the prefix of that number till that bit by using a bitmask which will store all the bits from left to current bit for that element.

To find this, we will do bitwise AND of all elements with another number where only those bits are 1, which we need for the prefix and rest to be 0.


 

We will store all the prefix masks in a set and evaluate if we can make the current bit 1 in the answer.

We know if,

  a xor b  = c

Then

a = c xor b

So we will set the current bit 1 in a temporary answer, iterate through the set, and check if xor of this and the current element is present in the set. If it is present, we can update the answer to the temporary answer. 









 

Algorithm: 

Initialise ‘ans’ to 0.
Initialise ‘mask’ to 0.
Run a loop ‘i’ from 30 to 0
Create a set ‘s’ of integers.
Make the ith bit 1 in the ‘mask’.
Run a loop ‘j’ from ‘0’ to ‘N’ - 1
Insert the bitwise and of ‘A[j]’ and ‘mask’ into the set.
Initialise ‘tempAns’ to ‘ans’
Make the ith bit 1 in the ‘tempAns’.
Iterate through the set
If xor of ‘tempAns’ and current element is present in the array, update ‘ans’ to ‘tempAns’ and break.

 

Return ‘ans’
Time Complexity
O(N * log (M)), where ‘N’ is the size of the array and ‘M’ is the maximum number present in the array.


 

Since for each bit, we are iterating through the whole array, the time complexity becomes O(N * log (M)).


 

Space Complexity
O(N), where ‘N’ is the size of the array


 

We are storing all the masks in the set, which will lead to a space complexity of O(N).
    Time Complexity: O(N * log (M))
    Space Complexity: O(N)

    Where ‘N’ is the length of the given array and 'M' the maximum value in the array.
*/

#include <unordered_set>
int maximumXor(vector<int> A)
{   
    int ans = 0;
    
    int mask = 0;
    int n = A.size();
    unordered_set<int> s;

    for (int i = 30; i >= 0; i--)
    {   
        

        // Setting the ith bit 1 in mask.
        mask = mask | (1 << i);

        for (int j = 0; j < n; j++)
        {   
            // Inserting prefix bitmask into the set.
            s.insert(A[j] & mask);
        }

        int tempAns = ans;

        // Setting the ith bit 1.
        tempAns = tempAns | (1 << i);

        for(auto it: s)
        {   
            // Checking if 'it' xor 'tempAns' is present in set. 
            if(s.count(it ^ tempAns))
            {   
                ans = tempAns;
                break;
            }
        }

        s.clear();
    } 

    return ans;
}