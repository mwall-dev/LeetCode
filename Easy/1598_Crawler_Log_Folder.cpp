/*
 *  Notes:
 *      - Think this problem can be transformed into a simpler form:
 *      The three operations can be given a number based on their distance effect.
 *      "../" is a -1 to distance
 *      "./" is a 0
 *      "x/" is a +1
 *
 *
 *
 *
 *  Approach:
 *      Just count using above values.
 *      The min number of operations to get back will always just be straight ../ moves.
 *
 */
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int distance = 0;

        for(const auto& str : logs) {
            if(str[0] != '.') ++distance;
            else if(distance && str.length() == 3) --distance;
        }

        return distance;
    }
};