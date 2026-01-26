#define vi vector<int>
#define vvi vector<vi>

class Solution {
  public:
  
    void solve(vi& arr, int n, int index,vvi& ans) {
        
        if(index>=n) {
            //ans.push_back(imans);
            ans.push_back(arr);
            return;
        }
        
        
        
        for(int i = index;i<n;i++) {
            
            swap(arr[index],arr[i]);
            solve(arr,n,index+1,ans);
            swap(arr[index],arr[i]);
            

        }
        
    }
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        vvi ans;
        int n = arr.size();
        int index = 0;
        
        solve(arr,n,index,ans);
        
        return ans;
    }
};