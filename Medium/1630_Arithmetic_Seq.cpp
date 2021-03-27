/*
    Approach:
        - Iterate through l and r in parralel.
        - Get range
        - Sort range and check if its a valid sequence by computing differences.
        
    Time: O(m * n * log n), where m is the number of queries.

*/





class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        std::vector<bool> res;
        
        for(int i = 0; i < l.size(); ++i) {
            int low = l[i];
            int high = r[i];
            
            std::vector<int> range(nums.begin() + low, nums.begin() + high + 1);
            
            std::sort(range.begin(), range.end());
            
            int diff = range[1] - range[0];
            
            bool is_valid = true;
            for(int j = 0; j < range.size() - 1; ++j) {
                if(range[j + 1] - range[j] != diff) {
                    is_valid = false;
                    break;
                }
            }
            res.push_back(is_valid);
        
        }
        
        return res;
    }
};
