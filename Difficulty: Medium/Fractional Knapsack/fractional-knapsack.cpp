// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        auto cmp = [](auto& p1, auto& p2)->bool {
            if(((double)p1.first)/((double)p1.second) < ((double)p2.first)/((double)p2.second)) {
                return true;
            }
            return false;
        };
        
        priority_queue<pair<int,int>, vector<pair<int,int> >, decltype(cmp) > pq(cmp);
        
        int n = val.size();
        for(int i = 0;i<n;i++) {
            pq.push({val[i],wt[i]});
        }
        
        double ans = 0.0f;
        
        while(capacity>0 && !pq.empty()) {
            pair<int,int> prod = pq.top();
            pq.pop();
            int need = min(capacity,prod.second);
            capacity = capacity - need;
            double intm = (((double)prod.first/(double)prod.second)*(double)need);
            //cout<<intm<<endl;
            ans+= intm;
            
        }
        
        return ans;
        
    }
};
