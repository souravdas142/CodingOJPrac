class Solution {
public:
    int longestSubstring(string s, int k) {

        unordered_map<char,int> ump;

        for(auto ch: s) ump[ch]++;

        int total_uniq_char = ump.size();
        int n = s.size();
        int ans = 0;
        

        for(int nth_uniq_char = 1;nth_uniq_char<=total_uniq_char;nth_uniq_char++) {

            ump.clear();

            int i = 0, j= 0;

            int uniq_chars = 0;
            int fulfilled_uniq_char_count = 0;

            while(j<n) {

               

                    if(ump.find(s[j])==ump.end()) {
                        uniq_chars++;
                    }
                    ump[s[j]]++;

                    if(ump[s[j]]==k) {
                        fulfilled_uniq_char_count++;
                    }

                    if(uniq_chars == nth_uniq_char && fulfilled_uniq_char_count==nth_uniq_char) {
                        ans = max(ans,j-i+1);
                    }

                    

                
                if (uniq_chars > nth_uniq_char) {

                    if(ump[s[i]]==k) {
                       fulfilled_uniq_char_count--; 
                    }
                    ump[s[i]]--;

                    if(ump[s[i]]==0) {
                        uniq_chars--;
                        ump.erase(s[i]);
                    }
                    i++;
                    
                }

                j++;
                    
            }

        }

        return ans;
        
    }
};