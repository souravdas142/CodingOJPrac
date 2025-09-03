class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int,int> ump;
        int j = 0;
        int cnt = 0;
        int xored = 0;
        while(j<n) {
            xored ^= arr[j];
            if(xored==k) {
                cnt++;
            }
            int need = xored^k;
            if(ump.find(need)!=ump.end()) {
                cnt+=ump[need];
            }
            ump[xored]++;
            j++;
            
        }
        return cnt;
    }
};