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
    
    if(i>j) swap(i,j);

    Node* prev_i = nodes[i-1];
    Node* cur_i = nodes[i];
    Node* prev_j = nodes[j-1];
    Node* cur_j = nodes[j];
    
    if(i+1==j) { // handle adjacent nodes
        prev_i->next = cur_j;
        cur_i->next = cur_j->next;
        cur_j->next = cur_i;
        
    }
    else {
        Node* tmp =cur_j->next;
        prev_i->next = cur_j;
        cur_j->next = cur_i->next;
        prev_j->next = cur_i;
        cur_i->next = tmp;
    }
    
    swap(nodes[i],nodes[j]);
    
}

  
    Node* segregate(Node* head) {
        // code here
        /*
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
        */
        
        Node* zero = new Node(0);
        Node* zeroi = zero;
        Node* one = new Node(1);
        Node* onei = one;
        Node* two = new Node(2);
        Node* twoi = two;
        
        Node* iter = head;
        
        while(iter!=nullptr) {
            if(iter->data==0) {
                zeroi->next = iter;
                zeroi=zeroi->next;
            }
            else if(iter->data==1) {
                onei->next = iter;
                onei=onei->next;
            }
            else if(iter->data==2) {
                twoi->next = iter;
                twoi = twoi->next;
            }
            iter=iter->next;
        }
        
        twoi->next = nullptr;
        onei->next = two->next;
        zeroi->next = one->next;
        
        
        
        return zero->next;
        
        
        
        
        
        
    }
};