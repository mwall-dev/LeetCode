
"""
    Approach 1: Brute switch
        - Straightforward

    Apporach 2: Pythonic though seems like a lot of string searches initially for the 
                replaces. See LeetCode answer. Basically replace all 4 and 9 cases with IIII or 9 I's
                then just iterate though and use a dict for values.

                





"""

class Solution:
    def romanToInt(self, s: str) -> int:
        res = 0
        index = 0
        while index < len(s):
            char = s[index]
            
            if char == 'I': 
                if index == len(s) - 1:
                    res += 1  
                elif s[index + 1] == 'X':
                    res += 9
                    index += 1
                elif s[index + 1] == 'V':
                    res += 4
                    index += 1
                else:
                    res += 1
            
            elif char == 'X': 
                if index == len(s) - 1:
                    res += 10  
                elif s[index + 1] == 'L':
                    res += 40
                    index += 1
                elif s[index + 1] == 'C':
                    res += 90
                    index += 1
                else:
                    res += 10
                    
            elif char == 'C': 
                if index == len(s) - 1:
                    res += 100 
                elif s[index + 1] == 'D':
                    res += 400
                    index += 1
                elif s[index + 1] == 'M':
                    res += 900
                    index += 1
                else:
                    res += 100
            
            elif char == 'V': res += 5
            elif char == 'L': res += 50
            elif char == 'D': res += 500
            elif char == 'M': res += 1000
                
        
            index += 1
        
        return res