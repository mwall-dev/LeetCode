/*
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *          * };
 *           */

/*
 *	Notes:
 *	- Obvious approach is too use a hashmap.
 *	- 
 *
 *
 *
 *	Apporach 1: HashMap 
 *		- Use a freq map and store max.
 *		- Iterate through and find keys with max values.
 *
 *		time: O(N)
 *		space:O(N)
 *
 *	Approach 2: 
 *
 *
 *
 *
 *
 */

/*
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *          * };
 *           */

/*
 *	Notes:
 *	- Obvious approach is too use a hashmap.
 *	- This question is stupidly worded. They say that its allowed less than or equal to on left and
 *	greater than or equal too on right meaning that an inorder traversal wouldn't show pefectly in order.
 *	STUPID
 *
 *
 *
 *	Apporach 1: HashMap and iterative BFS
 *		- Use a freq map and store max.
 *		- Iterate through and find keys with max values.
 *
 *		time: O(N)
 *		space:O(N)
 *
 *
 *
 *
 *	Approach 2: Recursion
 *	    - LeetCode saying recursion stack space doesn't count.
 *	    - Techincally, the recursion stack accounts for space so to do this in O(1) space you need
 *	    an iterative traversal. Use Morris's traversal for this:
 *	    https://www.educative.io/edpresso/what-is-morris-traversal
 *
 *
 *	    - In order traversel gets us the tree in sorted order
 *	                        : visit left
 *	                         visit current
 *	                         visit right
 *      - Do in two traversals:
 *          First traversal you find the max_count
 *          Second traversal you find the modes with max_count.
 *
 *
 *
 *	    time: O(N)
 *	    space: O(1)
 *
 */


// Approach 2 with Recursion.
class Solution {
private:
    int curr_val;
    int curr_count = 0;
    int max_count = 0;
    std::vector<int> modes;

public:
    std::vector<int> findMode(TreeNode* root) {
        in_order(root, false);
        curr_count = 0;
        in_order(root, true);
        return modes;
    }

    void in_order(TreeNode* node, bool modes_search) {
        if(node == nullptr) return;
        in_order(node->left, modes_search);
        handle_value(node, modes_search);
        in_order(node->right, modes_search);
    }

    void handle_value(TreeNode* node, bool modes_search) {
        if (node->val != curr_val) {
            curr_val = node->val;
            curr_count = 0;
        }

        ++curr_count;
        std::cout << curr_count << '\n';

        if (curr_count > max_count) {
            max_count = curr_count;
        }

        else if (curr_count == max_count) {
            if (modes_search)
                modes.push_back(curr_val);
        }

    }
};


// Approach 1
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        std::unordered_map<int, int> freq_map;
        int max_count = 0;


        // Iterative BFS
        std::queue<TreeNode*> q;
        q.push(root);


        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            max_count = std::max(max_count, ++freq_map[current->val]);

            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);

        }
        std::vector<int> modes;

        for(auto it = freq_map.begin(); it != freq_map.end(); ++it) {
            if(it->second == max_count) {
                modes.push_back(it->first);
            }
        }

        return modes;
    }
};









	


