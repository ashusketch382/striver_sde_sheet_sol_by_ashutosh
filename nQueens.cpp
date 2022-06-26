bool noClashes(vector<vector<int>> &chess, int row, int col, int n){
    for(int j = col - 1 ; j>=0; j--){
        if(chess[row][j] == 1)return false;
    }
    for(int i = row - 1; i >= 0; i--){
        if(chess[i][col] == 1)return false;
    }
   int i = row - 1, j = col - 1;
    while(i >= 0 && j >= 0){
        if(chess[i][j] == 1)return false;
        i--;
        j--;
    }
    i = row + 1, j = col - 1;
    while(i < n && j >= 0){
        if(chess[i][j] == 1)return false;
        i++;
        j--;
    }
    return true;
}
void NQueens(vector<vector<int>> &chess, int y, int n, vector<vector<int>> &res){
    //base case
    if(y >= n){
        vector<int>temp;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                temp.push_back(chess[i][j]);
            }
        }
        res.push_back(temp);
        return;
    }
    
    for(int i = 0 ; i < n ; i++){
        if(noClashes(chess, i, y, n)){
            chess[i][y] = 1;
            NQueens(chess, y + 1,n, res);
            chess[i][y] = 0;
        }
    }

}
vector<vector<int>> solveNQueens(int n){
    // Write your code here.
    vector<vector<int>>chess(n, vector<int>(n, 0));
    vector<vector<int>>res;
    NQueens(chess, 0, n, res);
    return res;
}