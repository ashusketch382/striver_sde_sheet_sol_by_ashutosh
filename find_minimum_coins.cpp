int findMinimumCoins(int amount) 
{
    int count = 0;
    vector<int>currency{1,2,5,10,20,50,100,500,1000};
    for(int i = 8; i >= 0; i--){
        if(amount >= currency[i]){
            count += amount / currency[i];
            amount =amount % currency[i];
        }
    }
    return count;
    // Write your code here
}
