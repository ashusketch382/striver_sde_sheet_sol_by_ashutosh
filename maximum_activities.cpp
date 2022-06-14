#include<bits/stdc++.h>
struct time{
    int s;
    int e;
};

bool comp(struct time t1,struct time t2){
    return t1.e < t2.e;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    struct time meets[n];
    for(int i = 0 ; i < n; i++){
        meets[i].s =start[i];
        meets[i].e = finish[i];
//         meets[i].push_back(finish[i]);

    }
    sort(meets, meets + n, comp);
    int maxAct = 1;
    int lastTime = meets[0].e;
    for(int i = 1; i < n ; i++){
        if(lastTime <= meets[i].s){
            maxAct++;
            lastTime = meets[i].e;
            
        }
    }
    return maxAct;
}