class Solution {

    int check(int a, int b) {
        int ans  = 0;

        string astr = to_string(a), bstr = to_string(b);

        int astrlen = astr.length(), bstrlen = bstr.length();

        int maxlen = max(astrlen,bstrlen);

        while(astrlen!=maxlen) {
            astr = '0'+astr; astrlen++;
        }
        while(bstrlen!=maxlen) {
            bstr = '0'+bstr; bstrlen++;
        }

        int diff = 0;
        unordered_map<char,int> mp1,mp2;
        for(int i = 0;i<maxlen;i++) {

            if(astr[i]!=bstr[i]) diff++;
            mp1[astr[i]]++;
            mp2[bstr[i]]++;
        }

        return (diff<=2 && mp1==mp2); 

    }
public:
    int countPairs(vector<int>& nums) {

        int sz = nums.size();
        int ans = 0;
        for(int i = 0;i<sz;i++) {
            for(int j = i+1;j<sz;j++) {
                ans+=check(nums[i],nums[j]);
            }
        }

        return ans;
        
    }
};