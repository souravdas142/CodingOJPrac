class Solution {
  public:
    int buyMaximumProducts(int n, int k, int price[]) {
        // Write your code here
        vector<pair<int,int>> vpi;
        for(int i = 0;i<n;i++) {
            vpi.push_back({i+1,price[i]});
        }
        
        sort(vpi.begin(),vpi.end(),[](auto& p1, auto& p2)->bool {
            // double x1 = ((double)p1.first)/((double)p1.second);
            // double x2 = ((double)p2.first)/((double)p2.second);
            // // if(x1==x2) {
            // //     return p1.first>=p2.first;
            // // }
            // return x1>x2;
            if(p1.second==p2.second) {
                return p1.first<p2.first;
            }
            return p1.second<p2.second;
        });
        int ans = 0;
        for(int i = 0;i<n;i++) {
            int maxProd = k/vpi[i].second;
            int actualProd = min(vpi[i].first,maxProd);
            ans+=actualProd;
            k = k-(actualProd*vpi[i].second);
        }
        
        return ans;
        
    }
};
