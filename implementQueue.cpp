/*
Time Complexity
O(q), where q is the number of queries.

 

enQueue, deQueue, front, isEmpty all of these functions are O(1). Hence the total time complexity will be O(q).

Space Complexity
O(q), where q is the number of queries.

 

Since we are creating a linked list that can be of size q in the worst case when all the queries are of enQueue. Hence the space complexity is O(q).


*/
// Queue using Linked List.
template <typename T>
class LinkedListNode{
    public:
        T data;
        LinkedListNode<int> *next;
        LinkedListNode(T data){
            this->data = data;
            this->next = NULL;
        }
};

class Queue {
public:
    LinkedListNode<int>* firstNode;
    LinkedListNode<int>* lastNode;
    
    Queue() {
        firstNode = NULL;
        lastNode = NULL;
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(firstNode == NULL)return 1;
        return 0;
        // Implement the isEmpty() function
    }

    void enqueue(int data) {
        LinkedListNode<int>* curr = new LinkedListNode<int>(data);
        if(firstNode == NULL){
            firstNode = curr;
            lastNode = curr;
            return ;
        }
        lastNode->next = curr;
        lastNode = curr;
        
        
        // Implement the enqueue() function
    }

    int dequeue() {
        if(firstNode == NULL)return -1;
        int ans = firstNode->data;
        LinkedListNode<int>* temp =firstNode;
        firstNode = firstNode->next;
        if(firstNode == NULL)lastNode = NULL;
        delete(temp);
        return ans;
        // Implement the dequeue() function
    }

    int front() {
        if(firstNode == NULL)return -1;
        int ans = firstNode->data;
        return ans;
        // Implement the front() function
    }
};

//Queue using Array.
/*
Time Complexity
O(q), where q is the number of queries.

 

enQueue, deQueue, front, isEmpty all of these functions are O(1). Hence the total time complexity will be O(q).

Space Complexity
O(q), where q is the number of queries.

 

Since we are creating a linked list that can be of size q in the worst case when all the queries are of enQueue. Hence the space complexity is O(q).


*/

class Queue {
public:
    int qfront, rear, size, queueSize;
    int q[100010];
    Queue() {

        // Intialise the queue with 0 elements.
        rear = 0;
        qfront = 0;
        size = 0;
        queueSize = 100010;

    }

    // Function to check if the queue is empty.
    bool isEmpty() {
        if (qfront == rear) {
            return true;
        }
        return false;
    }

    void enqueue(int data) {

        // Push the current element in the queue.
        q[rear] = data;
        rear = rear + 1;

        // Increase the value of size.
        size++;
    }

    int dequeue() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        int ans = q[qfront];
        qfront++;
        size--;
        if (qfront == rear) {
            qfront = 0;
            rear = 0;
        }
        return ans;
    }

    int front() {

        // Check if the queue is empty.
        if (isEmpty()) {
            return -1;
        }

        // Return the element at front.
        return q[qfront];
    }
};