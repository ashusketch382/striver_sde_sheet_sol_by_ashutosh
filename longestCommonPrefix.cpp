string longestCommonPrefix(vector<string> &arr, int n)
{
    string str = arr[0];
    for(int ind = 1 ; ind< n ;ind++){
        int n = str.length();
        string str2 = arr[ind];
        int m = str2.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(str[i] != str2[j])break;
            i++, j++;
        }
        if(i == 0)str = "";
        else if(i == n)continue;
        else if(j == m)str = str2;
        else{
            str = str.substr(0, i);
        }
    }
    return str;
    // Write your code here
}


