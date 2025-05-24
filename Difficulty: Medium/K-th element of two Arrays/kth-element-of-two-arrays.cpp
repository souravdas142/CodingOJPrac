class Solution {
  public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        // code here
        int i = 0;
        int j = 0;
        int cnt = 0;
        int cur = 0;
        while(i<a.size() && j<b.size()) {
            if(a[i]<=b[j]) {
                cur=a[i];
                i++;
            }    
            else {
                cur = b[j];
                j++;
            }
            cnt++;
            if(cnt == k) {
                return cur;
            }
        }
        while(i<a.size()) {
            cur = a[i];
            i++;
            cnt++;
            if(cnt == k) return cur;
        }
        while(j<b.size()) {
            cur = b[j];
            j++;
            cnt++;
            if(cnt==k) return cur;
        }
        return cur;
     }
};