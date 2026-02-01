class Solution {
  public:
    void print(vector<int>& arr) {
        for(auto& e: arr) {
            cout<<e<<" ";
        }
        cout<<endl;
    }
    void rearrangeQueue(queue<int> &q) {
        
        
        int n = q.size();
        queue<int> a,b;
        for(int i = 1;i<=n;i++) {
            if(i*2<=n) {
                a.push(q.front());
            }
            else {
                b.push(q.front());
            }
            q.pop();

        }
        
        int i = 1;
        
        while(i*2<=n) {
            q.push(a.front());
            a.pop();
            q.push(b.front());
            b.pop();
            i++;
        }
        
    }
};