/*

    Approach 0: Lambda Sort 
        - Bad time complexity but would be a one liner 
        std::sort(A.begin(), A.end(), [](int x, int y){ return (some truth condition) }
        time: O(nlogn)
        space:O(1)


    Approach 1: Brute Force
        - Iterate through array building two vectors: one that holds odd nums and one that 
        holds even nums
        - Concat vectors
        time: O(n)
        space: O(n)

    Approach 2: Two Pointers (in place)
        - Start with two pointers at either end of array.
        - Iterate through array and if you find even then swap with left pointer and increment left
        - If you find odd swap with right pointer and deincremenet right.
        - Be sure to not increment index as you need to check number you've swapped.
        - Stop when two pointers meet.
        time:O(n)
        space:O(1)
*/





#include <vector>




class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int> &A) {
        for (int i = 0, j = 0; j < A.size(); j++)
            if (A[j] % 2 == 0) std::swap(A[i++], A[j]);
        return A;
    }
};

