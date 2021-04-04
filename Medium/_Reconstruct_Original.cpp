
/*

    Approach HashMap:
        - Cycle through all chars and use a hashmap to record char freq.
        - Search through hashmap and try to build all "zero", then all "one", then all "two"
        and so on, removing chars from hashmap as you use them.
        
            for each digit_string:
                search for first char in hashmap
                    if found then check if done
                        if not done then search for next letter
                        else append string to res and keep searching for this string again from 
                        starting char.
                    else search for next string
                    
        
        
        Debug: If you partially are able to build a digit's letters but not fully
        you need to give back those letters to the hashmap.
        
        Solution below is bad. Doesn't work as  "zeroonetwothreefourfivesixseveneightnine"
Output
"01113356"
Expected
"0123456789"

        This is just a question with a trick.
        
        Trick is just count as some have unique letters.
        The even digits all have a unique letter while the odd digits all don't:

    zero: Only digit with z
    two: Only digit with w
    four: Only digit with u
    six: Only digit with x
    eight: Only digit with g

    The odd ones for easy looking, each one's letters all also appear in other digit words:
    one, three, five, seven, nine
*/


class Solution {
public:
    string originalDigits(string s) {
        vector<string> words = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        
        vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        
        vector<int> distinct_char = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        
        vector<int> counts(26, 0);
        
        string result;
        for(auto ch : s){ counts[ch-'a']++;}
        for(int i = 0; i < 10; i++){
            int count = counts[distinct_char[i]-'a'];
            for(int j = 0; j < words[i].size(); j++)
                counts[words[i][j]-'a'] -= count;
            while(count--)
                result += to_string(nums[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};




/*
class Solution {
public:
    string originalDigits(string s) {
        std::unordered_map<char, int> character_freq;
        std::vector<std::string> digit_strings = {"zero", "one", "two", "three", "four",
                                                 "five", "six", "seven", "eight", "nine"};
        
        std::unordered_map<std::string, std::string> str_to_digit_map ({
                                        {"zero", "0"}, {"one", "1"}, {"two", "2"}, 
                                        {"three", "3"}, {"four", "4"}, {"five", "5"}, 
                                        {"six", "6"}, {"seven", "7"}, {"eight", "8"}, 
                                        {"nine", "9"}
        });
        
        // Fill hashmap
        for(const char& c : s) {
            ++character_freq[c];
        }
    
        std::string res;
        for(const auto& str : digit_strings) {
            int search_index = 0;
            std::string build_string;
            while(true) {
                char search_char = str[search_index];
                
                if(character_freq[search_char] > 0) {
                    ++search_index;
                    --character_freq[search_char];
                    build_string += search_char;
                    
                    if(build_string.length() == str.length()) {
                        res += str_to_digit_map[str];
                        build_string.clear();
                        search_index = 0;
                    }
                    
                }
                
                else {
                    for(const char& c : build_string) {
                        ++character_freq[c];
                    }
                    break;
                }
            }
                
        }
        
        return res;
        
    }
};

*/
