
/*
    Approach:
        Just use a for loop and store last three.

*/




class Solution {
public:
    int tribonacci(int n) {
        int T0 = 0, T1 = 1, T2 = 1;
        
        if(n < 3) {
            if(!n) return 0;
            else return 1;
        }
        
        int res;
        
        for(int i = 3; i <= n; ++i) {
            res = T0 + T1 + T2;

            T0 = T1;
            T1 = T2;
            T2 = res;
        }
        
        return res;
    }
};
