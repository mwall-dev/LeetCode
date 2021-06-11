/*
 *  Notes:
 *      max - min must = 1.
 *      Note that we can delete whatever elements we want, the array still has to be ordered.
 *      But this sort of means that we can get whatever combo we want.
 *
 *      THE TRICK:
 *          The trick here is to notice that any subarray that satisfies the condition must only have two unique
 *          elements as this is the only way it will work. (e.g. [1,2,1,2,1,1,2,2] will work, but [1,2,3] will not
 *          and anything with more than two unique elements will NOT WORK).
 *
 *
 *
 *
 *
 *  Approach : HashMap
 *      - Make a freq_map
 *      - Iterate through the map and for each key, check freq of the key - 1 elements.
 *      - Add freq's and make max_length if greater.
 *
 *      time: O(N)
 *      space: O(N)
 *
 *
 *  Other approaches utilise sort or a one pass.
 *
 *
 */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::unordered_map<int, int> number_freq;

        for(const int& num : nums) {
            ++number_freq[num];
        }

        int max_length = 0;

        for(auto it = number_freq.begin(); it != number_freq.end(); ++it) {
            if(number_freq.find(it->first - 1) != number_freq.end()) {
                max_length = std::max(max_length, it->second + number_freq[it->first - 1]);
            }
        }
        return max_length;
    }
};