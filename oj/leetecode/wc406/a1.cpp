#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define newln "\n"
#define CODE_PATH  "/home/sourav/Documents/code/"
#define INPUT_FILE CODE_PATH"input.txt"
#define OUTPUT_FILE CODE_PATH"output.txt"
#define ERR_FILE CODE_PATH"err.txt"
#define fixed(n) fixed << setprecision(n)
#define ull unsigned long long
#define ll long long
#define dd double
#define pii pair<int, int>
#define pll pair<long, long>
#define vi vector<int>
#define vl vector<long>
#define vll vector<ll>
#define vvi vector<vi >
#define vvl vector<vl >
#define vvll vector<vll >
#define vpii vector<pii >
#define vpll vector<pll >
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define frr(i,a,b) for(ll i=a-1;i>=b;i--)
#define tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define sz(a) (ll)((a).size())
#define pb push_back
#define emb emplace_back
#define emp emplace
#define all(x) (x).begin(), (x).end() //Forward traversal
#define rall(x) (x).rbegin, (x).rend() //reverse traversal
#define max(a, b) (a < b ? b : a) 
#define min(a, b) ((a > b) ? b : a) 
#define debug(x) cout<<newln<< #x <<" = "<<x<<endl;
#define debug2(x,y) cout<<newln<< #x <<" = "<<x<<", "<< #y <<" = "<<y<<endl;
#define mod (1e9 + 7)
#define PI 3.1415926535897932384626433832795

template<typename t>
ostream& operator<<(ostream& print,const vector<t> vec) {
    print<<newln<<"{";
    for(auto ele:vec) print<<ele<<", ";
    print<<"} "<<newln;
    return print;
}



// --------------

//{ Driver Code Starts


// } Driver Code Ends
class Solution{
    

    string add(string a,string b) {
        string ans;
        int alen = a.length();
        int blen = b.length();
        
        int carry = 0;
        
        int i = alen-1,j=blen-1;
        while(i>=0 && j>=0) {
            int num1 = a[i]-'0';
            int num2 = b[j]-'0';
            int num3 = num1+num2+carry;
            carry = num3/10;
            char c = '0'+(num3%10);
            ans.insert(0,1,c);
            
            
            i--;j--;
            
        }
        while(i>=0) {
            int num1 = a[i]-'0';
            int num2 = num1+carry;
            char c = '0'+(num2%10);
            ans.insert(0,1,c);
            carry = num2/10;
            i--;
        }
        while(j>=0) {
            int num1 = b[j]-'0';
            int num2 = num1+carry;
            char c = '0'+(num2%10);
            ans.insert(0,1,c);
            carry = num2/10;
            j--;
        }
        
        if(carry>0) {
            char c = '0'+carry;
            ans.insert(0,1,c);
        }
        
        
        return ans;
    }
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       //Your code here
       string sign = "";
       if(s1[0]=='-') {
         sign+="-";
         s1.erase(0,1);
       }
       if(s2[0]=='-') {
         sign+="-";
         s2.erase(0,1);
       }
       
       if(sign.length()==2) sign="";
       
       if(s2[0]=='-') sign+="-";
       //cout<<sign<<" "<<sign[0]<<endl;
       int s1len = s1.length();
       int s2len = s2.length();
       string ans;
       
       int i = s1len-1, j = s2len-1,carry = 0;
       int cnt = 0;
       while(j>=0) {
           int num2 = s2[j]-'0';
           string res="";
           i = s1len-1;
           while(i>=0) {
               int num1 = s1[i]-'0';
               int x = (num1*num2)+carry;
               carry = x/10;
               char c = '0'+(x%10);
               res.insert(0,1,c);
               i--;
               
               
           }
           char cc = '0'+carry;
           if(carry>0) res.insert(0,1,cc);
           if(cnt>0) {
                res+=string(cnt,'0');
                //cout<<"Result = "<<res<<endl;
                ans = add(ans,res);
           }
           else {
            ans = res;
           }
           carry = 0;
           j--;
           cnt++;
       }
       
        while(ans[0]=='0') ans.erase(0,1);
       if(ans.empty()) ans="0";
       else ans.insert(0,1,sign[0]);
       return ans;
       
    }

};

//{ Driver Code Starts.
 
int main() {
     
    fio;

    #ifndef ONLINE_JUDGE  
        freopen(INPUT_FILE, "r", stdin); 
        //freopen(ERR_FILE, "w", stderr); 
        //freopen(OUTPUT_FILE, "w", stdout); 
    #endif 
    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;
       // cout<<a<<" * "<<b<<endl;
    	Solution obj;
    	cout<<obj.multiplyStrings(a,b)<<endl;
    }
     
}
// } Driver Code Ends

//-------------


