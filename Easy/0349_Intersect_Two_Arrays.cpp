/*
 *  Notes:
 *
 *
 *
 *  Approach 1 : Brute Force
 *      - For each element in array 1, do a full sweep of array 2 to search for it.
 *      - If found than add to result if its not already there.
 *
 *      time: O(N^2)
 *      space: O(N)
 *
 *
 *  Approach 2: Sort
 *      - Sort both arrays and use two pointers.
 *      - Store the last one found as a variable so you can compare against and avoid duplicates
 *      (only want unique).
 *
 *      time: O(NlogN)
 *      space O(N)
 *
 *
 *  Approach 3: HashMap
 *      - Put one array into an unordered_set, iterate through the other.
 *      - For each element in array, search for it in unordered_set and add.
        - To avoid unique elements, store all found in another unordered_set first.

        time: O(N)
        space: O(N)

    Approach 4: Arrays
        - The values are only in the 0 - 1000 range.
        - Use approach 3 but just use arrays.
 */



// Approach 4 Slower than optimised 3.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int arr_1[1001] = {0};

        for(const int& num : nums1) {
            arr_1[num] = 1;
        }


        std::vector<int> res;
        int arr_found[1001] = {0};

        for(const int& num : nums2) {
            if(arr_1[num]) {
                if(!arr_found[num]) {
                    res.push_back(num);
                    arr_found[num] = 1;
                }
            }

        }

        return res;
    }
};

// Approach 3
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());

        std::unordered_set<int> intersect;

        for(const int& num : nums2) {
            if(nums1_set.find(num) != nums1_set.end()) {
                if(intersect.find(num) == intersect.end()) {
                    intersect.insert(num);
                }
            }

        }

        return std::vector<int>(intersect.begin(), intersect.end());
    }
};

// Optimised Approach 3 using array for lookup.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> nums1_set(nums1.begin(), nums1.end());

        std::vector<int> res;

        int arr_found[1001] = {0};

        for(const int& num : nums2) {
            if(nums1_set.find(num) != nums1_set.end()) {
                if(!arr_found[num]) {
                    res.push_back(num);
                    arr_found[num] = 1;
                }
            }

        }

        return res;
    }
};