class Solution {
  public:
  
    void solve(int n, int left, int right, string valid,int& ans) {
        
        //cout<<valid<<endl;
        
        if(left>n/2) return;
        
        if(left+right==n) {
            if(left==right) {
                ans++;
            }
            return;
        }
        
        
        
        char ch = (valid.size())?valid.back():'a';
        
        if(ch == 'a' || ch=='('  || ch==')') {
           
            solve(n,left+1,right,valid+'(',ans);
            
        }
        
        if(left>right && ch!='a') {
          
            solve(n,left,right+1,valid+')',ans);
            
        }
    }
    
    int findWays(int n) {
        // code here
       
        string valid = "";
        int ans  = 0;
        int left = 0, right = 0;
        
        
        solve(n,left,right,valid,ans);
        
        return ans;
    }
};