/*
    Approach:
        1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
        M T W T F S S M T W  T   F S  S  M 
        1 2 3 4 5 6 7 
        
        Rule:
       if((i - 1) % 7 == 0) {
                res += monday_deposit++;
                daily_deposit = monday_deposit;
            }
            
            else res += daily_deposit++;
        

        time:O(N)
        
        
    Approach: Math
                    M                           M
        Sequence is 1 + 2 + 3 + 4 + 5 + 6 + 7 + 2 + 3 + 4 + 5 + 6
        So its like its resetting.
        Some cooked arithmetic sequence, see the discussion page.
    
    time:O(1)

*/


class Solution {
public:
    int totalMoney(int n) {
        int daily_deposit = 1;
        int monday_deposit = 1;
        
        int res = 0;
        
        for(int i = 1; i <= n; ++i) {
            if((i - 1) % 7 == 0) {
                res += monday_deposit++;
                daily_deposit = monday_deposit;
            }
            
            else res += daily_deposit++;
            
            std::cout << res << std::endl;
        }
        
        return res;
    }
};
