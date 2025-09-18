class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        int vote = 1;
        int voter = arr[0];
        int ans = 0;
        int j = 1;
      
        while(j<n) {
            
            if(voter==arr[j]) {
                vote++;
                
            }
            else {
                vote--;
                if(vote==0) {
                    voter = arr[j];
                    vote++;
                }
            }
            
            
            j++;
            
        }
        
        int cnt = 0;
        
        for(int i = 0;i<n;i++) {
            if(voter == arr[i]) cnt++;
        }
        
        if(cnt>n/2) return voter;
        
        return -1;
       
    }
};