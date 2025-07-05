// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
    int checkHeap(Node* tree) {
        if(tree==nullptr) return 0;
        int left = checkHeap(tree->left);
        if(left == -1) return -1;
        int right = checkHeap(tree->right);
        if(right == -1) return -1;
        
        if(left>tree->data || right>tree->data) {
            //cout<<left<<" "<<right<<" "<<tree->data<<endl;
            return -1;
        }
        return tree->data;
        
    }
    bool checkCBT(Node* tree) {
        if(tree == nullptr) return true;
        queue<Node*> que;
        que.push(tree);
        bool child = true;
        while(!que.empty()) {
            Node* parent = que.front();
            que.pop();
            
            if(parent!=nullptr) {
                if(child == false) return false;
                que.push(parent->left);
                que.push(parent->right);
            }
            else {
                child = false;
            }
        }
        return true;
    }
    bool isHeap(Node* tree) {
        // code here
        int first = checkHeap(tree);
        //cout<<first<<endl;
        int sec = checkCBT(tree);
        //cout<<sec<<endl;
        if(first!=-1 && sec==true) return true;
        return false;
        
    }
};