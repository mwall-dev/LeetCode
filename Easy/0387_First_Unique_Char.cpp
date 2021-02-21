#include <iostream>
#include <vector>

/*
 * Approach 1:
 *  Nested loop
 *  For each char look ahead to find if it exists later on.
 *  if not then return index
 *  else try next char
 *  time:O(n^2)
 *  space:O(1)
 *
 *
 *  Approach 2:
 *  Frequncy count with an array of 26
 *  Then iterate through string and find first entry with value 1
 *
 *  time:O(N)
 *  space:O(1) as is limited to 26 character set.

    Approach 3:
    sort and iterate
    time:O(NlogN)
    space:O(1)
 *
 *
 *  Apporach 4:
 *  ordered map then iterate through map for 1 value.
 *  though this is NlogN as it is logN inserts
 *
 *
 *
 */


// Apporach 2
class Solution {
public:
    int firstUniqChar(string s) {
        int freq_count[26] = {0};

        for(const char& c : s) {
            ++freq_count[c - 'a'];
        }

        for(int i = 0; i < s.length(); ++i) {
            if(freq_count[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};


