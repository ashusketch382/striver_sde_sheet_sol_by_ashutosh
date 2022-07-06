// T.C. = O(N)
// S.C. = O(N)


bool areAnagram(string &str1, string &str2){
    // Write your code here.
    vector<int>count(26, 0);
    int n = str1.length();
    int m = str2.length();
    if(n != m)return 0;
    for(int i = 0 ; i < n ; i++){
        count[str1[i] - 'a']++;
    }
    for(int i = 0 ; i < m; i ++){
        count[str2[i] - 'a']--;
    }
    for(int i = 0 ; i <26; i ++){
        if(count[i] != 0)return 0;
    }
    return 1;
}