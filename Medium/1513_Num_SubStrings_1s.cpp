
/*
    Approach:
        Need to find the lengths of all contigious groups of ones.
        



*/






class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        
        long long count = 0;
        for(const char& c : s) {
            if(c == '1') {
                ++count;
            }
            
            else {
                ans = (ans + count * (count + 1) / 2) % 1000000007;
                count = 0;
            }
        }
        
        if(count) {
            ans = (ans + count * (count + 1) / 2) % 1000000007;
        }
        
        return ans;
    }
};