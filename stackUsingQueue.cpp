//my sol
/*
Time Complexity
O(N * Q), where ‘N’ denotes the maximum number of elements in the queue, and ‘Q’ denotes the number of queries.

 

During each pop operation, we transfer all the elements of ‘q1’ to ‘q2’.

Space Complexity
O(max(N1, N2)), where ‘N1' and ‘N2’ denote the size of queues ‘q1’ and ‘q2’.

 

We use two queues of size ‘N1’ and ‘N2’.
*/

#include<bits/stdc++.h>
class Stack {
	// Define the data members.
    queue<int>q1;
    queue<int>q2;
   public:
    Stack() {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q1.size();
        // Implement the getSize() function.
    }

    bool isEmpty() {
        return !q1.size();
        // Implement the isEmpty() function.
    }

    void push(int element) {
        q1.push(element);
        // Implement the push() function.
    }

    int pop() {
        if(q1.empty() == true)return -1;
        int n = q1.size();
        for(int count = 0; count < (n - 1); count++){
            q2.push(q1.front());
            q1.pop();
        }
        int ans = q1.front();
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
        // Implement the pop() function.
    }

    int top() {
        if(q1.empty() == true)return -1;
        return q1.back();
        // Implement the top() function.
    }
};

//

// solution in code studio
/*
Time Complexity
O(N * Q), where ‘N’ denotes the maximum number of elements in the queue, and ‘Q’ denotes the number of queries.

 

During each pop operation, we transfer all the elements of ‘q1’ to ‘q2’.

Space Complexity
O(max(N1, N2)), where ‘N1' and ‘N2’ denote the size of queues ‘q1’ and ‘q2’.

 

We use two queues of size ‘N1’ and ‘N2’.

*/

/*
    Time complexity: O(Q*N)
    For each push operation O(N); O(1) for all other operations.
    
    Space complexity: O(max(N1, N2))

    where Q is the number of queries, N denotes the maximum number of elements in the queue and
    ‘N1' and ‘N2’ denote the size of queues ‘q1’ and ‘q2’.
*/

#include <queue>

class Stack {
   public:
    queue<int> *q1, *q2;

    Stack() {  
        // Constructor.
        q1 = new queue<int>();
        q2 = new queue<int>();
    }

    int getSize() {
        // Return the size of the queue 'q1'.
        return q1->size();  
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void push(int data) {  
        // Simply enqueue data to q1.
        q1->push(data);
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        // Enqueue all the elements of q1 into q2 except the last one.
        while (q1->size() > 1) {  
            q2->push(q1->front());
            q1->pop();
        }

        // Last element of q1 is our answer.
        int ans = q1->front();  
        q1->pop();

        // Swap q1 and q2.
        queue<int> *temp = q1;  
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        // Enqueue all the elements of q1 into q2 except the last one.
        while (q1->size() > 1) {  
            q2->push(q1->front());
            q1->pop();
        }

        // Last element of q1 is our answer.
        int ans = q1->front();  
        q1->pop();
        // Enqueue the top to q2.
        q2->push(ans);  

        queue<int> *temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }
};




//Approach 3(most efficient)

/*
    Time complexity: O(Q*N)
    For each push operation O(N); O(1) for all other operations.

    Space complexity: O(N)

    where Q is the number of queries, N denotes the maximum number of elements in the queue.
*/

#include <queue>

class Stack {
   public:
    queue<int> *q1;

    // Constructor.
    Stack() {  
        q1 = new queue<int>();
    }

    int getSize() {
        // Return the size of the queue 'q1'.
        return q1->size();  
    }

    bool isEmpty() {
        return getSize() == 0;
    }

    void push(int data) {
        // Get the size of the queue.
        int size = q1->size();  
        // Enqueue the  new data to the queue.
        q1->push(data);         

        // Make the new data front of the queue.
        for (int i = 0; i < size; i++)  
        {
            q1->push(q1->front());
            q1->pop();
        }
    }

    int pop() {
        // If empty, return -1.
        if (isEmpty()) {  
            return -1;
        }

        // Simply dequeue from the queue q1.
        int ans = q1->front();  
        q1->pop();
        return ans;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        int ans = q1->front();

        return ans;
    }
};

