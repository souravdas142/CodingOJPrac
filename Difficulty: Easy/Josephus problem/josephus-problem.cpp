class Solution {
  public:
    int josephus(int n, int k) {
        // code here
        deque<int> dq;
        
        for(int i = 1;i<=n;i++) dq.push_back(i);
        int cnt = 0;
        
        while(dq.size()!=1) {
            int x = dq.front();
            dq.pop_front();
            cnt++;
            
            if(cnt<k)
                dq.push_back(x);
            else cnt = 0;
        }
        
        return dq.front();
    }
};