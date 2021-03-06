/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
    Approach:
        Essentially just need the values.
        Could do a simple in-order traversal and just put vals in a vector. 
        Then basically is building a linked list.
        To save space could do this as we go so we don't have to store all the vals.
        
        inorder-traverse:
        if(node!=null)
            inorder(node.left) 
            visit current node
            inorder(node.right)   
            
        
        Doing in order is hard recursivley unless we use globals.
        
        Could use a stack.
        
        time:O(n) where n = number of nodes.
        space:O(1)
        
        
    
        
    
    
        

*/

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        // For traversing old tree
        stack<TreeNode *> s;
        TreeNode *curr = root;
        
        // New tree build
        TreeNode* head = new TreeNode(0);
        TreeNode* current_add = head;
        
        while (curr != nullptr || s.empty() == false) {
            
            // Keep going left until you reach nullptr.
            while (curr !=  nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            // Current must be nullptr at this point.
            curr = s.top();
            s.pop();

            // Build node into tree.
            TreeNode* new_node = new TreeNode(curr->val);
            current_add->right = new_node;
            current_add = current_add->right;

            // Visit right subtree.
            curr = curr->right;

        } 
        
        return head->right;
    }
    
};