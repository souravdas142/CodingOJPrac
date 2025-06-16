// User function Template for C++

class Solution {
  public:

    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices) {
        // write your code here
        
        for(int  i = 0;i<queries;i++) {
            int ind = indices[i];
            int cnt = 0;
            for(int j = ind+1;j<n;j++) {
                if(arr[j]>arr[ind]) {
                    cnt++;
                }
            }
            indices[i] = cnt;
        }
        
        return indices;
        
    }
};