/*
    Approach 1: Sorting after every stone smash.
        At each pair smash we take two heaviest stones in array:
            - If equal weight -> delete both stones.
            - If not equal -> greater stone loses mass equal to lesser stone.
        
    
    Need to sort in asc order.
    while(size > 1) {
        Start at back, look at back two elements.
        Stone logic.
        If result non zero then sort array.

    }
    
    
    time:O((N^2)logN)
    
    
    
    Approach 2: Use a binary heap.
        Put vector into a binary heap (std::priority_queue)
        While heap size > 1
            take top, pop top, take top, pop top. To get first two elements to smash
            Push if result is non zero
            
            
    pop is logn
    push is logn
    building is nlogn
    time:O(nlogn)
    
    


*/



class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        std::priority_queue<int> max_heap(stones.begin(), stones.end());
        
        while(max_heap.size() > 1) {
            int stone1 = max_heap.top(); max_heap.pop();
            int stone2 = max_heap.top(); max_heap.pop();
            
            int smash_res = std::abs(stone1 - stone2);
            if(smash_res) max_heap.push(smash_res);
        }
        
        if(max_heap.empty()) return 0;
        
        
        return max_heap.top(); 
        
    }
};
