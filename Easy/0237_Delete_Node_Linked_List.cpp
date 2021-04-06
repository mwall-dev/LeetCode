/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */



/*
    Notes:
        Not given head of list so can't just work our way down and link over it to delete.
    
    
    Approach:
        Start at node to be deleted.
        Set its value to the value of next.
        Repeat.
        When you reach second last node then make sure to delete the node infront.
        
        If node to be deleted is last node than can't do anything (but the q says its guraanteed to not be a last node).
        
        
        Disgusting one-liner
        *node = *(node->next);
        
        Basically just moves whole bit of memory (val and next) into this node (so it keeps its links).
        Literally O(1) and one operation.
        
*/


class Solution {
    public:
    void deleteNode(ListNode* node) {
        *node = *(node->next);
    }
};


/*
class Solution {
public:
    void deleteNode(ListNode* node) {      
        while(node->next->next != NULL) {
            node->val = node->next->val;
            node = node->next;
        }
        
        node->val = node->next->val;
        node->next = NULL;
        
    }
};
*/
