int removeDuplicates(vector<int> &arr, int n) {
    // Write your code here.
    int s = 0;
    int e = 0;
    int i = 0;
    while(i < n){
        while((i + 1) < n && arr[i + 1] == arr[i])i++;
        arr[s++] = arr[i++];
    }
    return s;
}