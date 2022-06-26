
void mazePath(vector<vector<int>> &maze, int row, int col, int n, vector<vector<int>> &res, vector<vector<bool>> &visited){
    visited[row][col] = 1;
//     cout<<"i "<<row<<" j "<<col<<"\n";
    if(row == n-1 && col == n-1){
//         pathFound = true;
        vector<int>curr(n*n, 0);
//         int size = path.size();
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < n ; j++){
                curr[i * n + j] = (int)visited[i][j];
            }
        }
        res.push_back(curr);
        visited[row][col] = 0;
        return ;
    }
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    for(int i = 0 ; i < 4; i ++){
//         if(row == 0 && col == 0)pathFound = false;
        int x = row + dx[i];
        int y = col + dy[i];
        
        if(x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1 && !visited[x][y]){
            
            mazePath(maze, x, y, n, res, visited);
//             if(!pathFound)maze[x][y] = 0;
        }
    }
    visited[row][col] = 0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>>res;
//     bool pathFound = false;
//     vector<pair<int, int>>path;
    
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    if(maze[0][0] == 1)
        mazePath(maze, 0, 0, n, res, visited);
    return res;
}