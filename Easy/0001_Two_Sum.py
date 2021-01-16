from typing import List

"""
    Approach 1: Super naive nested loop.
        - Iterate through nums. 
        - For each iteration, iterate though the whole loop and try to find number 
        that will sum with current number to get the target number.
        time: O(N^2)
        space: O(1)
    
    Apporach 2: Again naive
        - Iterate through nums.
        - For each iteration, look for complement using if complement in nums:
        time: O(N^2) as 'in' does a linear search.
        space: O(1)

    Approach 3: HashMap
        - Build map from list with key, val = num, list of indicies (list to record duplicates).
        - Iterate through list (or map) and search map for complements.

    Approach 4: HashMap optimized
        - Build map from list with same key val idea as above, but while
        you are building the map, you search each time for the complement to the element
        you've just added. This would require only one pass through the list.
    time: O(N)
    space: O(N)
    
    Note: Approach 4 is implemented below. Since we do it in one sweep of the list, we
    dont have to worry about duplicates so is much simplier.

"""





class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        index_map = {}
        
        for index, num in enumerate(nums):
            if target - num in index_map:
                return [index, index_map[target - num]]
            else:
                index_map[num] = index

        
    
            











if __name__ == "__main__":
    s = Solution()
    print(s.twoSum([1,5,2,3,5,3,1,2], 4))
