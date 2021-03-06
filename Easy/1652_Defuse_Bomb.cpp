
/*
    Approach: Build a new vector
    (Since all numbers are replaced simultaneously, we require
    the numbers we change.)
    
    for i = 0 to n - 1
        get starting num
        
        depending on k go back or forward with a for loop and sum OR just make zero.
        Use modulo for wrapping indicies around (n-1 -> 0).
        Use check for -ve for wrapping indicies other way (0 -> n-1).
        
        Add to new vector.
        
    time:O(nk)
    space:O(n)


    Approach 2: Sliding window
    time: O(n)
    space: O(1)
    See online

*/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        std::vector<int> decrypted;
        
        int size = code.size();
        
        for(int i = 0; i < code.size(); ++i) {
            
            int sum = 0;
            
            if(k == 0) {
                decrypted.push_back(sum);
                continue;
            }
            
            else if(k > 0) {
                int index = (i + 1) % size;
                for(int count = k; count > 0; --count) {
                    sum += code[index];
                    index = (index + 1) % size;
                }
            }  
            
            else {
                int index = (i - 1) % size;
                if(index < 0) index = size - 1;
                
                for(int count = -k; count > 0; --count) {
                    sum += code[index];
                    int check = (index - 1) % size;
                    index = check < 0 ? size - 1 : check; 
                }
                    
            }
            
            decrypted.push_back(sum);
        }
        
        return decrypted;
    }
};