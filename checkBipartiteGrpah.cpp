/*
Time Complexity
O(N ^ 2), where ‘N’ is the number of nodes.

 

As we have to color all the nodes present, and for each node, we have to traverse its neighbors. In the worst cases, there can be at most ‘N’ neighbors. Hence, the overall time complexity is O(N ^ 2).

Space Complexity
O(N), where ‘N’ is the number of nodes.


 

Since we are using an array to store the color of each node and a queue to do BFS, the overall space complexity will be O(N).

*/
bool bipartite(int node, vector<vector<int>> &edges, vector<int>& color, int n){
    if(color[node] == -1)color[node] = 0;
    
    for(int i = 0; i < n; i++){
        if(edges[node][i] == 1){
            if(color[i] == -1){
                color[i] = 1 - color[node];
                if(bipartite(i, edges, color,  n) == false)return 0;
            }
            else if(color[i] == color[node])return 0;
        }
    }
    return 1;
}
bool isGraphBirpatite(vector<vector<int>> &edges){
	// Write your code here.
    int n = edges.size();
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n; j ++){
            if(j > i)
            edges[j][i] = edges[i][j];
        }
    }
    vector<int>color(n, -1);
    for(int i = 0 ; i < n ; i++){
        if(color[i] == -1){
            if(!bipartite(i,edges, color, n))return 0;
        }
    }
    return 1;
}