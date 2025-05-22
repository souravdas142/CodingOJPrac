class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> ump;
        int i = 0,j = 0;
        int ans = 0;
        int n = fruits.size();
        while(j<n) {
            ump[fruits[j]]++;
            if(ump.size()>2) {
                ump[fruits[i]]--;
                if(ump[fruits[i]]==0) {
                    ump.erase(fruits[i]);
                }
                i++;
            }
            if(ump.size()<=2) {
                ans = max(ans,j-i+1);
            }
            j++;
        }

        return ans;
    }
};