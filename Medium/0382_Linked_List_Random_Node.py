from typing import List
import random
import math




""" 
    Approach 1:
        - On __init__, we iterate through linked list until end and build a 
        list of the values for fast random access.

        - Use python random library to generate a uniform index number 
        between 0 and len(list) - 1 each time getRandom is called.
    


    Follow up question: what is list is extremely large and its length is unknown to you. 
    Also no using extra space.

    Approach 1:
        - Iterate through list once to get length.
        - Generate random number as you did last time.
        - Go down the list this many times and return the value.
        time: O(N)
        space: O(1)

    Approach 2:
        - Generate a random number between 0 and 10^4.
        - Iterate through list this many times and if you reach end, go to the top and keep going.
        - Return value of node you end up on
    time: O(1) as max number will be 10^4
    space: O(1)


"""


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:

    def __init__(self, head: ListNode):
        self.head = head
        

    def getRandom(self) -> int:
        """ Returns a random node's value. """
        node = self.head
        index = random.uniform(0, 10000)

        # Check just incase it actually did get the last value.
        index = math.floor(index)
        if index == len(self.values): return self.getRandom()


        while(index > 0):
            if not node.next:
                node = self.head

            else:
                node = node.next

            index -= 1


        return node.val


        


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()






if __name__ == "__main__":
    s = Solution()
    print(s.partitionLabels("aaabcdbadbeeef"))