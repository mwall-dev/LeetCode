/*
 * Notes:
 *  Recall twos complement representation of negative numbers where the MSB is 1 for -ve numbers. We dont
 *  have to worry about this as input is always positive.
 *  0000_0000_0000_0000_0000_0000_0000_0000 to 0111_1111_1111_1111_1111_1111_1111_111
 *
 *
 * 5 to 7 would be:
 *  0101
 *  0110
 *  0111
 *
 * Need to analyse what exactly bitwise AND does to numbers.
 *
 * 5 AND 7
 * 0101
 * 0111  &
 * ----
 * 0101  = 5
 *
 *
 * 5 AND 6
 * 0101
 * 0110  &
 * ----
 * 0100 = 4
 *
 *
 * 2 AND 31
 * 0000_0010
 * 0010_0000  &
 * ---------
 * 0
 *
 * Note that it really only depends on the smaller numbers in the range, since
 * the larger numbers MSB's that are ones won't be present in the smaller numbers.
 *
 *
 * Scrap the above, there is just a trick to this.
 *
 * Bitwise AND of any two numbers will always produce a number less than or equal to the smaller number.
 *Consider the following example:

									12 ---- 1100
									11 ---- 1011
									10 ---- 1010
									9  ---- 1001
									8  ---- 1000
									7  ---- 0111
									6  ---- 0110
									5  ---- 0101
Desired Range: [5,12]

Starting from 12, the loop will first do
12 & 11 = 8

Next iteration, the loop will do
8 & 7 = 0

why did we skip anding of 10,9? Because even if we did so, the result would eventually be anded with 8 whose value would be lesser than equal to 8.

Hence, you start from the range end and keep working your way down the range till you reach the start.
 *
 * Approach:
 *  Brute force is just to and all numbers together.
 *  There must be a shortcut though.
 *
 *
 *
 *
 *
 *
 */


class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left)
            right = right & right-1;
        return right&left;
    }
};