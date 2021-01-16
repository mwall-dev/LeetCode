
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/* 
    Sorting via custom comparator.

    First turn all numbers into string form.
    Basically for each pair of numbers, there are two combinations:
    e.g. 9 and 44 can be 944 or 449. 
    The > operator for string looks at strings lexiographically so we can exploit this
    in a lambda function.
    Then it is just concatenating the elements of the sorted string array.

    The last while loop is just to handle the input {0,0}
    
*/
class Solution {
public:
    std::string largestNumber(std::vector<int> &num) {

        std::vector<std::string> arr;

        for(auto i : num) {
            arr.push_back(std::to_string(i));
        }

        std::sort(begin(arr), end(arr), 
            [](std::string &s1, std::string &s2){ return s1+s2>s2+s1; });

        
        std::string res;
        for(auto s : arr)
            res+=s;
        
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res; 
    }
};






int main() {
    Solution solve;
    std::vector<int> input {1,92,104,23,2241,2};
    std::cout << solve.largestNumber(input);

}