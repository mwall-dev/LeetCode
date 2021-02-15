/*

    Approach 1:
        - Iterate though each string and save index for last char each time.
        if # then go back and delete last char.

        Just string build.


    Apporach 2:

        - Iterate through strings in reverse and if you find hash just skip next char 
        you find.








*/





class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s = clean_string(S);
        string t = clean_string(T);
        
        return s == t;

    }

    string clean_string(const string& str) {
        string ans;
        for(const char& c : str) {
            if(c == '#') {
                if(!ans.empty()) ans.pop_back();
            }
            else ans.push_back(c);
        }

        return ans;
    }
};

