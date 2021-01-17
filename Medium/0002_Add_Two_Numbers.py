# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next



"""
    Approach 1:
        - Recursively build each number using a string and appending with a final int() conversion at end.
        - Add numbers
        - Convert to string
        - Build linked list using string.
        time: O(N)
        space: O(N)


    Approach 2:
        - Stay in linked list format.
        - Iterate through the lists in parallel.
        - For each pair of nodes, add the node values together and put into a newly created node in a new list.
        - Note that if the value is greater than 9, you put a 0 as the value and carry a 1 for next iteration.
        - Also if you're left with a carry one at end and no more nodes to iterate over, you must make one new node 
        output 
        - If lists are different lengths and one runs out, be sure to handle the carry one 
        and then if there are no more carries (if the node wasnt a 9) then can just iterate through rest of list
        and copy to result as we are not adding anymore since other list has run out.  

        time: O(N) but this will be faster.
        space: O(N) for output.


    Note:
        For these linked list questions we have to make the first node and then ignore it at end.
        Sort of there to start to the chain so we can attach further nodes. We don't put a val
        in it.
"""
def recurse_list(linked_list):
    if not linked_list:
        return ""

    return recurse_list(linked_list.next) + str(linked_list.val)


""" Approach 1 """
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        result = str( int(recurse_list(l1)) + int(recurse_list(l2)) )

        sum_result_list = ListNode()
        head = sum_result_list

        for char in result[::-1]:
            num = int(char)
            sum_result_list.next = ListNode(num)
            sum_result_list = sum_result_list.next

        return head.next


""" Approach 2 """
def addTwoNumbers(self, l1, l2):
    carry = 0
    root = n = ListNode(0)

    while l1 or l2 or carry:
        v1 = v2 = 0
        if l1:
            v1 = l1.val
            l1 = l1.next
        if l2:
            v2 = l2.val
            l2 = l2.next
        carry, val = divmod(v1+v2+carry, 10)
        n.next = ListNode(val)
        n = n.next
    return root.next
            
    
            

            
            

            

            


