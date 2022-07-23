// Stack class.
/*
Time Complexity
O(1)

 

We don’t traverse the array in any of the operations. Therefore, the overall time complexity will be O(1).

Space Complexity
O(N), where ‘N’ is the capacity of the stack.

 

We use extra space to store the elements of the stack. Therefore, the overall space complexity will be O(N).

*/
class Stack {
    
public:
    int cap;
    int ind;
    vector<int>st;
    Stack(int capacity) {
        cap = capacity;
        ind = 0;
        // Write your code here.
    }

    void push(int num) {
        if(ind == cap)return;
        st.push_back(num);
        ind++;
        // Write your code here.
    }

    int pop() {
        if(ind == 0)return -1;
        int ans = st[--ind];
        st.pop_back();
        return ans;
        // Write your code here.
    }
    
    int top() {
        if(ind == 0)return -1;
        return st[ind - 1];
        // Write your code here.
    }
    
    int isEmpty() {
        if(ind == 0)return 1;
        return 0;
        // Write your code here.
    }
    
    int isFull() {
        return ind == cap;
        // Write your code here.
    }
    
};