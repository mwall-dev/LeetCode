/*
 * Approach:
 *  Num to string and scan through string until you found a six.
 *  Change first occurrence of six to a 9.
 *  If there are no 6's then do nothing.
 *
 *  time: O(N)
 *  space: O(N)
 *
 *
 *  Optimised : Don't convert to string.
 *      - Do %10 / 10 stuff to get right hand number each time.
 *      - Record right most position of six.
 *      - Add 3 * 10's using position of six to get result.
 *      - If no 6's then return result.
 *
 *
 *     time:O(N)
 *     space: O(1)
 *
 *
 *
 *
 */


class Solution {
public:
    int maximum69Number (int num) {
        int pos_6 = 0;
        int tens = 0;
        int original_num = num;
        while(num > 0) {
            ++tens;
            if(num % 10 == 6) pos_6 = tens;
            num /= 10;
        }

        if(!pos_6) return original_num;

        return original_num + (3 * std::pow(10, pos_6 - 1));
    }
};


class Solution {
public:
    int maximum69Number (int num) {
        std::string number = std::to_string(num);
        for(char& c : number) {
            if(c == '6') {
                c = '9';
                return std::stoi(number);
            }
        }
        return num;
    }
};



