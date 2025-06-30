class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
      
        
        int n = start.size();
          vector<pair<int,int> > vpi(n);
        for(int i= 0;i<n;i++) {
            vpi[i] = {start[i],end[i]};
        }
        sort(vpi.begin(),vpi.end(),[](auto& p1, auto& p2)->bool{
           return p1.second<p2.second; 
        });
        
        // for(auto& pr: vpi) {
        //     cout<<"{"<<pr.first<<","<<pr.second<<"} ";
        // }
        
        int ans = 1;
        int lastJob = vpi[0].second;
        for(int i =1;i<n;i++) {
            if(lastJob<vpi[i].first) {
                ans++;
                lastJob = vpi[i].second;
            }
            
        }
        
        return ans;
    }
};