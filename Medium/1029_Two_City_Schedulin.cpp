
#include <vector>

/*

    Notes:
        We are given 2n vectors, each with the cost of flying that person to city A or city B.
        We want to get the min cost of flying everyone but we need n people at A and n people at B exactly.
        COMPARE BY SAVING.


    Approach : Sort, Greedy
        Sort with a lambda whereby we compare vectors for differecne between A and B with larger savings going first.
        Ones with a smaller B will have a negative saving.
        How much money can we save if we fly a person to A vs. B? To minimize the total cost, we should fly the person with the maximum saving to A, and with the minimum - to B.

        Example: [30, 100], [40, 90], [50, 50], [70, 50].
        Savings: 70, 50, 0, -20.

        Obviously, first person should fly to A, and the last - to B.

        Solution
        We sort the array by the difference between costs for A and B. Then, we fly first N people to A, and the rest - to B.

*/



class Solution {
public:
    int twoCitySchedCost(std::vector<std::vector<int>>& cs) {
        int res = 0;

        std::sort(begin(cs), end(cs), [](vector<int> &v1, vector<int> &v2) {
            return (v1[0] - v1[1] < v2[0] - v2[1]);
        });

        for(const auto& vec : cs) {
            std::cout << vec[0] << " " << vec[1] << std::endl;

        }
        for(auto i = 0; i < cs.size() / 2; ++i) {
            res += cs[i][0] + cs[i + cs.size() / 2][1];
        }

        
        return res;
        

    }
};