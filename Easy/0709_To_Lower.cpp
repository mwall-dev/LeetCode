
/*
 * Approach:
 *  - Cycle through string and check if each character is uppercase using isupper() then change.
 *
 * Approach:
 *  - Exploit the fact that A-Z is ascii 65-90 and that respective lowercase characters are + 32 away.
 *
 */
class Solution {
public:
    string toLowerCase(string str) {
        for(char& character : str) {
            if(character <= 90 && character >= 65) {
                character += 32;
            }
        }
        return str;
    }
};

