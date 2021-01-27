"""
    Approach 1:
        - Iterate through list to find shortest string length and use for index boundaries.
        - For i in range(0, min length in list):
            get ith char of first string 
            for(all strings):
                compare ith value to the above value:
                build stirng

        time:O(N)

    Approach 2:
        - Get max and min of the list using max() and min(). In the case of strings, these will return the lexiographical
        max and min.
        - Then iterate through these two to find difference.


"""


# Approach 1
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        
        min_str = min(strs,key=len)
        common_prefix = ""
    
        for i in range(0, min_str):
            char = strs[0][i]

            for s in strs[1:]:
                if s[i] != char:
                    return common_prefix
            common_prefix += char

        return common_prefix


# Approach 2 
class Solution:
    def longestCommonPrefix(self, m):
        if not m: return ''
				#since list of string will be sorted and retrieved min max by alphebetic order
        s1 = min(m)
        s2 = max(m)

        for i, c in enumerate(s1):
            if c != s2[i]:
                return s1[:i] #stop until hit the split index
        return s1




if __name__ == "__main__":
    s = Solution()
    print(s.longestCommonPrefix(["flower", "fligfdsg", "flow"]))