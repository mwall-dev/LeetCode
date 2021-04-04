/*
    Approach 1: Brute Force
        - For each char search for a duplicate later on and count the spaces.
        - Store max
    time:O(N2)
    optimise: stop early due to not being able to find something better than current max_len.
    
    
    Approach 2: HashMap
        - Store each char in a unordered_map<char, vector<int>> as we need vector for multiple indicies.
    
    This is actually slower lol.
        
*/


/*
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        
        int max_len = -1;
        for(int i = 0; i < s.length(); ++i) {
            char current = s[i];
            
            // Find next occurences of character 
            for(int j = i + 1; j < s.length(); ++j) {
                if(current == s[j]) {
                    max_len = std::max(j - i - 1, max_len);
                } 
            }
        }
        
        return max_len;
    }
};

*/

/*
class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        std::unordered_map<char, std::vector<int>> char_index_map;
        
        for(int i = 0; i < s.length(); ++i) {
            char_index_map[s[i]].push_back(i);
        }
        
        int max_len = -1;
        for(auto it = char_index_map.begin(); it != char_index_map.end(); ++it) {
            const auto& indicies = it->second;
            if(indicies.size() < 2) continue;
            
            max_len = std::max(max_len, indicies[indicies.size() - 1] - indicies[0] - 1);
        }
        
        return max_len;
    }
    
    
};

*/


// Better hashmap.


class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        std::unordered_map<char, int> mp; // key: character, value: least index of character in s
        int len = -1;
        for(int i = 0; i < s.length(); i++) {
            if(mp.count(s[i])) len = max(len, i - mp[s[i]] - 1);
            else mp[s[i]] = i;
        }
        return len;
    }
};


