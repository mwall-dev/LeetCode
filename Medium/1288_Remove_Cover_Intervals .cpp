/*
 *
 * Notes:
 *  - Note this is not overlapping but a strict covering.
 *  - Any groups of covered intervals simply add 1 to the result.
 *  - Since we sort it means that only left elements can cover the right ones, not vice versa.
 *  - Sort by ascending lower part of interval but if two intervals have equal lower range (e.g. (1,2), (1,4)) then we
 *  want the larger upper range first (1,4), (1,2) to ensure that only left elements can cover right.
 *  - Since we sort this way, its only a matter of looking at the upper ranges as we know the lowers increase
 *  as we move forward.
 *
 *
 *  Approach: Brute Force
 *     - Some N^2 thing where we compare all intervals to all others and remove as we go
 *
 *     time:O(N^2)
 *     space:O(1)
 *
 *
 *  Approach:
 *      - Sort by lower bound of interval.
 *      - Look at first ele and make the starting interval. Add 1 to res.
 *      - Start at index 1.
 *      - Look at ele and check if it is covered by the next interval.
 *      - If not then make it the new range.
 *
 *     time:O(NlogN)
 *     space:O(1)
 *
 *
 *
 *
 */


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](auto interval1, auto interval2) {
            if(interval1[0] == interval2[0]) return interval1[1] > interval2[1];
            return interval1[0] < interval2[0];
        } );

        if(intervals.empty()) return 0;

        int current_upper_bound = intervals[0][1];
        int res = 1;

        for(int i = 0; i < intervals.size(); ++i) {
            int upper = intervals[i][1];

            if(upper > current_upper_bound) {
                current_upper_bound = upper;
                ++res;
            }
        }
        return res;
    }
};