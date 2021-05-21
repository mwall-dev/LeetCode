/*
 *
 *  Notes:
 *      - Looking for longest path.
 *      - Picturing this as a graph it would be directed as edges are one way. Challenge here.
 *      - Looks like it has something to do with height.
 *      - From a node, the deepest height of the left and right subtrees represents the longest path that goes
 *      through this node.
 *      - Can't assume root will be in path.
 *      - Could be one of the very low down nodes that has massive left and right subtrees.
 *
 *
 *
 *  Approach: Brute Force:
 *      - Start at root.
 *      - For left and right children, we do a recursive traversal down to leaf node and return max depth for each side.
 *      - Compare with current_max.
 *      - Move down and do again for left and right children.
 *
 *      - The calculate_depth function is really smart.
 *
 *
 *  Approach: Optimised
 *      - The code is actually very similar to our brute force.
 *      - We instead just continually check if we have reached a max diameter using the left and right depths currently.
 *      - The recursive function takes us through the whole tree anyway.
 *      - This is very hard to see. Do it on paper and see how it looks at the subtress below first and propogates answers up.
 *
 *
 *
 *
 */


// Optimised
class Solution {
public:
    int max_diameter = 0;

    int calculate_depth(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }

        int left_depth = calculate_depth(node->left);
        int right_depth = calculate_depth(node->right);

        if(left_depth + right_depth > max_diameter) max_diameter = left_depth + right_depth;

        return std::max(left_depth + 1, right_depth + 1);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        calculate_depth(root);

        return max_diameter;
    }
};


/*
// Brute Force
class Solution {
public:

    int calculate_depth(TreeNode* node) {
        if(node == nullptr) {
            return 0;
        }

       int left_depth = calculate_depth(node->left);
       int right_depth = calculate_depth(node->right);

       if(left_depth > right_depth) {
           return left_depth + 1;
       }
       else {
           return right_depth + 1;
       }

    }

    int diameterOfBinaryTree(TreeNode* root) {

        int max_diameter = 0;
        std::queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* current_node = q.front();
            q.pop();
            int left_depth = 0;
            if(current_node->left != nullptr) {
                left_depth = calculate_depth(current_node->left);
                q.push(current_node->left);
            }

            int right_depth = 0;
            if(current_node->right != nullptr) {
                right_depth = calculate_depth(current_node->right);
                q.push(current_node->right);
            }

            max_diameter = std::max(max_diameter, left_depth + right_depth);

        }

        return max_diameter;
    }
};

 */