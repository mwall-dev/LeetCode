/*
    Approach:
        Start at MSB, we know its a 1.
        Iterate through string until you hit a zero.
        Keep iterating If there are any more ones after this, return false.


*/






class Solution {
public:
    bool checkOnesSegment(string s) {
        
        int index;
        
        while(s[index] == '1') ++index;
        
        
        while(index < s.length()) {
            if(s[index] == '1') return false;
            
            ++index;
        }
        
        return true;
        
    }
};