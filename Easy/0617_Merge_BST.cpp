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



    Notes:
       - Do in place and use one tree to store the results.
       - Note that if one tree reaches nullptr but the other keeps going then
       all you have to do is put the other trees next node there and stop as it will bring over all that is
       under it too if there is any more.



    Approach : Recursive
        - Base cases: if either are nullptr then return the others subtree from there (see above note).
        - Else add together values and keep recursing down tree.

    Approach : Iterative
        - Bit harder to see at first. Use a stack and build tree on root1 again.

 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) {
            return root2;
        }


        if(root2 == nullptr) {
            return root1;
        }

        root1->val += root2->val;

        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};