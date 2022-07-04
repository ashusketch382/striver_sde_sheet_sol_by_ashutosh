// Time Complexity
// O(M * log(K)), where ‘M’ is the number of chapters and ‘K’ is the sum of time required to study all the chapters.

 

// Because by doing binary search we will calculate the possible answer only log(max) times and in each possible answer we have to traverse all the chapters so the complexity is N * log(max).

// Space Complexity
// O(1).

 

// As we are only doing binary search and we are only using variables to store the state of the binary search so the space complexity is O(1).


bool canAllocate(vector<int> &time, int n , int m, long long dayTime){
    int days = 1;
    long long currTime = time[0];
    if(dayTime < time[0])return 0;
    for(int i = 1 ; i < m; i++){
        if(dayTime < time[i])return 0;// we can't complete this chapter we are required to study time[i] to complete it but we got only dayTime time
        currTime += time[i];
        if(currTime > dayTime){
            days++;
            currTime = time[i];
        }
    }
    if(days <= n)return 1;
    return 0;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	   
    long long sum = 0;
    
    for(int i = 0 ; i < m; i++){
        sum += time[i];
    }
    long long l = 1;
    long long r = sum;
    long long ans = 0;
    while(l <= r){
        long long mid = l + (r - l)/2;
        if(canAllocate(time, n, m, mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    return ans;
	// Write your code here.
}