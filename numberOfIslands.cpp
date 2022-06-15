// Time Complexity
// O(N * M)
// Space Complexity
// O(N * M)
void dfs(int** arr,int x, int y,  int n, int m){
    if(x < 0 || y <0 ||x>=n || y >= m ||arr[x][y] == 0)return;
    int dx[8] = {0,1,1,1,0,-1,-1,-1};
    int dy[8] = {1,1,0,-1,-1,-1,0,1};
    arr[x][y] = 0;
    for(int i = 0 ; i < 8 ; i++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        dfs(arr, new_x, new_y, n,m);
    }
}
int getTotalIslands(int** arr, int n, int m)
{
    int islands = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j <m ; j++){
            if(arr[i][j] == 1){
                islands++;
                dfs(arr, i, j, n, m);
            }
        }
    }
    return islands;
   // Write your code here.
}
