// Time Complexity
// O( N * log (max) ), where N is the total number of rooms and max is the maximum possible position for any room.

 

// Because by doing binary search we will calculate the possible answer only log(max) times and in each possible answer we have to traverse all positions of the room so the overall Time Complexity is O( N * log (max) ).

// Space Complexity
// O(1).

 

// Constant space is being used. Hence, the overall Space Complexity is O(1).



bool allowed(int mid, vector<int>& positions, int n, int c){
    int players = 1;
    int lastPlayer = positions[0];
    
    for(int i = 1; i < n; i++){
        if((positions[i] - lastPlayer) >= mid){
            lastPlayer = positions[i];
            players++;
        }
    }
    if(players >= c)return 1;
    return 0;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(), positions.end());
    int ans = 0;
    int l = 1;
    int r = positions[n - 1] - positions[0];
    while(l <= r){
        int mid = r + (l-r)/2;
        if(allowed(mid, positions, n, c)){
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return ans;
}