/*

    Let T[i][0] be the maximum profit that could be gained with at the end of the ith day
                WHERE we hold 0 stock AFTER taking the action 
        T[i][1] be same as above but 
                WHERE We hold 1 stock AFTEr taking the action

        Base Cases
        T[-1][0] = 0 As havent bought or done anything yet     
        T[-1][1] = -inf as impossible to sell when you have nothing.
            
        3 States: BUY, REST, SELL.


        Recurrence relations:
        T[i][0] = max(T[i-1][0], T[i-1][1] + prices[i])
        Action taken on ith day can only be REST with 0 OR SELL as since this is [0] column
        it means that we end up with 0 stock.
        So we take max of RESTING with 0 stock, SELLING.

        T[i][1] = max(T[i-1][1], T[i-1][0] - prices[i]
        Action taking on the ith day can only be BUY, REST with 1 as since this is [1] column 
        it means we end up with 1 stock.
        So we take the max of buying RESTING with 0 stock or buying.


*/



class Solution {
    public int maxProfit(int[] prices) {
        int[][] T = new int[prices.length][2];
        
        // Initialise first two values
        T[0][0] = 0;
        T[0][1] = -prices[0];

        int res = 0;

        for(int i = 1; i < prices.length; ++i) {
            T[i][0] = Math.max(T[i-1][0], T[i-1][1] + prices[i]);
            T[i][1] = Math.max(T[i-1][1], T[i-1][0] - prices[i]);
            res = Math.max(T[i][0], T[i][1]);
        }

        return res;
    }   
}


//Simplier Approach
// Just add increasing parts.
class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
}
