#include <bits/stdc++.h>
using namespace std;
#define newln "\n"

ostream& operator<<(ostream& print,const vector<int> vec) {
    print<<newln;
    
    for(auto& i:vec) cout<<i<<" ";

    print<<newln;
}

class Solution {
    
    public:
        
        static void makeFailureTable(const string& pattern,vector<int>& ft) {
           ft[0] = 0;
           ft[1] = 0; 
           
           int j = 0;
           int sz = pattern.length();

           for(int i  = 2;i<=sz;i++) {
               
               j = ft[i-1];
               while(true) {
                   if(pattern[j]==pattern[i-1]) {
                    ft[i] = j + 1;
                    break;
                   }
                   if(j == 0) {
                        ft[i] = 0;
                        break;
                   }
                   
                   j = ft[j];
            }

           }

        }

        static bool solve(const string& text,const string& pattern) {
            
            bool ans = false;
            
            int len = pattern.length();
            int txtSize = text.length();
            vector<int> ft(len+1);
            
            Solution::makeFailureTable(pattern,ft);
            
            cout<<__LINE__<<endl;
            
            int i  = 0,j = 0;
            bool flag = false;
            
            while(true) {
                
                

                if(text[i]==pattern[j]) {
                    i++;
                    j++;
                    if(j==len) {
                        cout<<"We have a match at pos: "<<(i-j)<<newln;
                        return true;
                    }
                }
                else {

                    if(j==0) {
                        i++;
                    }

                    if(i==txtSize) {
                        cout<<"pattern \""<<pattern<<"\" doesn't have a match"<<newln;
                        return false;
                    }

                    j = ft[j];

                }
                

            }


            

            return false;


        }




};


int main() {

    int tc = 1;
    cin>>tc;
    while(tc--) {
        
        string text, pattern;
        cin>>text>>pattern;
        
        if(Solution::solve(text,pattern)) {
            cout<<"We have a match"<<newln;
        }
        
    }
    
    return 0;


    
}