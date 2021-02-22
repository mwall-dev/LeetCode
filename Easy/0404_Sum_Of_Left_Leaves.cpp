

/*
 * Approach: DFS to leaves but record if you came from a left or right (extra bool arg in recursive function)
 *
 *
 *
 *
 *
 *
 */





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
class Solution {

public:
    int sum = 0;

    int sumOfLeftLeaves(TreeNode* root) {

    }
    // Left = true, Right = False.
    void sum_dfs(TreeNode* node, bool direction) {
        if(node == nullptr) return;
        if(node->left == nullptr && node->right == nullptr) {
            if(direction) {
                sum += node->val;
            }
        }
        else {
            sum_dfs(node->left, true);
            sum_dfs(node->right, false);
        }
    }
};


// More concise
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root, bool is_left=false) {
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) {
            return is_left ? root->val : 0;
        }
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};
