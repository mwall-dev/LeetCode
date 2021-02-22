/*
 *  Approach: Use .find() to get index where it first appears.
 *  Now need to figure out which word this belongs. Could pre-process and split words and use .find on all
 *  but this might be too costly.
 *  Instead just find where it is, and from that index count back to 0 and count spaces.
 *
 *  BELOW SOLUTION INVALID.
 *  input "pillow love winstontang i pillow corona you errichto love"
"i"
 * fails as it would see first i in pillow and just return -1.
 *
 *
 *
 * TO FIX:
 *
 * SEE APPROACH 2
 * PUT LEADING WHITESPACE INTO SENTENCE AND SEARCHWORD so it looks to match a space then the word as
 * we are looking for PREFIX.
 *
 *
 */



class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto res = sentence.find(searchWord);
        if(res == std::string::npos) return -1;
        if(isspace(sentence[res-1])) return -1;
        int num_spaces = 0;
        while(res > 0) {
            if(isspace(sentence[res--])) ++num_spaces;
        }

        return num_spaces + 1;

    }
};






// Approach 2

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        auto sent = " " + sentence, word = " " + searchWord;
        auto pos = sent.find(word);
        if (pos != string::npos)
            return count(begin(sent), begin(sent) + pos + 1, ' ');
        return -1;
    }
};