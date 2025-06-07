/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};*/

class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
        // Write your code here
        Node* tmpHead = head;
        Node* deepCopy = new Node(0);
        Node* tmpCpy = deepCopy;
        
        unordered_map<Node*,Node*> ump;
     
        
        while(tmpHead) {
            
            tmpCpy ->next = new Node(tmpHead->data);
            ump[tmpHead] = tmpCpy->next;
            tmpCpy = tmpCpy->next;
            
            tmpHead = tmpHead->next;
        }
        
        tmpHead = head;
        tmpCpy = deepCopy->next;
        
        while(tmpHead) {
            ump[tmpHead]->random = ump[tmpHead->random];
            tmpHead = tmpHead->next;
        }
        
        return deepCopy->next;
        
    }
};