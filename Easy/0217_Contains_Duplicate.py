from typing import List
from collections import Counter

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        
        # Elegant but too long as you're doing a pass for each element so is n^2
        # return [1 for number in nums if nums.count(number) >= 2] != []

        freq_count = Counter(nums)
        for key in freq_count:
            if(freq_count[key] >= 2): return True

        return False

# Super concise
    #return len(nums) != len(set(nums))


if __name__ == "__main__":
    s = Solution()
    print(s.containsDuplicate([1,2,2,3,4]))