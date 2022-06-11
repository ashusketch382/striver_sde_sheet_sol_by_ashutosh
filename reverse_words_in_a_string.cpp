void reverse(string &str, int s, int e){
    while(s < e){
        swap(str[s], str[e]);
        s++;
        e--;
    }
}
string reverseString(string str)
{
    int n = str.length();
    //remove extra space
    int s = 0, i = 0;
    while(s < n && str[s] == ' ')s++;
    while(s < n){
        while(s < n && str[s] != ' ')str[i++] = str[s++];
        
        while(s < n && str[s] == ' ')s++;
        if(s == n)break;
        str[i++] = ' ';
    }
    str.erase(i);
    n = i;
    reverse(str, 0, n-1);
    
    //reverse each word
    int start = 0 , end = 0;
    while(end < n){
        if(str[end] == ' '){
            reverse(str, start, end - 1);
            start = end + 1;
        }
        end++;
    }
    reverse(str, start, end - 1);
    return str;
    // Write your code here.
}