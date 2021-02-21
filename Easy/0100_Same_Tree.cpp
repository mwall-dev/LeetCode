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
        In parallel BFS.




*/

// Iterative solution
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;

        q1.push(p);
        q2.push(q);

        while(!q1.empty() && !q2.empty()) {
            TreeNode *node1 = q1.front();
            q1.pop();
            TreeNode *node2 = q2.front();
            q2.pop();

            if(!node1 && !node2) continue;
            if(!node1 || !node2) return false;

            if (node1->val != node2->val) return false;

            if (node1) {
                q1.push(node1->left);
                q1.push(node1->right);
            }
            if (node2) {
                q2.push(node2->left);
                q2.push(node2->right);
            }



        }

        return q1.empty() && q2.empty();
    }
};

// Recursive
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;


        if(p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else return false;
    }
};
