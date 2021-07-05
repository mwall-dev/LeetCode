/*
    Notes:
        - Common Q that showcases the power of DP
        - Could do some recursive function but this ends up repeating calculations
        f(5) = f(4)   +   f(3)
              /   \       /  \
          f(3) + f(2)    f(2) + f(1)
          ...



        Can do a bottom up or top down DP approach.


    Approach : Bottom Up (simplier to understand)
        - For loop with 3 variables, prev1, prev2, sum
        - start at n = 0 and continue up until you reach n


    time: O(N)
    space: O(1) (would be O(N) if we used an array to store all results but we don't need) (maybe good to save time for multiple calls to Solution).





*/
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int nTake1 = 1;
        int nTake2 = 0;
        int sum = 0;

        for(int i = 2; i <= n; ++i) {
            sum = nTake1 + nTake2;
            nTake2 = nTake1;
            nTake1 = sum;
        }


        return sum;

    }
};