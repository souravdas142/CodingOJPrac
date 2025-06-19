class StockSpanner {
    int  cnt;
    stack<pair<int,int> > st;
public:
    StockSpanner() {
        ios_base::sync_with_stdio(false); cin.tie(nullptr);
        cnt = -1;
    }
    
    int next(int price) {

        cnt++;
        int ele = price;
        int ans = 1;
        while(!st.empty() && st.top().first<=ele) {
            st.pop();
        }
        if(st.empty()) {
            ans =  cnt+1;
        } else {
            ans  = cnt-st.top().second;
        }
        st.push({ele,cnt});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */