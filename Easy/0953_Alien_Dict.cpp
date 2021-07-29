/*
    Notes:
        - We are looking to see if the words are in lexiographical ordering based on the ordering of the alphabet given.
        - We will normally only need to look at first characters but when they are the same cahr then we need to look at the second char etc...
        - Lexiographic comparison is transitive therfore we only need to compare adjacent words.
        -

    Approach : Store alphabet in a hash map with values
        - Store alphabet in a hashmap and assign values as indicies in the order string.
        - Compare each string with one before and compute its value using the hash_map. If equal values then need to keep going until end.

        time:O(NM)
        space:O(26)

    */


class Solution {
private:
    std::unordered_map<char, int> alphabet;

public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.length(); ++i) {
            alphabet.insert({order[i], i});
        }

        return is_sorted(words.begin(), words.end(), [this](const auto& s1, const auto& s2) {
            if(s1 == s2) return false;
            int sum1 = 0;
            int sum2 = 0;
            int i;
            while(sum1 == sum2 && i < s1.length() && i < s2.length()) {
                sum1 += alphabet[s1[i]];
                sum2 += alphabet[s2[i]];
                ++i;
            }


            if(sum1 == sum2) {
                return s1.length() <= s2.length();
            }

            return sum1 < sum2;

        });
    }


};
