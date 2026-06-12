/*
class Node {
    int data;
    Node left, right;
    Node(int item){
        data = item;
        left = right = null;
    }
}
*/
class Solution {
    public ArrayList<Integer> inOrder(Node root) {
        // code here
        Deque<Node> st = new ArrayDeque<>();
    
        List<Integer> arr = new ArrayList<>();
        Node cur = root;
        
        while(true) {
            
            if(cur!=null) {
                st.push(cur);
                cur = cur.left;
            }
            else {
                Node temp = st.poll();
                arr.add(temp.data);
                
                cur = temp.right;
                if(cur!=null) {
                    st.push(cur);
                    cur = cur.left;
                }
               
                
            }
            if(st.isEmpty()==true) break;
        }
        return (ArrayList<Integer>)arr;
    }
}