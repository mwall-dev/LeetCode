
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
/*
    Approach : Brute Force
        Iterate through and record all values in a vector.
        Once you reach end start at start of vector and replace values

        time:O(N)
        space:O(N)

    Approach : Space Optimised
        Iterate through list and make current node point to previous node.
        (basically just changing links).

        time: O(N)
        space: O(1)


    LeetCode is bugged.


*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next_node;

        while(next_node != nullptr) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }

        return prev;
    }
};