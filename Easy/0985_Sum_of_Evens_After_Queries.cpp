/*
 *
 *  Notes:
 *      - We have our nums = [1,2,3,4] and our queries = [[1,0],[-3,1],[-4,0],[2,3]] where for each pair [1,0], val = 1, index = 0.
        - nums[index] += val
        - The answer to ith query is the sum of all even elements.
        - Each modification permanently changes nums.

        - You might think a good optimisation would be to just pre scan whole array for even numbers and adjust accordingly when things are changed.
         but the queries can change numbers at any index. There is no order.

         -
 *
 *
 *
 *  Approach : Brute Force
 *      - Iterate through nums and queries in parallel.
 *      - For each query, we add the val to the specified index.
 *      - Then scan whole nums array for even numbers, sum and put into result vector.
 *
 *      time: O(N^2)
 *      space: O(1) not including res vector.
 *
 *  Approach: Optimised
 *      - We can use this pre scan result but we need to focus on the switching of even to odd and vice versa.
        - We should do an initial sweep sum of all the even numbers:
            and if a query changes a number from even to odd, we subtract the original even number from the running sum and this is our sum.
            and if a query changes a number from odd to even, we add this new even number to running sum and this is our sum.

        time: O(N)
        space:O(1) not including res vector.
 */

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        std::vector<int> query_results;
        int sum = std::accumulate(nums.begin(), nums.end(), 0,
                                  [](const int& current_sum , const int& num) {
                                        if(num % 2 == 0) return current_sum + num;
                                        return current_sum;
                                    });

        for(const auto& query : queries) {
            int val = query[0];
            int index = query[1];
            int prev = nums[index];

            nums[index] += val;
            int new_num = nums[index];

            // Even to odd
            if( prev % 2 == 0) {
                if(new_num % 2 != 0) sum -= prev;
                else sum += (new_num - prev);
            }

            // Odd to even (we don't care about odd to odd as still not included).
            else if(new_num % 2 == 0) {
                sum += new_num;
            }

            query_results.push_back(sum);
        }

        return query_results;

    }
};