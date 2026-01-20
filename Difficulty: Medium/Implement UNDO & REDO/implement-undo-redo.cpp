class Solution {
  public:
    string store = "";
    string ans = "";
    void append(char x) {
        // append x into document
        ans+=x;
    }

    void undo() {
        // undo last change
        store+=ans.back();
        ans.pop_back();
    }

    void redo() {
        // redo changes
        ans+=store.back();
        store.pop_back();
    }

    string read() {
        // read the document
        return ans;
    }
};