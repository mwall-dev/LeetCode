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
        Recusrive DFS
        Have function parameters in rcursive function that store a max/min range.
        
        






*/
bool res;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        res = true;
        helper(root, LONG_MIN, LONG_MAX);
        return res;
    }
    
    
    void helper(TreeNode* node, long min, long max) {
        
        if(node == nullptr) return;
        
        if(node->val >= max || node->val <= min) {
            res = false;
            return;
        }
        
        helper(node->left, min, node->val);
        helper(node->right, node->val, max);
    }
};
