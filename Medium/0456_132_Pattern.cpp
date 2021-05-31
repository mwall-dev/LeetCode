/*
 *
 *  Notes:
 *  i < j < k
 *  and nums[i] < nums[k] < nums[j]
 *  so strictly increasing but largest is in middle.
 *
 *  nums[i] must be less than nums[k] so 2,4,2 doesn't satisfy.
 *  smallest, largest, middle.
 *
 *  Elements don't have to be adjacent so can't just sliding window from start and look at adjacent groups of 3.
 *  Need to look at all combinations with 3 numbers.
 *  Need to preserve ordering though as indicies do matter.
 *
 *  Looking for an up and a down. A hill basically.
 *
 *  We can find the second as early as possible as we know we will find the next later. Earliest is best as you don't
 *  miss anything. Actually this is not true as you might miss the pattern.
 *  case: [-2,1,2,-2,1,2] you only see the 1 for the second when its -2, 2, 1.
 *
 *  Approach: Brute Force
 *      - 3 for loops for all combinations.
 *
 *      time: O(N^3)
 *      space: O(1)
 *
 *
 *  Approach: Slighty optimised
 *      - Similar but this time scan for j,k pairs where j < k and nums[k] < nums[j]. k is middle one and j is largest.
 *      - Now we need to find some i < j and nums[i] < nums[k].
 *      - Can precompute this and store using an array.
 *      - Before starting, do a linear scan of array with a running minimum and for nums[i] store in a seperate array
 *      min_val[i] the minimum element before nums[i].
 *      - This will make the last step O(1) lookup. Will basically be min_val[j - 1] < nums[k].
 *      - Can do this as the smallest will be between index 0 < j - 1
 *      - The array abstracts the ordering (i < j condition) away as the loop does the work.
 *
 *      time:O(N^2)
 *      space: O(N)
 *
 *
 *  Approach: One Pass using a std::set:
 *      - When you have to fix 3 things, always fix the middle one (not k though). So fix j, the largest. as its small, large, medium.
 *      - We see that i will be from 0 to j - 1 and k will be from j + 1 to nums.size().
 *      - i = pos of min_val[j - 1]. Check if a[i] < a[j].
 *      - Check if there is some k such that a[i] < a[k] < a[j] where a[k] = the max value from j + 1 to n WHICH IS LESS THAN a[j]. NOW ITS HARDER
 *      AS WE CAN"T PRECOMPUTE THIS.
 *
 *      - Use a set.
 *      - Basically you build the set as you go and then use lower/upperbound() to find the max set_ele < nums[j].
 *
 *      very similar to above except you search for j from n to 0.
 *      each time you add nums[j+1] to set. Do a search to find the max value just less than nums[j]. Then check if this
 *      is > min_val[j - 1].
 *
 *
 *
 *
 *      time: O(NlogN)
 *      space: O(N)
 *
 *
 *
 *  Approach: One pass using a stack.
 *      - Can just use a stack for potential j's and k's.
 *      - Put stuff in stack in non-increasing order. Say it works out for first several elements (they are sorted) and
 *      our stack looks like 10 6 5 3 3 1, now we've reached a[j] = 7. Pop each element off that is less than 7, try as a
 *      k, test against min_val[j-1] too. If doesn't work than push 7 on in spot. In this example, this is the case if we need
 *      smaller min_vals (as we must satisfy the k value is > nums[i]).

 */

//O(N)
class Solution {
public:
    void print_arr(vector<int>& min_val) {
        for(int& x : min_val) {
            std::cout << x << "\n";
        }
    }

    bool find132pattern(vector<int>& nums) {
        vector<int> min_val(nums.size());
        min_val[0] = nums[0];

        for(int k = 1; k < nums.size(); ++k) {
            min_val[k] = std::min(min_val[k - 1], nums[k]);
        }

        std::stack<int> stck;

        for(int j = nums.size() - 1; j >= 1; --j) {

            while(!stck.empty() && stck.top() < nums[j]) {
                int k = stck.top();
                stck.pop();
                if (min_val[j - 1] < k) return true;
            }
            stck.push(nums[j]);
        }

        return false;

    }
};
// O(N^2)
class Solution {
public:

    void print_arr(vector<int>& min_val) {
        for(int& x : min_val) {
            std::cout << x << "\n";
        }
    }

    bool find132pattern(vector<int>& nums) {
        vector<int> min_val(nums.size());
        min_val[0] = nums[0];

        for(int k = 1; k < nums.size(); ++k) {
            min_val[k] = std::min(min_val[k - 1], nums[k]);
        }

        for(int j = 1; j < nums.size(); ++j) {
            for (int k = j + 1; k < nums.size(); ++k) {
                if (nums[k] < nums[j] && min_val[j - 1] < nums[k]) {
                    return true;
                }
            }
        }
        return false;

    }
};

// Brute Force
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
                for (int j = i + 1; j < nums.size(); ++j) {
                    if(nums[i] < nums[j]) {
                        for (int k = j + 1; k < nums.size(); ++k) {
                            if(nums[k] < nums[j] && nums[i] < nums[k]) {
                                return true;
                            }
                        }
                    }
                }
            }
        return false;

        }

    }
};



class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i) {
            bool found_second = false;
            int j;

            for(j = i + 1; j < nums.size(); ++j) {
                if(nums[i] < nums[j]) {
                    found_second = true;
                    break;
                }
            }

            if(found_second) {
                for(int k = j + 1; k < nums.size(); ++k) {
                    if(nums[k] < nums[j] && nums[i] < nums[k]) {
                        return true;
                    }
                }
            }

        }
        return false;
    }
};