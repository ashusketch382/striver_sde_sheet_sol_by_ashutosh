T.C. = O(log(min(n,m)))
S.C. = O(1)
#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    if(n > m)return median(b,a);
    
    int l = 0;
    int r = n;
    int l1,r1, l2, r2;
    while(1){
        int cut1 = (l + r)/2;
        int cut2 = (m + n) / 2 - cut1 ;
        
        l1 = cut1>0?a[cut1 - 1]:INT_MIN;
        r1 = cut1<n?a[cut1]:INT_MAX;
        l2 = cut2>0?b[cut2- 1]:INT_MIN;
        r2 = cut2<m?b[cut2]:INT_MAX;
        
//         cout<<l1<<" "<<r1<<"\n";
//         cout<<l2<<" "<<r2<<"\n";
        if(l1 > r2)r = cut1 - 1;
        else if(l2 > r1)l = cut1 + 1;
        else break;
    }
    int left = max(l1, l2);
    int right = min(r1, r2);
//     cout<<left<<" "<<right<<"\n";
    if((m + n) % 2 == 0)return ((left + right)/2.0);
    return (double)right;
    // Write your code here.
}
