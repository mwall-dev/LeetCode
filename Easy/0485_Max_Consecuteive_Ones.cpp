/*
    Approach 1: Array linear scan
        - One sweep of array.
        - Count sequences of ones
        - When you encounter a 0 compare count with max and store new max if found.
        
        time:O(N)
        space:O(1)
        
*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max = 0;
        
        for(const auto& num: nums) {
            if(num) ++count;
            else {
                max = std::max(count, max);
                count = 0;
            }
        }
        
        return std::max(count, max);
    }
};
