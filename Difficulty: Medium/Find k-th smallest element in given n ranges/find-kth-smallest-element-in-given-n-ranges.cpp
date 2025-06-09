// User function Template for C++
#define vvi vector<vector<int> >
#define vi vector<int>

class Solution {
  public:
  
    int mergeRange(vvi& range,int k) {
        
        int i = 1;
        
        int n = range.size();
        
        int rangeLeft = range[0][0];
        int rangeRight = range[0][1];
        int curLeft = -1;
        int curRight = -1;
        int cnt = rangeRight-rangeLeft+1;
        
       
        
        while(i<n && cnt<k) {
            
            curLeft = range[i][0];
            curRight = range[i][1];
            
            if(curLeft <= rangeRight) {
                
                if(curRight>rangeRight) {
                    
                    cnt+=(curRight-rangeRight);
                    rangeRight = curRight;
                    if(cnt>=k) break;
                    
                }
                
            }
            else {
                
                
                
                rangeLeft = curLeft;
                rangeRight = curRight;
                
                cnt+=(rangeRight-rangeLeft+1);
                if(cnt>=k) break;
                
            }
            
            
            i++;
        }
        
        int ans = ((rangeRight+(k-cnt)) > rangeRight)?-1:rangeRight+(k-cnt);
        return ans;
        
        
    }
    
    vi kthSmallestNum(int n, vvi& range, int q,vi queries) {
        // Write your code here
        
        sort(range.begin(),range.end());
        vector<int> ans(q,-1);
        
        for(int i = 0;i<q;i++) {
        
            ans[i] = mergeRange(range,queries[i]);
            
        }
        return ans;
        
        
    }
};
