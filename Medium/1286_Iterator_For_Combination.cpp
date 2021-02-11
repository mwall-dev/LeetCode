/*
    Approach:
        - Preprocess all combinations
            - Do this by generating all combos of the length given (it may differ from length 
            of string characters)
                - Do this by using a bitmask. Can get all combinatons by iterating through 
                numbers 2^k to 0(k = length of string characters). We only take combos when the 
                number has 1 bits equal to the combo length. Note: we do from 2^k to 0 and not
                0 to 2^k as we want lexicographical ordering though this will not be perfect
                so still need to sort and reverse.
            
                Need a method to count number of bits in a number
        - Other methods are then straightforward 





*/

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>




class CombinationIterator {
    private:
        std::vector<std::string> combinations;

    public:
        CombinationIterator(std::string characters, int combinationLength) {
            for(int k = ((int)std::pow(2,characters.length())) - 1; k > 0; --k) {
                if(number_of_one_bits(k) == combinationLength) {
                    combinations.push_back(build_combo(characters, combinationLength, k));
                }
                
            }
            std::sort(combinations.begin(), combinations.end());
            std::reverse(combinations.begin(), combinations.end()); 
        }

        int number_of_one_bits(int num) {
            int count = 0;
            while(num > 0) {
                count += ((num & 1) == 1);
                num >>= 1;
            }
            return count;
        }

        std::string build_combo(const std::string& characters, int length, int num) {
            int index = 0;
            std::string res;

            while(length > 0 && num > 0) {
                if((num & 1) == 1) {
                    res += characters[index];
                    --length;
                }
                ++index;
                num >>= 1;
            }
            return res;
        }
        
        std::string next() {
            std::string res = combinations.back();
            combinations.pop_back();
            return res;
        }
        
        bool hasNext() {
            return !combinations.empty();
        }
    
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

