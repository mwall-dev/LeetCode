/*
    Approach 1: Iterate through and delete as you go.
    Iterate through string.
    
    For a group of adjacnet identical characters. The cost will be sum_cost(group) - max_cost(group). 



*/


class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        
        int min_cost = 0;
        int i = 0;
        
        while(i < s.length()) {
            char current = s[i];
            int max_cost = cost[i];
            int sum_cost = cost[i];
            
            ++i;
            while(current == s[i] && i < s.length()) {
                max_cost = std::max(max_cost, cost[i]);
                sum_cost += cost[i];
                ++i;
            }
            
            min_cost += (sum_cost - max_cost);
        }
        
        return min_cost;
    }
};
