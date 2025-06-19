
class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;
        
        Node(int key,int val) {
            Node::key = key;
            Node::val = val;
            prev = nullptr;
            next = nullptr;
        }
    
};


class LRUCache {
  private:
    unordered_map<int,Node*> ump;
    int cap;
    Node* head, *tail;
    int size;
  public:
    LRUCache(int cap) {
        // code here
        LRUCache::cap = cap;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        head->prev = nullptr;
        tail->prev = head;
        tail->next = nullptr;
        size = 0;
    }
    
    void swap(Node* cur) {
      
     
        (cur->prev)->next = cur->next;
        (cur->next)->prev = cur->prev;
            
        cur->next = head->next;
        cur->prev = head;
        (head->next)->prev = cur;
        head->next = cur;
        
        
        
    }

    int get(int key) {
        
        int ans = -1;

        if(ump.find(key)!=ump.end()) {
            ans =  (ump[key]->val);
            /// TODO: WILL FURTHER PROCESS
            Node* cur = ump[key];
           
            swap(cur);
            
            
            
        }
        
        return ans;
        
        // code here
    }
    
    void addNode(Node* newNode) {
        newNode->prev = head;
        newNode->next = head->next;
        (head->next)->prev = newNode;
        head->next = newNode;
        ump[newNode->key] = newNode;
    }
    
    void update(int key, int value ) {
        Node* cur = tail->prev;
        
        ump.erase(cur->key);
        
        
        cur->key = key;
        cur->val = value;
        
        ump[key] = cur;
        
        swap(cur);
        
    }
        
    void put(int key, int value) {
        // code here
        if(ump.find(key)!=ump.end()) { // cache hit
            ump[key]->val = value;
            swap(ump[key]);
        }
        else {
            if(size<cap) { // if there is cache miss and still we have capacity
                size++;
                Node* newNode = new Node(key,value);
                addNode(newNode);
            }
            else {
                update(key,value); // we are reusing tail to update
            }
        }
        
        
    }
};