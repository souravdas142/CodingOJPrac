/*
class Node{
    int data;
    Node left, right;
    Node(int d){
        data=d;
        left=right=null;
    }
}
*/

class Solution {
    public boolean isIdentical(Node r1, Node r2) {
        // code here
        if(r1==null || r2==null) {
            if(r1==r2) return true;
            return false;
        }
        if(r1.data!=r2.data) return false;
        if(isIdentical(r1.left,r2.left)==false) return false;
        if(isIdentical(r1.right,r2.right)==false) return false;
        return true;
    }
}