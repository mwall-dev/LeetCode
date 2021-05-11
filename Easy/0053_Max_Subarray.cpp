/*
 *  Notes:
 *
 *
 *
 *
 *  Approach 1: Brute Force:
 *      - From each element in array check every contiguous sub array starting with that element
 *      adding on an element each time.
 *
 *      time: Bad
 *
 *
 *  Approach 2: Dynamic Programming
 *      - Have an external array A of identical size where A[i] = the max subarray sum at index i.
 *      - Iterate through array and store in A[i] the max of A[i-1] + num  or num.
 *      - Keep track of max so we don't have to iterate through array A at end.
 *
 *      time: O(N)
 *      space: O(N)
 *
 *  Approach 3: Memory optimised.
 *      - Only really need the last entry so don't need whole array.
 *      - Use two variables.
 *
 *      time:O(N)
 *      space: O(1).
 *
 *
 *
 *
 *
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        std::vector<int> A(nums.size());

        A[0] = nums[0]; // As we need at least one number. Just take the first or not.
        int max_sum = A[0];

        for(int i = 1; i < nums.size(); ++i) {
            A[i] = std::max(A[i -1] + nums[i], nums[i]);
            max_sum = std::max(max_sum, A[i]);
        }

        return max_sum;
    }
};