// User function template for C++


class Node {
    public:
        vector<Node*> nodes;
        bool isWordExistSoFar;
        Node() {
            nodes.resize(26,nullptr);
            isWordExistSoFar = false;
        }
};

class Trie {
  public:
    Node *trie;
    Trie() {
        // implement Trie
        trie = new Node();
    }
    void insertInTrie(string word,int index, int n, Node* head) {
        
        if(index>=n) {
            head->isWordExistSoFar = true;
            return;
        }
        
        int pos = word[index]-'a';
        if(head->nodes[pos]==nullptr) {
            head->nodes[pos] = new Node();
        }
        
        insertInTrie(word,index+1,n,head->nodes[pos]);
        
    }
    
    void insert(string &word) {
        // insert word into Trie
        Node* head = trie;
        int index = 0;
        int n = word.size();
        insertInTrie(word,index,n,head);
    }
    
    bool searchInTrie(string word,int index, int n,Node* head) {
        if(index>=n) {
            if(head->isWordExistSoFar==true) return true;
            return false;
        }
        int pos = word[index]-'a';
        if(head->nodes[pos]==nullptr) return false;
        
        
        
        return searchInTrie(word, index+1,n, head->nodes[pos]);
    }
    
    bool search(string &word) {
        // search word in the Trie
        Node* head = trie;
        int index = 0;
        int n = word.size();
        return searchInTrie(word,index,n,head);
    }
    
    bool isPrefixInTrie(string word,int index,int n, Node* head) {
        if(index>=n) {
            return true;
        }
        int pos = word[index]-'a';
        if(head->nodes[pos]==nullptr) return false;
        
        
       
        return isPrefixInTrie(word,index+1,n, head->nodes[pos]);
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* head = trie;
        int index = 0;
        int n = word.size();
        return isPrefixInTrie(word,index,n,head);
    }
};
