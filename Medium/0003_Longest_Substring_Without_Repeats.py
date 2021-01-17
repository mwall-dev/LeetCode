

"""
    Approach 1:
        - Iterate through the string.
        - For each index, start there. 
        - Make a new set and iterate through rest of string adding elements to set
        - If you come across an item in set, record length and go to next starting point.

        time: O(N^2)
        space:O(N) as making a new set each iteration.
    

    Apporach 2:
        - Iterate through the string using a while loop so you can change the index.
        - Similar to earlier, for each index start there (may skip some though)
        - Make a new HashMap this time as (num : index) and record chars and length until you 
        reach one that exists in map already. 
        - Compare the length to max_len and now use hashmap to get first index of that 
        duplicate char and start your next fresh search from that index + 1.
        We can do this as if we start from that index we're going to get a smaller string anyway.
        As it was after our point we just started from and it will run into the same problem.

        time:O(N^2) but faster
        space: O(N)


    Approach 3 (DP):
        - Create a list to store max length ending at that index,
        and a map to store chars and indicies.
        - Iterate through string and record lengths in list and (num : index) pairs in map.
        - When you reach a duplicate, you look to map to get index of that char. 
        - You then use that index on list to get the max_len at that index, and you subtract
        this from the current length to get the max length at this duplicate char.
        - Also, make sure to record the earliest occurence of the duplicate so that you know 
        what map entry indices to ignore (ones before it).
        - You then keep iterating, but make sure to ignore map entries that have indicies,
        earlier than your starting point.

        time:O(N)
        space:O(N)

        REVISION
        - No need to keep track of length. Just used differences in indicies if found duplicate, OR [index below] + 1 if 
        continuing.
"""

""" Approach 3 """
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        


        # Edge cases
        if s.isspace() or len(s) == 1:
            return 1
        if not s:
            return 0

        
        max_length_at_index = [1] # At the zeroeth index, the max length of the substring ending here is 1.

        chars_found = {s[0] : 0 }
        max_length = 0
        starting_point = 0

        for index, char in enumerate(s):
            if index == 0:
                continue

            if char in chars_found:
                # If it is past starting point it means we have found a duplicate.
                if chars_found[char] >= starting_point:
                    starting_point = chars_found[char]
                    max_length_at_index.append(index - starting_point)
                    chars_found[char] = index
                    continue

            max_length_at_index.append(max_length_at_index[index-1] + 1)
            chars_found[char] = index

        return max(max_length_at_index)





""" Approach 1 """
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s.isspace() or len(s) == 1:
            return 1
       
        max_len = 0
        length = 0
        for index, char in enumerate(s):
            length = 1
            chars_found = set()
            chars_found.add(char)

            for j in range(index + 1, len(s)):
                if s[j] not in chars_found:
                    length += 1
                    chars_found.add(s[j])
                else:
                    break
            
            max_len = max(max_len, length)


        return max_len


""" Approach 2 """
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        index = 0
        
        while(index < len(s)):
            length = 1
            chars_found = {}
            chars_found[s[index]] = index

            for j in range(index + 1, len(s)):

                if s[j] not in chars_found:
                    length += 1
                    chars_found[s[j]] = j
                else:
                    index = chars_found[s[j]] # Set to the first occurrence of the duplicate.
                                              # This will increment due to while loop.
                    break
            
            index += 1
            max_len = max(max_len, length)

            # No point continuing if there aren't enough chars left to beat it.
            if(len(s) - index < max_len):
                break

        return max_len


if __name__ == "__main__":
    s = Solution()
    print(s.lengthOfLongestSubstring("aaabcdbadbeeef"))