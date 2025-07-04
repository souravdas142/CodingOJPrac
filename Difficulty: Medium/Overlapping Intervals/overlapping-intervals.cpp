class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        sort(arr.begin(),arr.end(),[](auto& a, auto& b)->bool{
           return a[0]<b[0];
           
        });
        
        // for(auto& ve: arr) {
        //     cout<<ve[0]<<" "<<ve[1]<<endl;
        // }
        
        int n = arr.size();
        int j = 1;
        vector<vector<int> > ans;
        int ending = arr[0][1];
        int starting  = arr[0][0];
        
        while(j<n) {
           if(arr[j][0]<=ending) {
               ending = max(ending,arr[j][1]);
           } 
           else {
               ans.push_back({starting,ending});
               starting = arr[j][0];
               ending = arr[j][1];
           }
           j++;
        }
        
        ans.push_back({starting,ending});
        
        return ans;
        
        
    }
};