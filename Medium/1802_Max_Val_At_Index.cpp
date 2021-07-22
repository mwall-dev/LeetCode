/*
    Notes:
        - All +ve or 0
        - Adjacent elements are either equal or -1 or +1 their neighbours.
        - Sum of elements <= maxSum
        - nums[index (given as arg)] is the maximum it can possibly be. (THIS IS THE RULE THAT EFFECTS WHAT THE ARRAY WILL LOOK LIKE AS THERE ARE MANY DIFFERENT COMBINATIONS THAT ARE VALID
        BUT THIS RESTRICTS).

        Hint 1: if the index param was instead replaced with some target value at an index, then we would sub this value in and work backwards from here building a valid staircase
        that sums to <= maxSum.

        Hint 2,3: so yeah once we have our target we basically place it at peak of a mountain (2345432), We can use a shortcut to find the sum of the elements on left and right of the target (they might not be equal though if the index is not the middle).
        Use the 1 + 2 + 3 ...  + n = n(n+1)/2. THis works if the array is so large that we will find ourselves at 0's on edges (we go all the way to 1's)    (000012343210000)


        How do we sum n is small, maxSUm is large so we arent reaching 0 on the edges?
        Say we need to sum not 1 to N but L to R, then just sum 1 to R and subtract sum 1 to l - 1. All O(1) formulas.
        https://www.geeksforgeeks.org/sum-of-all-natural-numbers-in-range-l-to-r/

        Hint 4: Use binary search to find target number. Test in the index place by using array size and index position and sum formulas.


        Note: question is stupid in that nums[i] can't be zero.


        IT AINT PRETTY BUT IT WORKS and 100% time.


*/



class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        if(n == 1) return maxSum;


        int start = 1;
        int end = maxSum;

        int result = 0;

        while(start < end) {
            int target = start + ((end - start)/2);
            long sum = target_sum(n, index, maxSum, target);

            if(sum <= maxSum) {
                result = std::max(result, target);
                start = target + 1;
            }
            else {
                end = target;
            }
        }

        return result;
    }


    long target_sum(int n, int index, int maxSum, int target) {
        long sum = target;

        if(index == 0) {}

            // Do we reach 1 on left side?
        else if(index + 1 >= target) {
            int spaces_left = index;
            spaces_left = spaces_left - (target - 1);
            // target - 1 is the number of numbers beween 1 and target.
            // Yes we reach 1, just sum 1 to target - 1
            sum += natural_sum(target - 1);
            if(spaces_left > 0) sum += spaces_left;

        }

        else {
            // No we don't.
            int R = target - 1;
            int L = target - index;
            sum += (natural_sum(R) - natural_sum(L - 1));
        }
        if(sum > maxSum) return maxSum + 1;

        if(index == n - 1){}


            // Do we reach 1 on right side.
        else if(n - index - 1 >= target - 1) {
            // Yes we reach 1, just sum 1 to target - 1
            sum += natural_sum(target - 1);
            int spaces_left = n - index - 1;
            spaces_left = spaces_left - (target - 1);
            if(spaces_left > 0) sum += spaces_left;
        }


        else {
            int R = target - 1;
            int L = target - (n-index-1);
            sum += (natural_sum(R) - natural_sum(L - 1));
        }

        //std::cout << "Target: " << target << " Sum: " << sum << '\n';
        return sum;



    }


    long natural_sum(long n) {
        long sum = (n * (n + 1)) / 2;
        return sum;
    }


};

