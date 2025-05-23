

class Solution {
  public:
    long long countSubArrayProductLessThanK(const vector<int>& arr, int n,long long k) {
        //int n = arr.size();
        int i = 0;
        int j = 0;
        unsigned long long prod = 1;
        unsigned long long cnt = 0;
        while(j<n) {
            prod = prod*arr[j];
            while(prod>=k && i<=j) {
               
                prod = prod/arr[i];
                i++;
            }
            if(prod<k) {
                cnt+=(j-i+1);
            }
            j++;
            
        }
        return cnt;
        
    }
};