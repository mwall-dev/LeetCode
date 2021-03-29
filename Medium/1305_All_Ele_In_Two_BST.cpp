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
        - In order traverse each and make vectors. 
        - Sort vectors with two pointers and a new vector.
        
    Optimise:
        Could optimise memory by doing some sort of parralell in order traversal but this 
        would require iterative in order and that just sucks.
        
        Bad we use globals.
       
       Optimsed below:
       Very good solution, Note that std::excahnge is just s.psuh(n) and n = n->left.
       
       This one uses two stacks and pushes all lefts on initially.
       Then while loop handles rights and middle for each level. Visualise in head.
       
     void pushLeft(stack<TreeNode*> &s, TreeNode* n) {
    while (n != nullptr) 
        s.push(exchange(n, n->left));
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> res;
    stack<TreeNode*> s1, s2;
    pushLeft(s1, root1);
    pushLeft(s2, root2);
    while (!s1.empty() || !s2.empty()) {
        stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 : 
            s1.top()->val < s2.top()->val ? s1 : s2;
        auto n = s.top(); s.pop();
        res.push_back(n->val);
        pushLeft(s, n->right);
    }
    return res;
}   

*/

std::vector<int> tree1;
std::vector<int> tree2;


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        tree1.clear(); tree2.clear();
        
        in_order(root1, tree1);
        in_order(root2, tree2);

        int p1 = 0;
        int p2 = 0;
        std::vector<int> res;
        
        while(p1 < tree1.size() && p2 < tree2.size()) {
            if(tree1[p1] < tree2[p2]) res.push_back(tree1[p1++]);
            else res.push_back(tree2[p2++]);
        }
        
        
        while(p1 < tree1.size()) {
            res.push_back(tree1[p1++]);
        }
        
         while(p2 < tree2.size()) {
            res.push_back(tree2[p2++]);
        }
        
        return res;
      
    }
    
    void in_order(TreeNode* node, std::vector<int>& vec) {
        if(node == nullptr) return;
        
        in_order(node->left, vec);
        vec.push_back(node->val);
        in_order(node->right, vec);
        
    }
};
