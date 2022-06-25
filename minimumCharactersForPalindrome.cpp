bool isPal(string &str, int l, int h){
    while(l <= h){
        if(str[l] != str[h])return 0;
        l++;
        h--;
    }
    return 1;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.length();
    int i;
    for(i = n - 1; i >= 0; i--){
        if(isPal(str, 0, i))break;
    }
    if(i < 0)return n - 1;
    return n - (i + 1);
}
