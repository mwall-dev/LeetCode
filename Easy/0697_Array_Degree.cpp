
/*

    Notes:
    Cannot sort as question asks for contigious.
    
    
    Approach: Recursive,  takes too long. Only need one sweep
        Find degree of whole array:O(N)
        
        Start at first element.
        Now have option to either include next element or start fresh from it.

    Approach 2: One sweep and make use of indicies
    We know that for an array to have the same degree as the whole array.
    It must contain all copies of the one most frequent element.
    If there are two elements with the same freqeuncy then need min size (could be fillers in between)
    
    
    

*/
class Solution {
    public:
 int findShortestSubArray(vector<int>& A) {
        unordered_map<int, int> count, first;
        int res = 0, degree = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (first.count(A[i]) == 0) first[A[i]] = i;
            if (++count[A[i]] > degree) {
                degree = count[A[i]];
                res = i - first[A[i]] + 1;
            } else if (count[A[i]] == degree)
                res = min(res, i - first[A[i]] + 1);
        }
        return res;
    }
};

/*
int min_size = INT_MAX;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        min_size = INT_MAX;
        
        std::unordered_map<int, int> freq_count;
        int target = 0;
        
        // Obtain degree of whole array.
        for(const int& num : nums) {
           target = std::max(++freq_count[num], target); 
        }
        
        
        min_array(nums, {}, 0, 0, 0, target);
        return min_size;
    }
    
    
    void min_array(vector<int>& nums, std::unordered_map<int, int> freq_map, int size, int current_index, int degree, int target) {
        if(degree == target) {
            min_size = std::min(min_size, size);
            // Any future adds would just mean a larger array.
            // So only look at starting fresh.
            if(current_index != nums.size()) min_array(nums, {{nums[current_index], 1}}, 1, current_index + 1, 1, target);
            return;
        }
        
        if(current_index == nums.size()) return;
        
        // Update map and degree if max freq changed.
        ++freq_map[nums[current_index]];
        degree = std::max(degree, freq_map[nums[current_index]]);
        
        // Keep going forward.
        min_array(nums, freq_map, size + 1, current_index + 1, degree, target);
        
        // Start fresh here.
        min_array(nums, {{nums[current_index], 1}}, 1, current_index + 1, 1, target);
        
    }
}; */
