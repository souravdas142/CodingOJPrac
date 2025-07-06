// User function template for C++

class Node {
    private:
        vector<Node*> links;
        bool word;
    public:
        Node() {
            links.resize(26,nullptr);
            word = false;
        }
        
        bool isWord() {
            return word;
        }
        
        void setWord() {
            word = true;
        }
        
        bool isContainsKey(char ch) {
            int pos = ch-'a';
            return links[pos]!=nullptr;
        }
        
        void put(char ch, Node* setter) {
            links[ch-'a'] = setter;
        }
        
        Node* getLink(char ch) {
            return links[ch-'a'];
        }
        
};

class Trie {
  private:
    Node* root;
    
  public:

    Trie() {
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node = root;
        int n = word.size();
        
        for(int i = 0;i<n;i++) {
            
            if(!node->isContainsKey(word[i])) {
                Node* link = new Node();
                node->put(word[i],link);
            }
            node = node->getLink(word[i]);
        }
        node->setWord();
    }

    bool search(string &word) {
        // search word in the Trie
         Node* node = root;
         int n = word.size();
         
         for(int i = 0;i<n;i++) {
             if(!node->isContainsKey(word[i])) {
                 return false;
                 
             }
             node = node->getLink(word[i]);
             
         }
         return node->isWord();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
         Node* node = root;
         int n = word.size();
         
         for(int i = 0;i<n;i++) {
             if(!node->isContainsKey(word[i])) {
                 return false;
                 
             }
             node = node->getLink(word[i]);
             
        }
        return true;
    }
};
