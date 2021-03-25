/*
    Approach:
        - Bit mask that is a single 1 and just & it with each bit and right shift
        to count ones.

*/


class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }
};
