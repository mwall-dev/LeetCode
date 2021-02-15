

/*
    Apporach 1: Bits

    




*/




class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        bool found_one = false;
        while(n > 0) {
            if((n & 1) == 1) {
                if(!found_one) found_one = true;
                else return false;
            }
            n >>= 1;
        }
        
        return found_one;
    }
};


/*




Crazy solution 

if(n<=0) return false;
        return !(n&(n-1));
*/