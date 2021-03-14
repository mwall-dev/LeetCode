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
    Some sort of traversal. Order doesnt really matter as is not a BST. 
    Make it recursive and just have a targetSum parameter for function.

    Slightly slow, need to stop once its found true.

*/

bool res;

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        res = false;
        helper(root, targetSum);
        return res;
    }
    
    
    void helper(TreeNode* node, int target_sum) {
        if(!node) return;
        target_sum -= node->val;
        
        if(target_sum == 0) {
            if(!node->left && !node->right) {
                res = true; 
                return;
            } 
        }
        
        helper(node->left, target_sum);
        helper(node->right, target_sum);
        
    }
};
