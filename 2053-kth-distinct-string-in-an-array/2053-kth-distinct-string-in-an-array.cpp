class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> ump;
        for(string& s:arr) {
            ump[s]++;
        }
        for(string& s:arr) {

            if(ump[s]==1) {
                k--;
                if(k==0) {
                    return s;
                }
            }
            
        }
        return "";
    }

};