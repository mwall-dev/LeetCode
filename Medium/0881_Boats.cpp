/*
 *  Notes:
 *      - We know that the max weight in the group will never be greater than the limit. It might be equal to the limit.
 *      - We want to pair big and small together and make our way towards middle.
 *
 *
 *
 *  Approach:
 *      - Sort.
 *      - Two pointers, start and end.
 *      - Work inwards and try to make pairs that work. If you can't then need to put big one in own boat
 *          and then de-increment.
 *      - This is like a greedy solution. Bit hard to see but we are getting the best we can each time as bigs can
 *      only go with smalls and mids with mids.
 *
 *
 *
 *
 */

// Slightly more optimised.
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        size_t start = 0;
        size_t end = people.size() - 1;
        int boats = 0;

        while(start < end) {
            if(people[start] + people[end] <= limit) ++start;

            ++boats;
            --end;
        }

        if(start == end) ++boats;

        return boats;
    }
};


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        size_t start = 0;
        size_t end = people.size() - 1;
        int boats = 0;

        while(start < end) {
            if(people[start] + people[end] <= limit) {
                ++boats;
                ++start;
                --end;
            }
            else {
                ++boats;
                --end;
            }

        }
        if(start == end) ++boats;
        return boats;
    }
};