
/*

    Notes: Dynamic Programming

    Apporach
        - Initialise two variables, a min price to be prices[0] 
        and a max profit to be prices[1]-prices[0]

        Iterate thorough each price starting at prices[1]
        calculate potential profit with regards to min price

        maxProfit = max(maxPorfit, potenital profit)
        minPRicd = min(min_price, current_price)


    Not obvious but we are using the fact that buys must happen before sells and 
    therefore the above logic holds. One might think if you reset the min price you're
    missing out on a larger earlier gap but you will process these.
    Could be classified as greedy






*/




class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length <= 1) return 0;
        
        int minPrice = prices[0];
        int maxProfit = prices[1] - prices[0];

        for(int i = 0; i < prices.length; ++i) {
            int potenitalProfit = prices[i] - minPrice;
            
            maxProfit = Math.max(maxProfit, potenitalProfit);
            minPrice = Math.min(minPrice, prices[i]);

        }
        if(maxProfit <= 0) {
            return 0;
        }

        return maxProfit;
    }
}