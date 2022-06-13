#include<bits/stdc++.h>
bool comp(pair<int,int>p1, pair<int,int>p2){
    double a = (double)p1.second/(double)p1.first;
    double b = (double)p2.second/(double)p2.first;
    return a > b;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    double val = 0.0;
    sort(items.begin(), items.end(), comp);
    for(int i = 0 ; i < n; i++){
        if(items[i].first <= w){
            val += items[i].second;
            w -= items[i].first;
        }
        else{
            double rem = (double)items[i].second/(double)items[i].first;
            val += (double)w*rem;
            break;
        }
    }
    return val;
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
}