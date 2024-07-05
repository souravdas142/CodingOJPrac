#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    Solution() {}
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";
        int vecSize = strs.size();
        if(vecSize==1) return strs[0];
        
        pair<int,pair<int,string> > pr={0,{0,""}};
        pair<int,string> pris={0,""};
        int keepConttrack_i = 0;
        int keepConttrack = 0;
        for(int i = 0;i<vecSize;i++) {
            

            string str1 = strs[i];
            int str1sz = str1.size();
            int ind = 0;
            int parentind = 0;

            for(int j = i+1;j<vecSize;j++) {
                string str2=strs[j];
                int str2sz = str2.size();
                int minij = min(str1sz,str2sz);
                
                if(str1[0]!=str2[0]) {
                    
                    if(keepConttrack>keepConttrack_i && ind!=0) {
                        pr.first = keepConttrack;
                        pr.second = {parentind,str1};
                    }

                    keepConttrack = 0;
                    parentind = 0;
                    continue;
                }
                else{
                    keepConttrack++;
                    cout<<" j = "<<j<<"keepContrack = "<<keepConttrack<<endl;
                    ind = 0;
                    for(int k = 0;k<minij;k++) {
                        if(str1[k]==str2[k]) ind++;
                        else 
                            break;
                    }
                    parentind = ind;
                }
                
            }
            
                if(keepConttrack>keepConttrack_i && ind!=0) {
                    pr.first = keepConttrack;
                    pr.second = {parentind,str1};
                }

                keepConttrack = 0;
                parentind = 0;
                keepConttrack_i = 0;
            
            //break;



        }



        pris = pr.second;
        string s(pris.second.begin(),pris.second.begin()+pris.first);
        result = s;

        return result;
        
    }



};

int main() {
    Solution solve;
    //vector<string> strs={"flower","flow","flight"};
    vector<string> strs={"car","cir"};
    string s = solve.longestCommonPrefix(strs);
    cout<<s<<endl;
    return 0;

}