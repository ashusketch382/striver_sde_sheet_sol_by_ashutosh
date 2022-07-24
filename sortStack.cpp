/*
    Time Complexity: O(N^2)
    Space Complexity: O(N),

    where N is the number of elements in the stack.
*/
void sortStack(stack<int> &s)
{
    if(s.empty())return ;
    int x = s.top();
    s.pop();
    sortStack(s);
    stack<int> st;
    while(!s.empty() && x < s.top()){
        st.push(s.top());
        s.pop();
    }
    s.push(x);
    while(!st.empty()){
        s.push(st.top());
        st.pop();
    }
	// Write your code here
}