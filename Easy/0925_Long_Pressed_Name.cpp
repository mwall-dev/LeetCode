/*
    Notes:
        - Can't just naively search eliminate all adjacent dups in typed as 
        the name itself might have dups in it e.g. saeed
        
        - Can't just do hashmap for characters and compare as ordering is important.
    
    Approach:
        - Cycle through typed and have an index for name as well.
        - Try to go along typed and search for all charcters in name incrementing when youre at a dup 
        that doesnt match with name.
        - If you reach end of name, found name.
        
        - else false.
    

*/




class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(typed.length() < name.length()) return false;
        
        int i = 0;
        int j = 0;
        
        if(name[0] != typed[0]) return false;
        
        while(i < name.length() && j < typed.length()) {
            if(name[i] == typed[j]) {
                ++i;
                ++j;
                continue;
            }    
            
            if(typed[j] == typed[j - 1]) {
                ++j;
                continue;
            }
            
            return false;
        }
        
        if(i < name.length()) return false;

        while(j < typed.length()) {
            if(typed[j] != typed[j - 1]) return false;
            ++j;  
        }
        
        return true;
    }
};
