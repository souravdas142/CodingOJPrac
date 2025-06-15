class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        int dotCnt = 0;
        int slashCnt = 0;
        int i = 1, j = 1;
        int n = path.size();
        stack<string> st;
        string ans = "/";

        while(j<n) {
            if(path[j]=='.') {
                dotCnt++;
            
            }
            if(path[j]=='/') {
                if(dotCnt==2 && (j-i)==2 ) {
                    if(!st.empty())
                        st.pop();
                }
                else if(i<j) {
                    if(!(dotCnt==1 && (j-i)==1)) {
                        string tmp = string(path.begin()+i,path.begin()+j);
                    //cout<<tmp<<endl;
                        st.push(string(tmp));
                    }
                }
                i = j+1;
                dotCnt = 0;
            }

            j++;

        }
        if(st.empty()) return ans;
        vector<string> dummy;
        while(!st.empty()) {
            dummy.push_back(st.top());
            st.pop();
        }

        int k = dummy.size();
        
        for(int i = k-1; i>0;i--) {
            ans+=dummy[i]+'/';
        }
        ans+=dummy[0]; 
        return ans;
        
    }
};