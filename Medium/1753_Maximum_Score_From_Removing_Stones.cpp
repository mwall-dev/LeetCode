/*
 * Notes:
 *  Looks to be about the differences between piles.
 *  Also about the odd/eveness of a pile.
 *
 *  Will always choose two largest numbers to start.
 *
 *  Hint 2 states the pile sizes are small enough for simulation so might not be a shortcut and
 *  need to just play it out.
 *
 *
 *
 * Approach:
 *  Put 3 piles into a heap.
 *  Take top 2. Add 1 to res. Re-add the taken out numbers to heap both with 1 less stone each.
 *  Back to step 1 until heap is empty.
 *
 *
 *  Optimised:
 *      Looks like there might be a shortcut as our relative time wasn't great.
 *      Suss the solutions. Theres a math and a recursive approach.
 *
 *
 *
 *      The math approach is good and simple.
 *
 *      Math:
 *      Looking at the 3 numbers, Lets call the biggest hi and then the other two lo1 and lo2.
 *
 *      If h1 > lo1 + lo2
 *          Then we can take all the stones from lo1 and lo2
 *          so the answer is just lo1 + lo2
 *
 *       if hi < lo1 + lo2
 *         Then we can either take all stones (if even total) OR leave only one stone(if odd total)
 *
 *
 *
 */

int maximumScore(int a, int b, int c) {
    int largest = max({a, b, c}), total = a + b + c, sumOfOtherTwo = total - largest;
    return largest >= sumOfOtherTwo ? sumOfOtherTwo : total/2;
}

/*
int maximumScore(int a, int b, int c) {
    if (a < b)
        return maximumScore(b, a, c);
    if (b < c)
        return maximumScore(a, c, b);
    return b == 0 ? 0 : 1 + maximumScore(a - 1, b - 1, c);
}
 */

/*
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        std::priority_queue<int> heap;

        heap.push(a);
        heap.push(b);
        heap.push(c);

        int score = 0;
        while(heap.size() >= 2) {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            ++score;
            if(--first) heap.push(first);
            if(--second) heap.push(second);

        }

        return score;


    }
};

 */