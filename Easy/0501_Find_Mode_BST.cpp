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

// Approach 1
class Solution {
	public:
		vector<int> findMode(TreeNode* root) {
			std::unordered_map<int, int> freq_map;
			int max_count = 0;
			// Iterative BFS
			std::queue<TreeNode*> q;

			while(!q.empty()) {
				TreeNode* = q.front();
				q.pop();
				max_count = std::max(max_count, ++freq_map[q->val]);

				if(q->left) q.push(q->left);
				if(q->right) q.push(q->right);

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



	


