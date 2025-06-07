/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

void printNext(Node* root) {
    cout<<endl<<"PrintNext"<<endl;
    int buffer =5;
    int i = 0;
    while(root!=nullptr) {
        cout<<root->data<<" ";
        root = root->next;
        i++;
        if(i>buffer) {
            cout<<endl;
            i=0;
        }
    }
    cout<<endl;
}

void printBottom(Node* nd) {
    cout<<endl<<"printBottom "<<endl;
    while(nd!=nullptr) {
        cout<<nd->data<<" ";
        nd = nd->bottom;
    }
    cout<<endl;
}

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    
    
    
    Node* merge(Node* root,Node* remNodes) {
        if(remNodes == nullptr) return root->bottom;
        else if(root->bottom==nullptr) {
            root->bottom = remNodes;
            return root->bottom;
        }
        
        Node* node1 = root->bottom, *node2 = remNodes;
        
        Node* build_down = new Node(0);
        Node* head = build_down;
        
        while(node1!=nullptr && node2!=nullptr) {
            if(node1->data <= node2->data) {
                build_down->bottom = node1;
                
                node1 = node1->bottom;
            }
            else {
                build_down->bottom = node2;
                node2 = node2->bottom;
            }
            build_down = build_down->bottom;
        }
        
        if(node2!=nullptr) build_down->bottom = node2;
        else if(node1!=nullptr)  build_down->bottom = node1;
        root->bottom = head->bottom;
        return root->bottom;
    }
    Node* solve(Node* prevRoot, Node* root, Node* remNodes,int i) {
        
        if(root==nullptr) {
            return root;
        }
        Node* nextRoot = root->next;
        //printBottom(root);
        remNodes = merge(root,remNodes);
        //printBottom(root);
        
        
        
        Node* build = new Node(0);
        Node* head = build;
        
        Node* down = root->bottom;
        Node* prev = root;
        int nextRootData = (nextRoot==nullptr)?INT_MAX:nextRoot->data;
        
        while(down!=nullptr) {
            
            if(down->data > nextRootData) {
               
                break;
            }
            
            build->next = down;
            build = build->next;
        
            prev = down;
            down = down->bottom;
        }
        
        build->bottom = nullptr;
      
        
        build->next = nextRoot;
        
        if(head->next)
            root->next = head->next;
            
        remNodes = down;
        //if(i>2) return;
        
        
        solve(root,nextRoot,remNodes,i+1);
        //printNext(prevRoot);
        //cout<<"final = "<<i<<endl;
        //printNext(root);
        return root;
        
    }
    
    void buildBottom(Node* root) {
        Node* tmp = root;
        Node* down = root;
        while(tmp) {
            down->bottom = tmp->next;
            down = down->bottom;
            tmp = tmp->next;
        }
    }        
    
    Node* flatten(Node *root) {
        // Your code here
        Node* remNodes = nullptr;
        Node* prevRoot = nullptr;
        int i = 0;
        Node* ans =  solve(prevRoot,root,remNodes,i);
        buildBottom(ans);
        return ans;
        cout<<"fall"<<endl;
        return ans;
        
    }
};