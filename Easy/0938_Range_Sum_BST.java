/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */


/*
    Notes:
        - If root is in range then we know that all left are < high and all right are >low so we just need to check for the low and high.
        - If root is not in range then we need to move left or right depending on low and high.
        - DFS is good.
        - Can do like a brute force on all nodes and just exit if we get something out of range though this condiiton might be hard to find.

    Approach : Sort of Brute Force.
        - DFS and just check if node in [low, high].


    Appraoch : Optimised
        - If node.val <= low,
        then dont go left. Recall BST
        is strict so if you go left than right a million times
        you still get a node greater than the root (also unique vals
        only so need to).




*/
// Optimised.
class Solution {
    private int solution = 0;
    public void helperDFS(TreeNode root, int low, int high) {
        if(root == null) return;


        if(root.val == low || root.val == high) {
            solution += root.val;
        }


        else if(root.val > low && root.val < high) {
            solution += root.val;
            helperDFS(root.left, low, high);
            helperDFS(root.right, low, high);
            return;
        }


        // If too low, ignore left subtree.
        if(root.val <= low) {
            helperDFS(root.right, low, high);
            return;
        }

        // If too high, ignore right subree.
        if(root.val >= high) {
            helperDFS(root.left, low, high);
            return;
        }
    }


    public int rangeSumBST(TreeNode root, int low, int high) {
        helperDFS(root, low, high);
        return solution;

    }
}

/* // MORE CONCISE.
public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) return 0;
        if (root.val <= L) return rangeSumBST(root.right, L, R) + (root.val == L ? root.val : 0);
        if (root.val >= R) return rangeSumBST(root.left, L, R) + (root.val == R ? root.val : 0);
        return rangeSumBST(root.left, L, R) + root.val + rangeSumBST(root.right, L, R);
    } */