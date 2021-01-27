""" 
    Approach 1: Brute Force.
        - Crazy triple nested loop checking every triplet
        time: O(n^3)

    Apporach 2: Use a hashmap and the previous problem 0001_Two_Sum.
        - Could basically put all values into a hashmap.
        - For each element in list, apply the two_sum function from earlier and make the target
        negative the element as we are looking to sum to 0. Maybe do all in one functon as we
        need to return the numbers themselves not indicies. Also need to fix for duplicates.
        - Completed below but returns too many duplicates.
        time:O(N^2)
    
    Approach 3: Sort first and then use pointers or hashmap.
        - time is N^2 anyway so can sort first to make easier.




"""
from typing import List
from collections import Counter


class Solution:

    # Approach 2
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        freq_map = Counter(nums)
        res = []

        for i, num in enumerate(nums):
            target = -num
            triplet = []

            for j in range(i + 1, len(nums)):
                search = target - nums[j]
                if search in freq_map and freq_map[search] > 0:
                    triplet = [num, nums[j], search]
                    res.append(triplet)
                    freq_map[search] -= 1

                freq_map[j] -= 1

            freq_map[i] -= 1


        return res

    # Approach 3  
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(0, len(nums) - 2): # As can ignore end as we need 3 elements

            # Ignore duplicates as we will evaluate all triplets anyway for first one.
            if i > 0 and nums[i] == nums[i-1]:
                continue
                     
            left = i + 1
            right = len(nums) - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]

                # Sum is too small, increment left index to get a LARGER number
                if s < 0:
                    left += 1

                # Sum is too large, deincrement right index to get a smaller number
                elif s > 0:
                    right -= 1

                # Found 0 
                else:
                    # Add result 
                    res.append([nums[i], nums[left], nums[right]])
                    
                    # Skip over duplicaes on both sides as would just be a duplicate entry.
                    while left < right and nums[left] == nums[left + 1]:
                        left += 1

                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    # Check next
                    left += 1
                    right -= 1
                        

        return res


        




if __name__ == "__main__":
    s = Solution()
    print(s.threeSum([-1,0,1,2,-1,-4]))