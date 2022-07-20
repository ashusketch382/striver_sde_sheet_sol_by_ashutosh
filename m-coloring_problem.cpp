bool isPossible2color(int node, int node_color, vector<int> &color, vector<int> &row){
    int len = row.size();
    for(int i = 0 ; i < len ; i++){
        if(i != node && row[i] == 1 && color[i] != -1 && color[i] == node_color)return 0;
    }
    return 1;
}
bool canWeColor(int node, int m, int n, vector<int> &color, vector<vector<int>> &mat){
    if(node == n) return 1;
    for(int i = 0; i < m ; i++){
        if(isPossible2color(node, i, color, mat[node])){
            color[node] = i;
                if(canWeColor(node + 1, m, n, color, mat) == true){
                    return true;
                }
            color[node] = -1;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>color(n, -1);
    if(canWeColor(0, m, n, color, mat))return "YES";
    return "NO";
}