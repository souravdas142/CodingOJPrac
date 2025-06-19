
class Node {
    public:

        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k,int v):key(k),val(v),prev(nullptr),next(nullptr) {}

};

class LRUCache {
    int cap;
    int cnt;
    unordered_map<int,Node*> ump;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) {

        cap = capacity;
        cnt = 0;
        head = new Node(-1,-1);
        tail = new Node (-1,-1);

        head->next = tail;
        tail->prev = head;

    }

    int get(int key) {

        if(ump.count(key)) {
            delink(ump[key]);
            add2head(ump[key]);

            return ump[key]->val;

        }
        return -1;

    }

    void put(int key, int value) {

        if(ump.count(key)) {

            ump[key]->val = value;
            /// TODO:
            /// delik the node and add to the front
            delink(ump[key]);
            add2head(ump[key]);

        }
        else {

            if(cnt<cap) {

                Node *cnd = new Node(key,value);
                add2head(cnd);
                ump[key] = cnd;
                cnt++;

            } else {
                Node *d = tail->prev;
                ump.erase(d->key);
                d->key = key;
                d->val = value;
                ump[key] = d;
                delink(d);
                add2head(d);
            }





        }

    }

    void add2head(Node* nd) {
        if(nd->prev==head) return;
        nd->next = head->next;
        nd->prev = head;
        (head->next)->prev = nd;
        head->next = nd;
    }

    void delink(Node* nd) {
        if(nd->prev == head) {
            return;
        }
        (nd->prev)->next = nd->next;
        (nd->next)->prev = nd->prev;
        nd->next = nullptr;
        nd->prev = nullptr;
    }


};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
