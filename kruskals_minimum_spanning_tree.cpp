/*

Time Complexity
O(M * log(M) + N + M), Where ‘N’ and ‘M’ denotes the number of nodes and edges in the graph, respectively.

 

Since we are sorting the array/list of edges, it will take O(M * log(M)) time. And then we are initialising the DSU which takes O(N) time. Along with that at each iteration of merging, we are using findParent() and unite() function of DSU which takes O(1) time. Thus the overall time complexity will be O(M * log(M) + N + M).

Space Complexity
O(N + M), Where ‘N’ and ‘M’ denotes the number of nodes and edges in the graph, respectively.

 

Since we are storing the array/list of edges, and also the DSU will take O(N) space. Thus the overall space complexity will be O(N + M).

*/
#include<bits/stdc++.h>
bool comp(vector<int>&v1, vector<int>& v2){
    return v1[2] < v2[2];
}
int findParent(int x, vector<int>&parent){
    if(parent[x] == x)return x;
    return parent[x] = findParent(parent[x], parent);
}
void unite(int u, int v, vector<int>&parent, vector<int>&rank){
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] > rank[v]){
        parent[v] = u;
    }
    else if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else{
        parent[u] = v;
        rank[v]++;
    }
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    vector<int>parent(n + 1);
    vector<int>rank(n, 1);
    for(int i = 1 ; i <= n ; i++){
        parent[i] = i;
    }
    int totWt = 0;
    sort(graph.begin(), graph.end(), comp);
    for(int i = 0 ; i < m ; i++){
        int u = graph[i][0];
        int v = graph[i][1];
        if(findParent(u, parent) != findParent(v, parent)){
            unite(u,v, parent, rank);
            totWt += graph[i][2];
        }
    }
    return totWt;
}