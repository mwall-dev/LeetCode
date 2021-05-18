/*
 *  Notes:
 *      - In an array of size 2n with n+1 unique numbers where one of the numbers repeats n times,
 *      this means that only one number repeats!!! This is just literally searching for the one number with
 *      frequency > 1. (think of n+1 as over half).
 *
 *
 *
 *  Approach 1: Brute Force
 *      - Just use a freq count and map until you get a count = n
 *      time: O(N)
 *      space: O(N)
 *
 *
 *  Approach 2: Optimised
 *      - Some interesting solutions here: see this:
 *      https://leetcode.com/problems/n-repeated-element-in-size-2n-array/discuss/208563/JavaC%2B%2BPython-O(1)-Solution
 *
 *
 *
 */
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int freq_count[10005] = {0};
        int n = nums.size()/2;
        for(const int& num : nums) {
            if(++freq_count[num] == 2) {
                return num;
            }
        }

        return -1;
    }
};