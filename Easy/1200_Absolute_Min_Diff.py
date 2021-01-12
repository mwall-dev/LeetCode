from typing import List

class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        # 1. Sort array 
        # 2. Linear search through once to find the min difference comparing adjacent elements
        # 3. A second linear search finding all adjacent elements with the min diff
        # O(nlogn) due to sort

        # Surely some smart list comprehension one liner for step 3.

    
        # Edge cases
        if len(arr) < 2:
            return []

        if len(arr) == 2:
            return [[arr[0],arr[1]]]


        
        arr.sort()
        # Set a first value. Could make INT_MAX but python 3 ints are infinite.
        min_diff = abs(arr[0] - arr[1])

        for index in range(0, len(arr) - 1):
            min_diff = min(min_diff, abs(arr[index] - arr[index + 1]))

        res = []

        for index in range(0, len(arr) - 1):
            if (abs(arr[index] - arr[index + 1]) == min_diff):
                res.append([arr[index], arr[index + 1]])


        return res


# Concise version:
    #def minimumAbsDifference(self, a: List[int]) -> List[List[int]]:
        #a.sort()
        #diff = min(a[i] - a[i - 1] for i in range(1, len(a)))
        #return [[a[i - 1], a[i]] for i in range(1, len(a)) if a[i] - a[i - 1] == diff]
    

if __name__ == "__main__":
    s = Solution()
    print(s.minimumAbsDifference([4,2,1,3]))

       