// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int row = arr.size();
        int col = arr[0].size();
        int r = -1;
        int maxi = INT_MIN;
        for(int i = 0;i<row;i++) {
            int sum = 0;
            for(int j = 0;j<col;j++) {
                sum += arr[i][j];
            }
            if(sum>maxi) {
                maxi = sum;
                r = i;
            }
            
        }
        return r;
    }
};