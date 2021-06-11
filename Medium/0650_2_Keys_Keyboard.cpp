/*
 *  Notes:
 *      - Abstraction of a lower number problem.
 *      - We start at n = 1.
 *      - Our operations are:
 *          - Record number on screen, k = n
 *          - Add k to n: n = n + k
 *
 *
 *      - We can only hold one variable in k and may need to reuse to get min.
 *      - Copy operations cost so don't want to do them unless we need a jump greater
 *      than the current k. Don't want to overstep and jump too close and now we don't have a low
 *      enough k to arrive.
 *
 *
 *  Approach 1 : Brute Force Recursive.
 *      - Start at n = 1, k = nothing. No copy yet.
 *      - At each step we choose to move into k (don't move if value is equal) or add to n.
 *      - Use a global and return result.
 *      - This is a bottom up approach where we are trying every possible path.
 *
 *
 *  Approach 2 : Math
 *      - It takes 2 ops to x2, 3 ops to x3
 *      - So if n % 2 == 0 (n is divisible by 2), then moves(n) = moves(n/2) + 2
 *      - This can be generalised to if n % i == 0 (n is divisible by i), then
 *      moves(n) = moves(i/2) + 2)
 *      - So you're basically finding all factors.
 *      - Implement this in a simple loop
 *
 *
 *
 */
// Approach 2 : Math
class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};



// Approach 1 : Brute Force.
class Solution {
private:
    int res = INT_MAX;
    int goal;
public:
    void calc(int n, int k, int ops) {
        if(n > goal) return;
        if(n == goal) {
            res = std::min(res, ops);
            return;
        }

        // Copy into k if you haven't.
        if(k != n) {
            calc(n, n, ops + 1);
        }

        // Try adding n.
        calc(n + k, k, ops + 1);


    }
    int minSteps(int n) {
        if(n == 1) return 0;

        goal = n;

        calc(1, 1, 1);
        return res;
    }
};