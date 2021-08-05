/*
    Notes:
        - Poorly worded question. int add(int val) adds val to the stream and then returns kth largest.
        - kth largest is from the right hand side if sorted. (e.g. 1st largest is max element, 2nd largest is 2nd max element...)


    Apporach : Brute Force
        - Add in the new element.
        - Sort array.
        - Start at right and count to kth unique element.

    time: O(NlogN) for each add
    space: O(N)


    Approach : Max Heap
        - Add all elements to heap with largest on top.
        - Each add() we add the value to heap.
        - Pop off k elements and store.
        - store the kth largest and push elements back on.


    time: O(N + klogN) k <= N so it could be better than brute force.
    space: O(N + k) for heap and then the k element buffer.


    Optimise : Too slow
        - Only need to store k elements in heap. The k largest elements.
        - We store the min of these k largest at the top so we always have access.





*/



class KthLargest {
    using Max_heap = std::priority_queue<int, vector<int>, greater<int>>;
private:
    Max_heap max_heap;
    int k;

public:
    KthLargest(int _k, vector<int>& nums) {
        k = _k;

        for(const auto& ele : nums) {
            max_heap.push(ele);
            if(max_heap.size() > k) max_heap.pop(); // As we dont care about smaller elements.
        }
    }


    int add(int val) {
        max_heap.push(val);

        if(max_heap.size() > k) max_heap.pop();

        return max_heap.top();
    }
};



/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */