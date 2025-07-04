class Solution {
public:
    string reorganizeString(string s) {


        unordered_map<char,int> mp;

        for(auto ch:s) mp[ch]++;

        auto cmp = [] (auto& pr1, auto& pr2) {
            return pr1.second < pr2.second;
        };

        priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(cmp)> pq(cmp);

        for(auto e:mp) {
            pq.push(e);
        }

        //cout<<pq.top().first<<endl;

        int n = s.size();

        if(pq.top().second > (n+1)/2) return "";

        int cnt = 1;

        int i = 0;

        while(!pq.empty()) {

            pair<char,int> cand = pq.top();
            pq.pop();
            
            while(i<n) {
                s[i] = cand.first;
                cand.second--;
                i+=2;
                if(cand.second==0) break;
            }
            if(i>=n) {
                i = 1;
            }
        }

        return s;
        
    }
};