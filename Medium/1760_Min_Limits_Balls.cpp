/*
 *  Notes:
 *      - Trying to minimize the maximum.
 *      - Whats the minimum maximum you can get after the operations?
 *      - Since we have to take the maximum as the answer, we want to split as evenly as possible:
 *          For example: to split 5, you choose 2,3 as 1,4 or 4,1 are worse options.
 *          Although this isn't true of the first example. 9->6,3 and not 5,4 as you can then go 6,3->3,3,3
 *
 *
 *      - Need to look at cases for even and odd.
 *          Even is better as the divide by 2 will be more powerful as odd will always have a +1.
 *
 *      - The operations also effect the strategy. For example 9 and 1 op -> 4,5 -> 5
 *                                                             9 and 2 ops ->6,3 ->3,3,3 -> 3
 *
 *
 *      - Hint 1: If we know the max size of a bag, what is the minimum number of bags you can make?
 *      - Hint 2: As the max size increases, the minimum number of bags decreases so we can binary search the max size.
 *
 *
 *
 *  Approach:
 *
 *
 */


int minimumSize(vector<int>& A, int k) {
    int left = 1, right = 1e9;
    while (left < right) {
        int mid = (left + right) / 2, count = 0;
        for (int a : A)
            count += (a - 1) / mid;
        if (count > k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}