/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/


/*
    Notes:
        - BFS looks best for this (lets do this iterative with a queue).
        - Need to somehow differentiate between a node with no children null and a new level null.
        - Each level will have a number of nulls that will depend on the number of above nodes
          Note that the number of children nodes (nodes in a level) does not depend on the number of nodes on
          the level above as this is an N-ary tree so it can be any arbitrary number of nodes n.
        - Store the previous breadth count and when the number of nulls = the number of above nodes than start a new level.
        - Try to sort of get it in array form like the non-serialized input (our output will ignore the nulls). Our algo works on the input-like form.
        - Make sure to add in proper number of nulls.


    Approach:
        - Iterative BFS using a queue.
        - Count the number of nodes in the parent breadth/level and store.
        - When you reach the next level, we know the level is over when the number of nulls = number of nodes in the parent level.

    time: O(n^n)
    space: O(n^n)



    Optimise:
        - See below.
        - Very smart that as you start a new iteration of the while loop, you basically can add the whole current sized queue to the level
          and add the next level as you go. Just like whatever there is. No numbers/counts/nulls needed. You essentially take the current queue size at start of while
          and don't go further than that (as youre adding the next level on and dont want to pop it yet).

*/
class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        List<List<Integer>> ret = new LinkedList<>();

        if (root == null) return ret;

        Queue<Node> queue = new LinkedList<>();

        queue.offer(root);

        while (!queue.isEmpty()) {
            List<Integer> curLevel = new LinkedList<>();
            int len = queue.size();
            for (int i = 0; i < len; i++) {
                Node curr = queue.poll();
                curLevel.add(curr.val);
                for (Node c : curr.children)
                    queue.offer(c);
            }
            ret.add(curLevel);
        }

        return ret;
    }
}


/*
class Solution {
    public List<List<Integer>> levelOrder(Node root) {

        List<List<Integer>> result = new ArrayList<>();
        if(root == null) return result;

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);
        queue.add(null);

        int prevLevelNodeCount = 1; // Do expect 1 null for root. (then will be 1 again when we assign to number of nodes).
        int nullCount = 0;
        int thisLevelNodeCount = 0;

        List<Integer> levelElements = new ArrayList<>();

        while(queue.size() > 0) {
            Node nextNode = queue.poll();

            // null node
            if(nextNode == null) {
                ++nullCount;
                if(nullCount == prevLevelNodeCount) {
                    if(levelElements.isEmpty()) break; // To avoid the last add of an empty array.
                    result.add(levelElements);
                    levelElements = new ArrayList<>();
                    prevLevelNodeCount = thisLevelNodeCount;
                    thisLevelNodeCount = 0;
                    nullCount = 0;
                }
            }

            // Valid node
            else {

                // Add node to current level vector.
                ++thisLevelNodeCount;
                levelElements.add(nextNode.val);


                // Enqueue null if no children.
                if(nextNode.children == null) { // Note that empty list is a null in this example and not valid reference that would return true if .isEmpty() was called.
                    queue.add(null);
                }

                // or enqueue children.
                else {
                    for(Node node : nextNode.children) {
                        queue.add(node);
                    }

                    queue.add(null); // Necessary to split.
                }
            }

        }

        return result;

    }
}
*/
