class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
       int sz = difficulty.size();
       vector<pair<int,int> > difprof(sz);
       for(int i = 0;i<sz;i++) {
            difprof[i]={difficulty[i],profit[i]};
       } 

       sort(difprof.begin(),difprof.end());
       sort(worker.begin(),worker.end());

       int ans = 0;
       int mx = 0;
       int wsz = worker.size();

       for(int i = 0;i<wsz;i++) {

            for(int j = 0;j<sz;j++) {
                if(worker[i]>=difprof[j].first) {
                    mx = max(mx,difprof[j].second);
                }


            }

            //cout<<"Worker[i] = "<<worker[i]<<" , profit = "<<mx<<endl;
            ans+=mx;

       }

       return ans;

    }
};