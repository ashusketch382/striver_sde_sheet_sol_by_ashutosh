vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    vector<int>res;
    
    int sum = 0 ;
    int carry = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        sum = a[i] + b[j] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        i++;
        j++;
    }
    while(i < n){
        sum = a[i] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        i++;
    }
    while(j < m){
        sum = b[j] + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        j++;
    }
    while(carry){
        res.push_back(carry % 10);
        carry = carry / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}git a