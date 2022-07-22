/*

Time Complexity
O(N), where ‘N’ denotes the length of the string.

 

We traverse the string once, therefore the overall time complexity will be O(N).

Space Complexity
O(1)

 

Since, we are not using any extra space. Therefore, the overall space complexity will be O(1).


*/
int atoi(string str) {
    int ans = 0;
    int n = str.length();
    int i = 0;
    if(str[0] == '-')i++;
    for(; i < n ;i++){
        if((str[i] >= '0') && (str[i] <= '9')){
            ans *= 10;
            ans += (int)(str[i] - '0');
        }
    }
    if(str[0] == '-')ans *= -1;
    return ans;
    // Write your code here.
}