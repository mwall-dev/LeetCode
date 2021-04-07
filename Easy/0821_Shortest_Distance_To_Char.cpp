/*
    Approach : Brute Force
        - For each char look ahead to nearest occurence of c.
    
    time : O(N^2)
    space : O(1)
    
    Approach : Optimised 
        - Scan through array and record the positions of each occurece of the character.
        - Work thorugh array again this time also looking at the indicies of the occurences and cycle through to find the closest one.
        - Optimise here, you can cut off if(indicies_of_c[j] > i) but also need a cutoff for starting.
        
        
        
    time: O(N)
    space: O(N) worst case if whole array is the character.
    
    

    Approach : Even more optimised
        - Initial result array.
        - Loop twice on the string S.
        - First forward pass to find shortest distant to character on left.
        - Second backward pass to find shortest distant to character on right.
        
        Very smart to initailly set pos to -size, write it out and see how it goes.
        Same time but less memory on this one.


*/

class Solution {
    public:
  vector<int> shortestToChar(string S, char C) {
        int n = S.size(), pos = -n;
        vector<int> res(n, n);
        for (int i = 0; i < n; ++i) {
            if (S[i] == C) pos = i;
            res[i] = i - pos;
        }
        for (int i = pos - 1; i >= 0; --i) {
            if (S[i] == C)  pos = i;
            res[i] = min(res[i], pos - i);
        }
        return res;
    }
  
    
}; 
/*
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        std::vector<int> indicies_of_c;
        
        for(size_t i = 0; i < s.length(); ++i) {
            if(s[i] == c) indicies_of_c.push_back(i);        
        } 
        
        std::vector<int> res;
        int current_c_index = 0;
        
        for(int i = 0; i < s.length(); ++i) {
            if(s[i] == c) {
                res.push_back(0);
            }
            else {
                int current_min = std::abs(i - indicies_of_c[0]);
                
                for(int j = current_c_index; j < indicies_of_c.size(); ++j) {
                    int distance = std::abs(i - indicies_of_c[j]);
                    if(distance <= current_min) {
                        current_min = distance;
                        current_c_index = j;
                    }
                    
                    if(indicies_of_c[j] > i) break;
                }
                
                res.push_back(current_min);
            }

        } 
        return res;
    }
};

*/
