// Time Complexity
// O( N * log( N )), Where ‘N’ is the number of queries.


//  We are iterating over each query which is ‘N’ and for each insert or remove we do heapify operation where we each time go to child or parent which is at its double or half of the current position respectively and at max, we will go to the height of the tree which is log ( N ).

// Hence the time complexity will be O( N * log( N )).

// Space Complexity
// O( N ), Where ‘N’ is the number of queries.
 

// We are creating a heap array of size ‘N’.

// Hence the space complexity will be O( N ).


void insert_heapify(vector<int> &heap, int i){
    int parent = (i - 1) / 2;
    if(parent >= 0 && heap[parent] > heap[i]){
        swap(heap[parent], heap[i]);
        insert_heapify(heap, parent);
    }
}
void del_heapify(vector<int> &heap, int i, int size){
    int smallest = i;
    int left = 2 *i +1;
    int right = 2 *i + 2;
    if(left < size && heap[left] < heap[smallest])smallest = left;
    if(right < size && heap[right] < heap[smallest])smallest = right;
    if(smallest != i){
        swap(heap[smallest], heap[i]);
        del_heapify(heap, smallest, size);
    }
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int>res;
    vector<int>heap;
    int size = 0;
    for(int i = 0 ; i < n ; i++){
        if(q[i][0] == 0){
            int x = q[i][1];
            heap.push_back(x);
            size++;
            insert_heapify(heap, size - 1);
        }
   else {
           res.push_back(heap[0]);
           swap(heap[0],heap[size - 1]);
           heap.pop_back();
           size--;
           del_heapify(heap,0, size);
       }
    }
    return res;
}
