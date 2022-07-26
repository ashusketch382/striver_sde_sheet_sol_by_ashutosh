/*Time Complexity
O(log(K))  where ‘K’ is the ‘K'th’ person which is given in the input of every test case.

 

In each recursive call, we check only the  ‘K’ / 2 elements of both arrays and in the subsequent calls, we are reducing the sizes of both arrays by ‘K’/2. Hence, the overall time complexity is O(log(K)).

Space Complexity
O(1)
*/

#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int l = max(0, k - n);
    int r = min(k, m);
    int l1, r1, l2, r2;
    while(l <= r){
        int cut1 = (l + r) / 2;
        int cut2 = k - cut1;
        l1 = cut1>0?row1[cut1 - 1]:INT_MIN;
        r1 = cut1<n?row1[cut1]:INT_MAX;
        l2 = cut2>0?row2[cut2 - 1]:INT_MIN;
        r2 = cut2<m?row2[cut2]:INT_MAX;
//         cout<<l1<<" "<<r1<<"\n";
//         cout<<l2<<" "<<r2<<"\n";
        if(l1 > r2)r = cut1 - 1;
        else if(l2 > r1)l = cut1 + 1;
        else break;
    }
    return max(l1,l2);
    // Write your code here.
}