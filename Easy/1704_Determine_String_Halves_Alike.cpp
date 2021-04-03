/*
    Approach:
        Iterate through string.
        Count vowels.
        Once you reach halfway, store count and start counting again.
        Compare counts.
*/



class Solution {
public:
    bool halvesAreAlike(string s) {
        std::unordered_set<char> vowels ({'a','e','i','o','u','A','E','I','O','U'});
        int halfway = s.length()/2;
        
        auto scan_string = [&s, &vowels](size_t start, size_t end) {
            int count = 0;
            for(int i = start; i < end; ++i) {
                if(vowels.find(s[i]) != vowels.end()) ++count;
            }
            
            return count;
        };
        
        
        return scan_string(0, halfway) == scan_string(halfway, s.length());
    }
};
