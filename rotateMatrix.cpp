/*

    Time Complexity: O(N * M)
    Space Complexity: O(1)

    Where N, M are the number of rowStarts and the number of colStartumns of the matrix, 
    respectively. 

*/


#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row = 0;
    int col = 0;
    int N = n;
    int M = m;
    while(row < (N - 1) && col < (M - 1)){
        int temp = mat[row][col];
        for(int i = row + 1; i < N; i++){
            mat[i - 1][col] = mat[i][col];
        }
        for(int j = col + 1; j < M ;j ++){
            mat[N - 1][j - 1] = mat[N -1][j];
        }
        for(int i = N - 2; i >= row; i--){
            mat[i + 1][M - 1] = mat[i][M - 1];
        }
        int j;
        for(j = M - 1; j > col + 1; j--){
            mat[row][j] = mat[row][j - 1];
        }
        mat[row][j] = temp;
        row++;
        col++;
        N--;
        M--;
    }
//     for(int i = 0 ; i < N ; i ++){
//         for(int j = 0 ; j < M ; j ++)cout<<mat[i][j]<<" ";
//         cout<<"\n";
//     }
    // Write your code here

}