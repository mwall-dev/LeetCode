/*

    Approach 1: Brute force but doesnt work.
        - Work your way along string and count swaps you make.
        - return swaps
        
    Approach 2: slightly optimised
        - Question asks for minimum. We may not get that.
        e.g. 11110101100
            if we start from index i and compare with i + 1.
            we get 4 swaps 
            
            if we start from index i and compare with i - 1.
            we get 7 swaps 
            
        We could iterate through twice and check for both answers and compare min.
        
        Basically we know end string will either be  0101010... or 101010... Starting with 1 or 0.
        Try both ways and take min.
        
        
    Approach 3: more optimised 
    Dont need to do second run through. Second sweep res is just length - first_res.
    
    
*/



class Solution {
public:
    int minOperations(string s) {
        
        auto check_string = [](string s, char start) {
            int swaps = 0;
            if(s[0] != start) {
                s[0] = start;
                ++swaps;
            }
        
            // Looking behind.
            for(int i = 1; i < s.length(); ++i) {
                if(s[i] == s[i-1]) {
                    s[i] = s[i] == '0' ? '1' : '0';
                    ++swaps;
                }
            }
            return swaps;
        };
        
        int res = check_string(s, '0');
        int n = s.length();
        return std::min(res, n - res);
        
    }
};