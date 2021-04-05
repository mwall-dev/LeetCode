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
    Notes: 
        - DFS seems appropirate.
        - Do it recusrivley and have a string parameter that we can pass down when we 
        take different paths.
    Approach: DFS
        



*/

std::vector<string> res;
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        helper(root, "");
        return res;
    }
    
    void helper(TreeNode* node, std::string path_str) {
        
        path_str.append(std::to_string(node->val) + "->");
        
        if(!node->left && !node->right) {
            path_str.pop_back();
            path_str.pop_back();
            res.push_back(path_str);
            return;
        }
        if(node->left) helper(node->left, path_str);

        if(node->right) helper(node->right, path_str);
 
    }
};
