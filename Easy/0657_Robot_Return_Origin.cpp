/*
 *
 * Approach:
 *  Basically for it to arrive where it started. It must have an equal number of U and D and an equal number of R and L.
 *
 *
 */


#include <algorithm>

class Solution {
public:
    bool judgeCircle(string moves) {
        int num_U = std::count(moves.begin(), moves.end(), 'U');
        int num_D = std::count(moves.begin(), moves.end(), 'D');
        int num_L = std::count(moves.begin(), moves.end(), 'L');
        int num_R = std::count(moves.begin(), moves.end(), 'R');

        return num_U == num_D && num_R == num_L;
    }
};



// Same time complexity but faster as we only iterate through once (removes k factor).
class Solution {
public:
    bool judgeCircle(string moves) {
        int num_U = 0, num_D = 0, num_R = 0, num_L = 0;

        for(const char& c : moves) {
            switch(c) {
                case 'U':
                    ++num_U;
                    break;

                case 'D':
                    ++num_D;
                    break;

                case 'R':
                    ++num_R;
                    break;

                case 'L':
                    ++num_L;
                    break;
            }
        }

        return num_U == num_D && num_R == num_L;
    }
};