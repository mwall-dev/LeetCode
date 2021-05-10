#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
/*

    Notes:  
        Cant exploit the fact that the sum of all ascii lowercase a-z is known. AS THEY CAN APPEAR AT LEAST ONCE.
        Use hashmap/freq count.



    Approach:
        Add elements to unordered_set (as duplicates will just override and not count as new elements).
        Once size >= 26 then return true.


    Optimise:
        Quite slow. Maybe overhead of hashset.
        Use array instead.

    Debug:


    Disgusting 1 Liners
    C++, 1-line
    by @alvin-777

    bool checkIfPangram(string s) {
        return set<char>(s.begin(), s.end()).size() == 26;
    }

    Python

    def checkIfPangram(self, s):
        return len(set(s)) == 26

*/
class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        bool freq_count[26] = {false};

        for(const char& c : sentence) {
            freq_count[c - 'a'] = true;
        }
        for(int i = 0; i < 26; ++i) {
            if(!freq_count[i]) return false;
        }

        return true;
    }
};

/*
class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        std::unordered_set<char> letters_seen;

        for(const char& c : sentence) {
            letters_seen.insert(c);
            if(letters_seen.size() >= 26) return true;
        }

        return false;
    }
};

*/