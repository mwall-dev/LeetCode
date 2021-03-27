
/*

    Apporach 1:
        - Square all numbers
        - Sort 
        Return 
        
        time: O(nlogn)
        
        
    Approach 2: Two pointers.
        - Need to worry about negative numbers place in array.
        - Alter array in place: Make all negative numbers postive, stop when you get to postive.
        - Now an L and R pointer on each end of vector.
        - Take the maximum number of the two and square it and put into back of a new vector.
        - Push forward that pointer and continue until pointers have met.
    
    time: O(N)
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::vector<int> res(nums.size());
    
        
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] > 0) break;
            nums[i] *= -1;
            ++i;
        }
        
      
        int L = 0;
        int R = nums.size() - 1;
        
        int res_index = nums.size() - 1;
        while(L <= R) {
            if(nums[L] > nums[R]) {
                res[res_index] = nums[L]*nums[L];
                ++L;
            }
            else {
                res[res_index] = nums[R]*nums[R];
                --R;
            }
            --res_index;
        
        }
        
        return res;
    }
};

/*
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        std::for_each(nums.begin(), nums.end(), [](int &n){ n = n*n; });
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};

*/



