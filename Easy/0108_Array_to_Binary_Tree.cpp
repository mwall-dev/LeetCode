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
    Apporach 1: Start from middle element.
    Some sort of recursive function for building the Tree, takes a parent and val argument and returns new child Node connected to parent.
    Maybe do left side of array and then right.
    Two loops. Pass through root as first one.
    
    Improvement:
    We are just making lines.
    Need to make more balanced. Start is good.
    ALways put middle element in and do for right and left side.
    
    You might think you're skipping elements by always jumping to middle of new subarray 
    but this is not the case as further recursion calls will go in other direction yoou've jumped from.



*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
                
        TreeNode* root = build_tree(nums, 0, nums.size() - 1);
       
        return root;
        
    }
    
    TreeNode* build_tree(const vector<int>& nums, int low, int high) {
        if(low > high) return nullptr;
        
        int middle = (high + low) / 2;
        
        TreeNode* node = new TreeNode(nums[middle]);
        
        node->left = build_tree(nums, low, middle - 1);
        node->right = build_tree(nums, middle + 1, high);
        
        return node;
    }
};