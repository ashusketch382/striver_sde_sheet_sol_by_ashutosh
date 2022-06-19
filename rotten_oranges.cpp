#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    queue<pair<int,int>>q;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< m; j ++){
            if(grid[i][j] == 2)q.push({i,j});
        }
    }
    int time = 0;
    while(!q.empty()){
        bool flag =false;
        int size = q.size();
        while(size--){    
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0 ; i <4; i++){
                int new_x = dx[i] + x;
                int new_y = dy[i] + y;
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < m){
                    if(grid[new_x][new_y] == 1){
                        flag = true;
                        grid[new_x][new_y] = 2;
                        q.push({new_x, new_y});
                    }
                }
            }
        }
        if(flag)time++;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j< m; j ++){
            if(grid[i][j] == 1){
                time = -1;
                break;
            }
        }
    }
    return time;
    // Write your code here. 
}