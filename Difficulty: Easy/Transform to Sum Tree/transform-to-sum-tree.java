/* Structure for Tree Node
class Node {
    int data;
    Node left, right;

    // Constructor
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
};
*/
class Solution {
    
    private int solve(Node root) {
        if(root==null) return 0;
        int left = solve(root.left);
        int right = solve(root.right);
        int sum = left+right;
        int temp = root.data;
        root.data = sum;
        return sum+temp;
    }
    
    public void toSumTree(Node root) {
        // code here
        int ans = solve(root);
        //System.out.println(ans);
    }
}