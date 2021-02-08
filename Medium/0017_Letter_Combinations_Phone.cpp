#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;




/*
    Apporach 1: Brute Force
        - Given input get all letters. e.g. 2-3-4 would give "abc" "def" "ghi"
        - If its a simple known number of letters than would just use a number of nested for 
        loops to build the combos but in this case we will need to use some form of recursion.

        - Visualse each number in sequence as a node with multiple options. Each node
        needs to branch of a branch for each of its letters

        2 - 3  - 4 

        a            b              c
    d   e   f     d  e   f       d  e   f
  ghi  ghi  ghi  ghi ghi ghi    ghi ghi ghi  






*/
class Solution {
public:
    unordered_map<int, string> digit_to_letters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> combinations;

    vector<string> letterCombinations(string digits) {
        build_combos(digits, "");
        return combinations;
    }

    void build_combos(string digits, string combo) {
        if(digits.empty()) {
            combinations.push_back(combo);
            return;
        }

        string letters = digit_to_letters[digits[0]];
        for(char letter : letters) {
            string to_add(1, letter);
            build_combos(digits.substr(1), combo + to_add);
        }
    }



};







int main() {
    Solution s;

    vector<string> res = s.letterCombinations("2345");

    for(auto combo: res) {
        cout << combo << " ";
    }
    cout << "\n"; 

    
}