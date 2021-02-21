/*

    Use arrays with indicies with chars to get characters
    Approach 1:
    Build array maps for character frequencies for each string.
    Iterate though one of these maps and look at all other for max common count.
    Add this number of chars to the res list.


*/


class Solution {
public:
    std::vector<string> commonChars(std::vector<string>& A) {
        std::vector<std::vector<int> > char_freq;
        for(int i = 0; i < A.size(); ++i) {
            char_freq.push_back(std::vector<int>(26, 0));
        }

        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < A[i].length(); ++j) {
                ++char_freq[i][A[i][j] - 'a'];
            }
        }

        std::vector<string> res;
        for(int k = 0; k < 26; ++k) {
            if(char_freq[0][k] == 0) continue;
            
            char c = 'a' + k;
            int occurrences = char_freq[0][k];

            for(int i = 1; i < A.size(); ++i) {
                occurrences = min(char_freq[i][c - 'a'], occurrences);
            }

            while(occurrences) {
                res.push_back(std::string(1,c));
                --occurrences;
            }
        }

        return res;
    }
};