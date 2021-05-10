/*
    Notes:
        Work backwards from nums to array of zeroes.
        Can only divide by 2 if all elements are even (as this reflects the * 2).
        Can't do element by element as the *2 works on all elements so we would not get the minimum answer.

        Realise that if you look at each element in binary format it is a bunch of 1's and 0's.
        Visualise the operations as doing these things:
            The first op will minus a one bit (the LSB)
            The second op will right shift by 1 (divide by 2) BUT ONLY IF THE LSB IS A 0 (if the number is even as this LSB
            determins the even/odd of a number).

        For each number, we are looking to eliminate all the one bits.
        The second op is shared between all numbers.

    Approach:
        Start with nums.
        Look at each ele.
        Count the number of 1 bits as well as the length of the number in binary.
        
        The number of minus/add 1 operations will be the number of 1 bits (as we can only eliminate them this way).
        The number of divide/times 2 operations will be the length of the longest binary number (as this will need the most and 
        since all others need less divide 2's than this, it will be fine).



Dirty 1 liner
https://leetcode.com/problems/minimum-numbers-of-function-calls-to-make-target-array/discuss/805682/C%2B%2B-1-liner-O(n)
*/

#include <vector>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int max_len = 1;
        int ops = 0;

        for(int& num : nums) {
            int len = 0;

            while(num) {
                ops += num & 1;
                num >>= 1;
                ++len;
            }
            max_len = std::max(max_len, len);
        }

        return ops + max_len - 1;
    }
};