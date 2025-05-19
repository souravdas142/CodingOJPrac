//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function template for C++
#define ull unsigned long long 
class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int i = 0;
        string num1 = "";
        string num2 = "";
        string ans = "";
        
        while(i<n) {
            
            
            //num1=(to_string(arr[i]))+num1;
            //num1.insert(0,to_string(arr[i]));
            num1+=(to_string(arr[i]));
            //cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
            //cout<<"arr["<<i<<"+1] = "<<arr[i+1]<<endl;
            if((i+1)<n) {
                //num2 = (to_string(arr[i+1]))+num2;
                //num2.insert(0,to_string(arr[i+1]));
                num2+=to_string(arr[i+1]);
            }
            i+=2;
        }
        //cout<<num1<<endl;
        //cout<<num2<<endl;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        
        int c = 0;
        int n1 = num1.size();
        int n2 = num2.size();
        i = 0;
        int j = 0;
        while(i<n1 && j<n2) {
            int sum = (num1[i]-'0')+(num2[j]-'0')+c;
            c = sum/10;
            sum = sum%10;
            ans+=to_string(sum);
            
            i++;j++;
            
        }
        
        while(i<n1) {
            int sum = (num1[i]-'0')+c;
            c = sum/10;
            sum = sum%10;
            ans+=to_string(sum);
            
            i++;
        }
        
        while(j<n2) {
            int sum = (num2[j]-'0')+c;
            c = sum/10;
            sum = sum%10;
            ans+=to_string(sum);
            j++;
        }
        
        if(c) {
            ans+=to_string(c);
        }
        //cout<<ans<<endl;
        int sz = ans.size()-1;
        while(sz>=0) {
            if(ans[sz]-'0'!=0) break;
            ans.pop_back();
            sz--;
        }
        
        reverse(ans.begin(),ans.end());
        
        
        
        
        // 5 3 0 7 4
        // 0 3 4 5 7
        // 0 4 7
        // 3 5
        
        return ans;
        
        
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends