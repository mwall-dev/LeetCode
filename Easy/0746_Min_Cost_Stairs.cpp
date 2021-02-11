
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

/*
    Approach: DP problem
    Hint: f[i] is cost to climb to the top from step i then f[i] = cost[i] + min(f[i+1],f[i+2])
    Approach 1: Too long 


    Apporach 2: Bottom up DP
    https://leetcode.com/problems/min-cost-climbing-stairs/discuss/476388/4-ways-or-Step-by-step-from-Recursion-greater-top-down-DP-greater-bottom-up-DP-greater-fine-tuning





*/



// Approach 1: Too long 
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        return std::min(minCost(cost, cost[0], 0),
                        minCost(cost, cost[1], 1));
    }

    int minCost(const std::vector<int>& cost, int sum, int i) {
        if(i >= cost.size() - 2) {
            return 0;
        }

        return std::min(minCost(cost, sum + cost[i + 1], i + 1), 
                        minCost(cost, sum + cost[i + 2], i + 2));
    }
};


// Approach 2 
class Solution {
    public:
        int minCostClimbingStairs(std::vector<int>& cost) {
            int n = cost.size();
            std::vector<int> dp(n);
            for (int i = 0; i < n; ++i) {
                if (i < 2) dp[i] = cost[i];
                else dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
            }
            return std::min(dp[n-1], dp[n-2]);

        }
};


/*
    Even more fine tuning.
    // Bottom up computation - O(n) time, O(1) space
public int minCostClimbingStairs(int[] cost) {
	int n = cost.length;
	int first = cost[0];
	int second = cost[1];
	if (n<=2) return Math.min(first, second);
	for (int i=2; i<n; i++) {
		int curr = cost[i] + Math.min(first, second);
		first = second;
		second = curr;
	}
	return Math.min(first, second);
}



/