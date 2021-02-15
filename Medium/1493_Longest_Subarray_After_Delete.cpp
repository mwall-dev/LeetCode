/*

    Approach:
    - Skip over all leading zeroes initially
    - If all zeroes return 0
    
    - Need to count ones until we reach a zero, then we need to continue the count 
    with the 0 ignored but also starting a new count from there.

    - Maintain a sliding window with at most one zero in it.
      pseudo below

    [0,1,1,1,0,1,1,0,1]
    First skip over leading zeroes.

    [1,1,1,0,1,1,0,1]
    Now begin count.
    Would get to length = 3 then you hit the sliding window.
    Record the index of the zero (lastZero = 3)
    Continue counting to length = 5 until you hit another 0.
    Now you have hit second zero. 
    Now compare len to maxLen and replace if greater.

    Need to move sliding window to start at lastZero + 1.
    Then assign length to be currentZero - lastZero + 1
    Now reassign lastZero.

    





*/
#include <vector>


class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int len= 0;
        int max_len = -1;
        int i = 0;
        while(nums[i] == 0) ++i;
        
        int last_zero = i!= 0 ? i - 1 : -1;

        for(i; i < nums.size(); ++i) {
            if(nums[i] == 1) {
                ++len;
            }
            else {
                max_len = std::max(len, max_len);
                if(last_zero != -1) len = i - last_zero - 1;
                
                last_zero = i;
            }
        }
        
        if(last_zero == -1) return len - 1;
        
        return std::max(max_len, len);
    }
};