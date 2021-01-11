class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        digit = s[0]
        count = 0
        count_opp = 0
        res = 0
        found_opposite = False 
        next_start = -1
        i = 0 
        
        while i < len(s):
            if s[i] == digit: 
                if not found_opposite:
                    count += 1
                else:
                    res += min(count, count_opp)
                    digit = s[next_start]
                    i = next_start - 1 # Minus 1 as will increment at bottom
                    count = 0
                    count_opp = 0
                    found_opposite = False

            
            else:
                if not found_opposite:
                    found_opposite = True
                    next_start = i
                    count_opp += 1
                else:
                    count_opp += 1
                    
            i += 1
                    
        
        
        res += min(count, count_opp)
        

        return res


        
# Solution overview:
# Basically, for any substring with 1's grouped consecutively and 0's grouped consecutively,
# the number of valid substrings is the min of the two. e.g. 0001111 has 3 consecutive 0's and
# 4 consecutive 1's so the answer is min(3,4) = 3 = ("01", "0011", "000111")

# I did a simple linear scan over all the characters, counting the consecutive 0's and 1's grouped together
# also making sure to record the next starting index. 
# e.g 00110011, I would count 0011, 1100, 0011 all as 2 + 2 + 2 = 6.

# Note the elegant solution:
#def countBinarySubstrings(self, s):
        #s = map(len, s.replace('01', '0 1').replace('10', '1 0').split())
        #return sum(min(a, b) for a, b in zip(s, s[1:]))

# This basically counts the number of consecutive 0's OR 1's grouped together
# e.g. 0110001111 = [1,2,3,4] (different to mine that counted the change and kept going).
# Then it basically used a similar rule to mine, where you look at min, in this case you just 
# have to look at min of the two numbers e.g. min(1,2) + min(2,3) + min(3,4) = 1 + 2 + 3 = 6

# this puts spaces in and splits and counts length.


# Notes: Initially did a for i in range(0,len(s)) and would change i in loop to backtrack to starting index
# but this doesn't work in python! The range creates a strict iterable and as soon as i is reassigned 
# manually, it breaks the loop basically. So we had to use a while loop.










if __name__ == "__main__":
    s = Solution()
    print(s.countBinarySubstrings("00110011"))


