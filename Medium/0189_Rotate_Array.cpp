/*
    Notes:
        - Recall the circular buffer and how indicies can wrap around with i % n where n = array size
        - We can use this to calculate the next position for each element.


        - Say we have 1,2,3,4,5,6,7 and k = 3, answer is  5,6,7,1,2,3,4
          We know that the last k elements will wrap around (and be the new start), and everything else will just shift to the right k spaces and remain in-bounds.
          Knowing this, we could just append the last k items to the front.
          Appending to front is costly for vectors though.

          Reverse whole array.
          7,6,5,4,3,2,1

          Reverse the first k elemetns.
          Reverse the next elemnts from k to n.

          Need to work out case where n < k.

          [1,2,3]

          k = 1
          3,1,2

          k = 2
          2,3,1

          k = 3
          1,2,3

          k = 4
          3,1,2


          We actually see that  if k > n then the behaviour just loops around since we're just doing previous rotations.
          So a rotation of k is equaivalent to a rotation of k % n


          - Say we go back to the original strategy of placing elements at (i + k) % n. Instead of using an additional vector
            what if we record the value we override and just keep going.

            k = 3
            1,2,3,4,5,6,7
            0 1 2 3 4 5 6

            -1,2,3,1,5,6,4
            -1,2,7,1,5,3,4
            -1,6,7,1,2,3,4
            5,6,7,1,2,3,4


            k = 2

            THIS DOESNT WORK WHEN n % k == 0 (when k is a factor of n).







    Approach 1 : New array
        - Allocate a vector of size n.
        - Start at i = 0 and iterate through array.
        - Use the identity in notes to insert elements in their correct position.

        time: O(N)
        space: O(N)


    Approach 2: In-place using reverses
        -Reverse whole array.
          7,6,5,4,3,2,1

          Reverse the first k elemetns.
          Reverse the next elemnts from k to n.


    Approach 3: Cyclic-dependency where we keep moving and track element we override
        - Similar to approach 1 but just keep last value store and keep going.

    1,2,3,4,5,6,7
    1,2,1,4,5,6,7




*/
// Approach 4: Don't reinvent the wheel.
class Solution {
public:
    void rotate(vector<int>& v, int k) {
        std::rotate(v.rbegin(), v.rbegin() + k%v.size(), v.rend());
    }

};


/*
// Approach 3: Cyclic-dependency where we keep moving and track element we override
class Solution
{
public:
    void rotate(int nums[], int n, int k)
    {
        for (; k = k%n; n -= k, nums += k)
        {
            // Swap the last k elements with the first k elements.
            // The last k elements will be in the correct positions
            // but we need to rotate the remaining (n - k) elements
            // to the right by k steps.
            for (int i = 0; i < k; i++)
            {
                swap(nums[i], nums[n - k + i]);
            }
        }
    }
};
*/

/*
// Approach 2: Reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};

*/

/*

// Approach 1: New array
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        std::vector<int> result(nums.size());
        int n = nums.size();

        for(int i = 0; i < nums.size(); ++i) {
            int new_index = (i + k) % n;

            result[new_index] = nums[i];
        }

        nums = result;
    }
};

*/