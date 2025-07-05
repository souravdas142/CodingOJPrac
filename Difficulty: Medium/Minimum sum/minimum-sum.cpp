class Solution {
  public:
    string add(string& a, string& b) {
        //cout<<a<<endl<<b<<endl;
        if(a.size()==0 && b.size()==0) return "0";
        if(a.size()==0) return b;
        if(b.size()==0) return a;
        
        int n = a.size();
        int m = b.size();
        string ans(max(n,m)+2,'.');
        int k = ans.size();
        int u = n-1, d = m-1;
        int j = k-1;
        int carry = 0;
        while(u>=0 && d>=0) {
            int sum = (a[u]-'0')+(b[d]-'0')+carry;
            carry = sum/10;
            sum = sum%10;
            ans[j] = ('0'+sum);
            j--;
            u--;
            d--;
        }
        while(u>=0) {
            int sum = (a[u]-'0')+carry;
            carry = sum/10;
            sum = sum%10;
            ans[j] = '0'+sum;
            u--;j--;
        }
        while(d>=0) {
            int sum = (b[d]-'0')+carry;
            carry = sum/10;
            sum = sum%10;
            ans[j] = '0'+sum;
            d--;j--;
        }
        if(carry) {
            ans[j] = '0'+carry;
            j--;
        }
        
        return string(ans.begin()+j+1,ans.end());
    }
    string minSum(vector<int> &arr) {
        // code here
        
        priority_queue<int, vector<int>,greater<int> > pq;
        
        for(auto e: arr) pq.push(e);
        int i = 0;
        vector<string> num(2,"");
        while(!pq.empty()) {
            if(num[i].size()==0 && pq.top()!=0)
                num[i] += ('0'+pq.top());
            else if(num[i].size()>0)
                num[i] += ('0'+pq.top());
            pq.pop();
            i++;
            i = i%2;
            
        }
        
        string ans = "";
        ans = add(num[0],num[1]);
        return ans;
        
    }
};