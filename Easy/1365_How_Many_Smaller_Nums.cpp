/* Notes:
 *  Can't sort as we need the index ordering for result.
 *
 *
 *
 * Approach: Brute Force
 *  - Iterate through array
 *  - For each number, iterate again from start counting the number of smaller numbers.
 *
 *  time: O(N^2)
 *  space: O(1)
 *
 *
 *  Approach:
 *      - Could build a max heap using std::priority_queue
 *      - We now have the max element on top (the number for this will now be heap.size() - 1) as everything
 *      below is less than.
 *      - Remove max.
 *      - Continue.
 *
 *      - Store results in a hashmap.
 *
 *      Iterate through array and lookup results on hashmap for each element.
 *
 *      time:O(NlogN)
 *      space:O(N)
 *
 *      Lot of memory usage here.
 *
 *
 *
 *  Approach:
 *      - Bit of a cheat answer but we didn't realise the input is limited to numbers
 *      in the range 0 to 100 so can use an array as hashtable.
 *
 *      - Basically, we frequency count using the array for each value, then we iterate through the array
 *      and add the previous index to forward ones (so we move forward all values to get all numbers less than).
 */

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int freq_count[101] = {0};

        for(const int& num : nums) {
            ++freq_count[num];
        }

        for(int i = 1; i < 101; ++i) {
            freq_count[i] += freq_count[i-1];
        }

        std::vector<int> res;

        for(const int& num : nums) {
            if (num == 0) res.push_back(0);
            else res.push_back(freq_count[num - 1]);
        }

        return res;
    }
};



/*
#include <priority_queue>
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::priority_queue<int> heap(nums.begin(), nums.end());
        std::unordered_map<int, int> lookup_result;

        while(!heap.empty()) {
            lookup_result[heap.top()] = heap.size() - 1;
            heap.pop();
        }

        std::vector<int> res;

        for(const int& num : nums) {
            res.push_back(lookup_result[num]);
        }

        return res;


    }
};

 */