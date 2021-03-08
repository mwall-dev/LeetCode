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
        Notes: 
        - Upon delete, a nodes children then become new roots.
        - Need to use uniqueness of values.
        - Store deleted values in a set.
        - If we add a new root and later need to delete, need to delete from result.
        
        
        Turn to_delete into a set.
        BFS whole tree.
        Chekc if any node is in to_delete.
        If it is then check children.
        If children are in to_delete, then dont add to root vector, else, add to root vector.
        Dont delete from tree as we may need to traverse down.
         std::vector<TreeNode*> res;
        
        std::unordered_set<int> deletes(to_delete.begin(), to_delete.end());
        auto it_end = deletes.end();
        
        
        std::queue<TreeNode*> q;
        
        q.push(root);
        
        if(deletes.find(root->val) == it_end) res.push_back(root);
        
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            
            bool need_to_delete = deletes.find(current->val) != it_end;
            
            if(current->left) {
                q.push(current->left);
                if(need_to_delete && deletes.find(current->left->val) == it_end) {
                    res.push_back(current->left);   
                }
            }
            
            if(current->right) {
                q.push(current->right);
                if(need_to_delete && deletes.find(current->right->val) == it_end) {
                    res.push_back(current->right);   
                }
            }      
            
        }
        
        return res;
    
    }
        
        Inital approach above doesnt work.
        
        Need to actually delete nodes themselves. So we need pointers to be able to edit the parents pointers.
        
        Need to try again with DFS.
        
        
        
*/

std::vector<TreeNode*> res; // Classic global for result in DFS recursion.

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        res.clear();
        std::unordered_set<int> deletes(to_delete.begin(), to_delete.end());
        
        helper(root, deletes, true);
        
        return res;
    
    }
    
    TreeNode* helper(TreeNode* node, const std::unordered_set<int>& deletes, bool is_root) {
        if(node == nullptr) return nullptr;
        
        bool need_to_delete = deletes.find(node->val) != deletes.end();
        if (is_root && !need_to_delete) res.push_back(node);
        
        node->left = helper(node->left, deletes, need_to_delete);
        node->right =  helper(node->right, deletes, need_to_delete);
        
        return need_to_delete ? nullptr : node; // Will change tree so that delete nodes.

    }
};