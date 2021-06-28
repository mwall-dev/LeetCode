class Solution {
public:
    void reverseString(vector<char>& s) {
        auto it_left = s.begin();
        auto it_right = s.end() - 1;


        while(it_left < it_right) {
            char temp = *it_left;
            *it_left = *it_right;
            *it_right = temp;
            ++it_left;
            --it_right;
        }
    }
};