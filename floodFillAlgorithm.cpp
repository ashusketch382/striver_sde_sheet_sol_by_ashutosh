// Time Complexity
// O(M * N) per test case, where M and N are the number of rows and columns in the image, respectively.

 

// In the worst case, we will be traversing the complete image. Hence, the overall time complexity is O(M * N)

// Space Complexity
// O(M * N) per test case, where M and N are the number of rows and columns in the image, respectively.

 

// In the worst case, O(M * N) extra space is required by the queue. Hence the overall space complexity is O(M * N).


#include<bits/stdc++.h>
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int m = image.size();
    int n = image[0].size();
    int oldColor = image[x][y];
    if(newColor == oldColor)return image;
    queue<pair<int,int>>q;
    q.push({x,y});
    image[x][y] = newColor;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0 ; i <4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == oldColor){
                image[nx][ny] = newColor;
                q.push({nx,ny});
            }
        }
    }
    return image;
    // Write your code here.
}