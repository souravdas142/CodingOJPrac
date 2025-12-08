class Solution {
public:
    int reverseb(int num) {
        int ans = 0;
  
        while(num) {
            ans = ((ans<<1) |(num&1));
            //cout<<bitset<32>(ans)<<endl;
            num = num>>1;
          
        }
        //cout<<ans<<endl;
        return ans;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int,int>> vpi;
        for(auto& e:nums) {
            int num = reverseb(e);
            vpi.push_back({num,e});

        }
        sort(vpi.begin(),vpi.end(),[](auto& a, auto& b)->bool{
            if(a.first==b.first) {
                return a.second<b.second;
            }
            return a.first<b.first;
        });
        vector<int> ans;
        for(auto& e:vpi) {
            ans.push_back(e.second);
        }
        return ans;
    }
};