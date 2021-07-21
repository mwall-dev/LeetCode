/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

/*
    Notes:
        - Just looks like a 1 to n binary search where instead of accessing the array element we chuck it into guess()
        and go left or right based on result.


    Approach:
        - Take a guess at mid way point.

*/
class Solution {
public:
    int guessNumber(int n) {
        int start = 1;
        int end = n;


        while(start < end) {
            // Use to prevent overflow.
            int mid = (end - start) / 2 + start;
            //std::cout << mid << '\n';

            int guess_result = guess(mid);

            if(guess_result == 0) return mid;

            else if(guess_result > 0)
                if(start == mid) start = mid + 1;
                else start = mid;

            else end = mid;
        }

        return start;
    }
};