/*
 *  Notes:
 *      - numBottles < numExchange then its numBottles
 *      - 15 4
 *
 *
 *
 *        15   3
 *
 *
 *
 *  Approach : Brute Force
 *      - Utilize int division.
 *
 *      - Add numBottles.
 *      - numBottles /= numExchange
 *      - Repeat.
 *
 *
 *
 */


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total_bottles_drank = 0;
        int empty_bottles = 0;

        while(numBottles) {
            total_bottles_drank += numBottles;
            empty_bottles += numBottles;
            numBottles = empty_bottles /numExchange;
            empty_bottles = empty_bottles % numExchange;
        }
        return total_bottles_drank;

    }
};