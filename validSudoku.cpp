bool check(int matrix[9][9] , int row, int  col, int val){
    for(int i = 0 ; i < 9; i ++)
        if(matrix[i][col] == val)return false;
    for(int j = 0 ; j < 9; j ++)
        if(matrix[row][j] == val)return false;
    int x = (row / 3)*3;
    int y = (col / 3)*3;
    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            if(matrix[x + i][y + j] == val)return false;
        }
    }
    return true;
}
bool sudoku(int matrix[9][9], int number){
    //base
    if(number == 81){
        return true;
    }
    int row = number / 9;
    int col = number % 9;
    if(matrix[row][col] == 0){
        for(int val = 1; val <= 9; val++){
            if(check(matrix, row, col, val)){
                matrix[row][col] = val;
                if(sudoku(matrix, number+1)){
                    return true;
                }
                matrix[row][col] = 0;
            }       
        }
        return false;
    }
    return sudoku(matrix, number + 1);
}
bool isItSudoku(int matrix[9][9]){
    // Write your code here.
    int number = 0;
    return sudoku(matrix, number);
}
