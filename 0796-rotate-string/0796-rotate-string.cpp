class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();
        if(n!=m) return false;

        int i = 0, j = n-1;

        set<char> st1, st2;

        while(i<n && j>=0) {
            string s1 = string(s.begin()+i,s.end());
            string s2 = string(goal.begin(),goal.begin()+j+1);
            cout<<s1<<endl<<s2<<endl;
            if(s1==s2) {
                
                if(st1!=st2) return false;
                return true;
            }
            st1.insert(s[i]);
            st2.insert(goal[j]);
            i++;
            j--;
        }
        return false;

    }
};