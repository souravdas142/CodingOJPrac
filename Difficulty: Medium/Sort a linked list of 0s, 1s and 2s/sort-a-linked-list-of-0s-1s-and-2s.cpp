/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    
    int length(Node* head,vector<Node*>& nodes) {
        if(head==nullptr) return 0;
        nodes.push_back(head);
        return 1+length(head->next,nodes);
    }
    
   void swapNodes(int i, int j, vector<Node*>& nodes) {
    if (i == j) return;

    if (i > j) swap(i, j); // ensure i < j for consistency

    Node* prev_i = nodes[i - 1];
    Node* node_i = nodes[i];
    Node* prev_j = nodes[j - 1];
    Node* node_j = nodes[j];

    if (j == i + 1) {
        // Adjacent nodes
        prev_i->next = node_j;
        node_i->next = node_j->next;
        node_j->next = node_i;
    } else {
        Node* temp = node_j->next;

        prev_i->next = node_j;
        node_j->next = node_i->next;

        prev_j->next = node_i;
        node_i->next = temp;
    }

    swap(nodes[i], nodes[j]);
}

  
    Node* segregate(Node* head) {
        // code here
        
        Node* dummy = new Node(0);
        dummy->next = head;
        vector<Node*> nodes;
        
        int n = length(dummy,nodes)-1;
        int left = 1;
        int mid = 1;
        int high = n;
        
        while(mid<=high) {
            if(nodes[mid]->data==0) {
                
                swapNodes(left,mid,nodes);
                
                left++; mid++;
            }
            else if(nodes[mid]->data ==1 ) {
                mid++;
            }
            else if(nodes[mid]->data==2) {
                swapNodes(high,mid,nodes);
                high--;
            }
        }
        
        return nodes[0]->next;
        
    }
};