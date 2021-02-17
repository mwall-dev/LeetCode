/* Our writing from previous question:

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


Taking the above into account, we now need to factor in number of transactions.
Add another dimension to the problem

Let T[i][k][0] be the max profit that could be gained with at the end of ith day
    WHERE we hold 0 stock after taking the action and we do at most k trades.

Let T[i][k][1] be the max profit that could be gained with at the end of the ith day
    WHERE we hold 1 stock after thaking the aciton and we do at most k trades.

Base cases
T[-1][k][0] = 0 as no buys yet as no prices.
T[i][0][0] = 0 as no trades
T[-1][k][1] = -inf as cant hold  any stock after no days of buying
T[i][0][1] = -inf as cant hold any stock after no trades

Recrurence relations:
T[i][k][0] = max(T[i-1][k][0], T[i-1][k][1] + prices[i])
T[i][k][1] = max(T[i-1][k][1], T[i-1][k-1][0] - prices[i])

*/












class Solution {
    public int maxProfit(int[] prices) {
        int[][][] T = new int[prices.length][3][2];
       
        T[0][1][0] = 0; T[0][1][1] = Integer.MIN_VALUE;
        T[0][2][0] = 0; T[0][2][1] = Integer.MIN_VALUE;

        for(int i = 1; i < prices.length; ++i) {
            T[i][2][0] =  Math.max(T[i-1][2][0], T[i-1][2][1] + prices[i]);// REST WITH 0 or SELL 
            T[i][2][1] =  Math.max(T[i-1][2][1], T[i-1][1][0] - prices[i]);// REST WITH 1 or BUY
            T[i][1][0] =  Math.max(T[i-1][1][0], T[i-1][1][1] + prices[i]);// REST WITH 0 or SELL
            T[i][1][1] =  Math.max(T[i-1][1][1], -prices[i]); // REST WITH 1 or BUY

            // For last line: As with one you will only have one buy
        }
        
        return T[prices.length-1][2][0];
    }
}