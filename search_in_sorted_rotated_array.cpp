// T.C. = O(log N)
// S.C. = O(1)
int search(int* arr, int n, int key) {
    // Write your code here.
    int l = 0;
    int h = n - 1;
    while(l <= h){
        int mid = (l + h)/2;
        if(arr[mid] == key)return mid;
        else if(arr[l] <= arr[mid]){
            if(key <= arr[mid] && key >= arr[l])h = mid - 1;
            else l = mid + 1;
        }
        else if(arr[mid] <= arr[h]){
            if(key >= arr[mid] && key <= arr[h])l = mid + 1;
            else h = mid - 1;
        }
    }
    return -1;
}