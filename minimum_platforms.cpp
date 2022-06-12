int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at + n);
    sort(dt, dt + n);
    int stations = 0;
    int ans = 0;
    int i = 0, j = 0;
    while(i < n && j < n){
        if(at[i] <= dt[j]){
            stations++;
            ans = max(ans, stations);
            i++;
        }
        else{
            stations--;
            j++;
        }
    }
//     while(i < n){
//         stations++;
//         ans = max(ans, stations);
//         i++;
//     }
    return ans;
}