/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
class Solution {
  public:
    bool areMirror(Node* a, Node* b) {
        // Your code here
        if(a==nullptr || b==nullptr) {
            if(a==nullptr && b==nullptr) return true;
            return false;
        }
        if(a->data !=b->data) return false;
        
        if(areMirror(a->left,b->right)==false) return false;
        if(areMirror(a->right,b->left) == false) return false;
        return true;
    }
};