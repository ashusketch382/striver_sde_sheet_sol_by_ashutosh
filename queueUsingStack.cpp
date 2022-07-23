// Space Complexity
// O(N), where ‘N’ is the maximum number of elements which are in the stack at a time.

 

// Since a maximum of N number of elements is stored in a stack at any given time, thus the space complexity will be O(N).

#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    
    public:
    int size;
    stack<int> *s1;
    stack<int> *s2;
    Queue() {
        size = 0;
        s1 = new stack<int>();
        s2 = new stack<int>();
        
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        size++;
        s1->push(val);
        // Implement the enqueue() function.
    }

    int deQueue() {
        if(size == 0)return -1;
        for(int count = 0; count < (size - 1); count++){
            s2->push(s1->top());
            s1->pop();
        }
        int ans = s1->top();
        s1->pop();
        while(!s2->empty()){
            s1->push(s2->top());
            s2->pop();
        }
        size--;
        return ans;
        // Implement the dequeue() function.
    }

    int peek() {
        if(size == 0)return -1;
        for(int count = 0; count < (size - 1); count++){
            s2->push(s1->top());
            s1->pop();
        }
        int ans = s1->top();
        while(!s2->empty()){
            s1->push(s2->top());
            s2->pop();
        }
        return ans;
        // Implement the peek() function here.
    }

    bool isEmpty() {
        return size == 0;
        // Implement the isEmpty() function here.
    }
};


//Approach 2(sol)
// Costly enQueue
/*
    Time complexity: O(N * T)
        For enQueue(): O(1) 
        For deQueue(): O(N) 
        For peek(): O(N)
        For isEmpty(): O(1)

    Space Complexity : O(N)

    Where 'N' is the maximum number of elements that are in the stack at any time.
    Where 'T' is the total number of queries which are performed.
*/

#include <stack>

class Queue {
    stack<int> *st;
public:
    Queue() {
        // Only one user stack is used.
        st = new stack<int>();     
    }

    // EnQueue item to the queue.
    void enQueue(int val) {
        // Push the value into the stack.
        st->push(val);
    }

    // Dequeue an item from the queue.
    int deQueue() {
        // If stack is empty, return -1.
        if (st->empty()) {
            return -1;
        }

        // Pop the current top element.
        int x = st->top();
        st->pop();     

        // Base case of the recursion.             
        if (st->empty()) {
            return x;                  
        }

        // Recursively pop the next element.
        int nxt = deQueue();      
        // Push this element again to the stack.
        st->push(x);              
        return nxt;
    }

    // Returns the Front element of the queue.
    int peek() {
        if (st->empty()) {
            return -1;
        }

        int x = st->top();
        st->pop();
        if (st->empty()) {
            st->push(x);
            return x;
        }

        int nxt = peek();
        st->push(x);
        return nxt;
    }

    // Whether the queue is empty or not.
    bool isEmpty() {
        return (st->empty());
    }
};


//Approach 3(Costly deQueue)
/*
    Time complexity: O(N * T)
        For enQueue(): O(1) 
        For deQueue(): O(N) 
        For peek(): O(N)
        For isEmpty(): O(1)

    Space Complexity : O(N)

    Where 'N' is the maximum number of elements that are in the stack at any time.
    Where 'T' is the total number of queries which are performed.
*/

#include <stack>

class Queue {
    stack<int> *st;
public:
    Queue() {
        // Only one user stack is used.
        st = new stack<int>();     
    }

    // EnQueue item to the queue.
    void enQueue(int val) {
        // Push the value into the stack.
        st->push(val);
    }

    // Dequeue an item from the queue.
    int deQueue() {
        // If stack is empty, return -1.
        if (st->empty()) {
            return -1;
        }

        // Pop the current top element.
        int x = st->top();
        st->pop();     

        // Base case of the recursion.             
        if (st->empty()) {
            return x;                  
        }

        // Recursively pop the next element.
        int nxt = deQueue();      
        // Push this element again to the stack.
        st->push(x);              
        return nxt;
    }

    // Returns the Front element of the queue.
    int peek() {
        if (st->empty()) {
            return -1;
        }

        int x = st->top();
        st->pop();
        if (st->empty()) {
            st->push(x);
            return x;
        }

        int nxt = peek();
        st->push(x);
        return nxt;
    }

    // Whether the queue is empty or not.
    bool isEmpty() {
        return (st->empty());
    }
};


//Approach 4(One stack)
/*
    Time complexity: O(N * T)
        For enQueue(): O(1) 
        For deQueue(): O(N) 
        For peek(): O(N)
        For isEmpty(): O(1)

    Space Complexity : O(N)

    Where 'N' is the maximum number of elements that are in the stack at any time.
    Where 'T' is the total number of queries which are performed.
*/

#include <stack>

class Queue {
    stack<int> *st;
public:
    Queue() {
        // Only one user stack is used.
        st = new stack<int>();     
    }

    // EnQueue item to the queue.
    void enQueue(int val) {
        // Push the value into the stack.
        st->push(val);
    }

    // Dequeue an item from the queue.
    int deQueue() {
        // If stack is empty, return -1.
        if (st->empty()) {
            return -1;
        }

        // Pop the current top element.
        int x = st->top();
        st->pop();     

        // Base case of the recursion.             
        if (st->empty()) {
            return x;                  
        }

        // Recursively pop the next element.
        int nxt = deQueue();      
        // Push this element again to the stack.
        st->push(x);              
        return nxt;
    }

    // Returns the Front element of the queue.
    int peek() {
        if (st->empty()) {
            return -1;
        }

        int x = st->top();
        st->pop();
        if (st->empty()) {
            st->push(x);
            return x;
        }

        int nxt = peek();
        st->push(x);
        return nxt;
    }

    // Whether the queue is empty or not.
    bool isEmpty() {
        return (st->empty());
    }
};