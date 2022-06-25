string writeAsYouSpeak(int n) 
{
    string str = "1";
    int i = 1;
    while(i < n){
        int len = str.length();
        char num = str[0], count = 1;
        string new_str = "";
        for(int j = 1 ; j < len ; j++){
            if(num == str[j]){
                count++;
            }
            else{
                new_str += to_string(count);
                new_str += num;
                num = str[j];
                count = 1;
            }
        }
        new_str += to_string(count);
        new_str += num;
        
        str = new_str;
        i++;
    }
    return str;
	// Write your code here.	
}