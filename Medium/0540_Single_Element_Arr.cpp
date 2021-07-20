/*
    Notes:
        - To achieve log n time and n space, this has to be some sort of binary search.
        - We don't know where the single element is.
        - Since the array is sorted, we know that every other element will be next to its neighbour.

        - Okay lets think binary search:
            You start at mid point, what do you check to determine whether or not you go left or right.
            There will be an odd number of elements of course, as the array is made up of all pairs + 1 unique number.
            Maybe we can exploit this. The the example case:
            1,1,2,3,3,4,4,8,8
            we start at mid = 4 and look left and right 1 space to see where the pair is for this one.
            In this case, the pair is on the left. So now there are mid - 1 (3) elements on left and mid (4) elements on right.
            So now, we know that the unique element must be somewhere on left since it has an odd number of elements.
            The check at the start where we look left and right 1 space will eventually show no pair and this is our result.


    Approach : HashMap
        - Put all elements into freqMap and then look for one that is only in once.

    time:O(N)
    space:O(N)


    Approach: Space optimised just look ahead and see if its same
        - Iterate through array with i+=2
        - If nums[i] != nums[i+1] then return nums[i]
        - else continue;

    time: O(N)
    space: O(1)



    Approach: Something binary search-like
        - Classic binary search with a different moving left/right criteria.
        - Initialise your standard left and right pointers and use a while left < right loop
            - mid = left + right / 2
              - Get mid element and check if its pair is one to the left or one to the right. (if not found then this is ans).
              - Calcualte rest of elements that are left and right of this pair to each end. One number will be even and one odd.
              - Note that you do need to still calculate the above. (pair element on left does not mean we go left neccessarily, look at both examples, this is due to 2*odd = even and 2*even = even )
              - You go in the odd direction.
              - Maybe there is some cooked math thing going on here where if pair is on left you go that way.

    time: O(logN)
    space: O(1)

*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = (left + right) / 2;

            int mid_element = nums[mid];

            int left_elements;
            bool pair_left;

            // Pair is on right.
            if(nums[mid] == nums[mid + 1]) {
                left_elements = mid - left;
                pair_left = false;
            }


                // Pair is on left
            else if(nums[mid] == nums[mid - 1]) {
                left_elements = (mid - 1) - left;
                pair_left = true;
            }

            else {
                return nums[mid];
            }

            // Go left if odd number of elements on left.
            if(left_elements % 2 == 1) {
                if(pair_left) right = mid - 2;
                else right = mid - 1;
            }

            else {
                if(pair_left) left = mid + 1;
                else left = mid + 2;
            }

        }

        return nums[left];

    }
};