/*
    Approach:
    Notes:
        Ideally want to maximise number of +-2 jumps as they are free.
                     to minimise number of +-1 jumps as they have a cost.
                     
        Always comes down to the chip being 1 or 0 positions off. Will only ever need to do 
        1 or 0 +-1 for a chip.
        
        Count the number of of odd numbered chips and even numbered chips.
        Lets say there are more odd numbered chips. So now all other odd numbered chips can be moved and stacked for free on
        an odd numbered index.
        
        Now the solution is just the count of the even chips as they will all need 1 +-1 move.
        
*/




class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        int odd = 0;
        
        for(const int& pos : position) {
            if(pos % 2) ++odd;
            else ++even;
        }
        
        return min(even, odd);
    }
};