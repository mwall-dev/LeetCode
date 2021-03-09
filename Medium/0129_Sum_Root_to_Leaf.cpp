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
    Approach: DFS
    - Start from root and have a recursive function with a paratmer than holds a string of numbers.
    - Use a global for adding
    
*/


int sum = 0;

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        helper(root, "");
        return sum;
    }
    
    void helper(TreeNode* node, std::string str_num) {
        if(!node->left && !node->right) {
            sum += std::stoi(str_num + std::to_string(node->val));
            return;
        }
        if(node->right) helper(node->right, str_num + std::to_string(node->val));
        if(node->left) helper(node->left, str_num + std::to_string(node->val));
    }
    
    
};