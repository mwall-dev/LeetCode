/*
 * Approach:
 *  Use an unordered_map<int, int> with key, val = number, frequency.
 *  As we go along we check if the number is present already. Exploiting the iteration through indices.
 *  Numbers can be reused.
 *
 *  time: O(N)
 *  space: O(N).
 *
 *
 *
 * Optimised:
 * count the occurrence of the same elements.
    For each new element a,
    there will be more count[a] pairs,
    with A[i] == A[j] and i < j

    Basically you find a 4 for the first time. You add 0 (as no pair yet) but you post increment.
    You find a second 4 and now you add one as is a pair and post increment.
    You find a third 4, now you can make 4,4 and 4,4 so you add 2 and post increment.
 *
 *
 *  int numIdenticalPairs(vector<int>& A) {
        int res = 0;
        unordered_map<int, int> count;
        for (int a: A) {
            res += count[a]++;
        }
        return res;
    }
*/



class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        std::unordered_map<int, int> number_frequency;
        int count = 0;
        for(const int& num : nums) {
            if(number_frequency[num]++) {
                count += number_frequency[num] - 1;
            }
        }

        return count;
    }
};