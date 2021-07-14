/*
    Notes:
        - Substrings are contigious.
        - Thinking maybe some sliding window approach or maybe a hashSet approach where you delete and add as you go.
        -



    Approach : Brute Force
        - Use substring with indicies and a helper method to check each sub string.
        - Quite expensvie with all the copying.

    Approach : HashSet and sliding window.
        - Just unclear logic for some reason.
        - Keep track of how many duplicates there are in the current substring.
        - Each iteration we add one more on right and check for dups. (the if i < 2 handles the first 3 chars)
        - If dup == 0 then is a valid good string.
        - Now we remove the leftmost char and see if it effects dups.
        - Note that you start each iteration with 2 chars in your set basically.



*/


class Solution {
 public int countGoodSubstrings(String s) {
    char[] chars = new char[26];
    int ans = 0;
    int dup = 0;

    for(int i = 0; i < s.length(); i++) {
        if (++chars[s.charAt(i) - 'a'] == 2) dup++;

        if (i < 2) continue;

        if (dup == 0) ans++;

        if (--chars[s.charAt(i - 2) - 'a'] == 1) dup--;

    }

    return ans;

    }
}

/*
// Brute Force
class Solution {

    public int countGoodSubstrings(String s) {

        int goodStringsCount = 0;

        for(int index = 0; index <= s.length() - 3; ++index) {
            if(isGoodString(s.substring(index, index + 3))) {
                ++goodStringsCount;
            }
        }

        return goodStringsCount;
    }

    private boolean isGoodString(String s) {
        int[] charFreq = new int[26];

        for(char c : s.toCharArray()) {
            if(charFreq[c - 'a']++ == 1) return false;

        }

        return true;
    }
} */