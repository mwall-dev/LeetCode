/*
    Approach:
    If n = odd then add 0 to result.
    Now n is even 
    just include all pairs starting from 1. e.g. -1,1    -2,2 ... 
    
    
    







*/




class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        
        if(n % 2) {
            res.push_back(0);
            --n;
        }
        
        n = n/2;
        
        
        int start = 1;
        while(n) {
            res.push_back(start);
            res.push_back(-start);
            ++start;
            --n;
        }
        
        return res;
    }
};
