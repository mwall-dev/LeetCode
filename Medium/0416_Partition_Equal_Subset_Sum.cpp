/*
 *
 *  Notes:
 *      - For a solution to exist, we need the total sum to be divisible by 2 as the subsets must sum to an equal number.
 *      - This is not all though, we also need to see if the numbers exist that can get us the two subsets with equal sums.
 *      (One number might be > the equal half sum or there might be alot of numbers and they cant be combined in a way to sum to
 *      the equal half.
 *
 *      - So then its just a matter of finding two sets of numbers that sum to the target number.
 *      - Its actually just a matter of finding one set of numbers that sums to the target number (total_sum/2) as
 *      if we do then the rest of the set should contain the other numbers and should sum to total_sum/2
 *      - So really its can we build a set of numbers that (total_sum/2) and then return true.
 *
 *
 *      -
 *
 *
 *
 *  // TOO SLOW
 *  Approach:
 *      - Sum all numbers of array.
 *      - Check its evenly divisible by 2.
 *      - If not return false.
 *      - If it is then use a recursive function to search for set (try with and without next element).
 *
 *      Need an exit early to improve speed.
 *      This is too slow
 *
 *
 *
 *  Approach: DP
 *      - This is a DP problem (the knapsack problem).
 *      - Bascially we are looking to see if there are numbers in a set that sum perfectly to the total_sum/2
 *      - This is called a 0/1 knapsack probelm (for each number we add it or not).
 *      - CBS
 *
 *
 *
 *  Approach : Bitwise
 *      - Just cooked
 *
 */



// TOO SLOW
class Solution {
private:
    int target;
public:

    bool find_set(std::vector<int>& nums, int index, int sum) {
        if(sum == target) return true;
        if(sum > target) return false;
        if(index == nums.size()) return false;

        // Include the ele at index        OR    dont include ele.
        return find_set(nums, index + 1, sum + nums[index]) || find_set(nums, index + 1, sum);
    }

    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0) return false;

        target = sum / 2;
        std::sort(nums.begin(), nums.end());
        return find_set(nums, 0, 0);


    }
};

// Still to slow

class Solution {
private:
    int target;
public:

    bool find_set(std::vector<int>& nums, int index, int remaining_sum) {
        //std::cout << "index: " << index << " remaining: " << remaining_sum << '\n';

        if(index >= nums.size() || remaining_sum < nums[index]) return false;
        if(remaining_sum == nums[index]) return true;

        // Include the ele at index        OR    dont include ele.
        return find_set(nums, index + 1, remaining_sum - nums[index]) || find_set(nums, index + 1, remaining_sum);
    }

    bool canPartition(vector<int>& nums) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if(sum % 2 != 0) return false;

        target = sum / 2;
        std::sort(nums.begin(), nums.end());
        //for(int num : nums) {cout << num << '\n';}
        return find_set(nums, 0, target);


    }
};






