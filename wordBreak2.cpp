bool isPresent(string str, vector<string> &dictionary){
    int size = dictionary.size();
    for(int i = 0; i < size ; i++){
        if(dictionary[i] == str)return true;
    }
    return false;
}
void word_break(string &s, int ind, int n, vector<string> &dictionary, string str, vector<string> &res){
    if(ind >= n){
        res.push_back(str);
    }
    for(int i = ind + 1; i <= n; i++){
        string substring = s.substr(ind, i - ind);
        if(isPresent(substring, dictionary)){
            if(str != "")str += " ";
            word_break(s, i, n, dictionary, str + substring, res);
            if(str != "")str.erase(str.length() - 1, 1);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string>res;
    int n = s.length();
    word_break(s, 0, n, dictionary,"", res);
    return res;
    // Write your code here

}