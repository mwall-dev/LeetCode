/*
 *  Notes:
 *      - Store bill counts
 *      - To accept a 10, must have a 5.
 *      - To accept a 20, must have a either (10 and 5) or (3 5's). Exhaust 10's first as can use 3 5's to make alot
 *      more combos.
 *      - The ordering is important so no trick for this, just a brute force sim.
 *
 *  Approach:
 *      - Initial bill counts are all 0.
 *      - For each bill:
 *          if 5: add to fives
 *          if 10: check fives and add to ten
 *          if 20: check tens and fives and add.
 *
 *
 *
 *
 *
 */

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0, twenties = 0;

        for(const int& bill : bills) {
            switch(bill) {
                case 5:
                    ++fives;
                    break;

                case 10:
                    if(fives--) ++tens;
                    else return false;
                    break;

                case 20:
                    if(tens >= 1 && fives >= 1) {
                        --tens;
                        --fives;
                    }
                    else if(fives >= 3) fives -= 3;

                    else return false;
                    ++twenties;
            }
        }

        return true;
    }
};

