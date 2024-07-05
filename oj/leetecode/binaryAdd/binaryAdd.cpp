#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define newln "\n"
#define debug(x) cout<<newln<<#x<<" = "<<x<<newln

class Solution {

	public:
		Solution() {}

		string  addBinary(string a,string b) {

			int asz = a.length();
			int bsz = b.length();
			int i = asz-1,j = bsz-1;

			string result;


			int carry = 0;

			while(i>-1 && j>-1) {

				int tmp = (a[i]-'0')+(b[j]-'0')+carry;
				if(tmp==3) {
					result.insert(result.begin(),'1');
					carry = 1;
				}else if(tmp==2) {
					result.insert(result.begin(),'0');
					carry=1;
				}
				else if(tmp==1) {
					result.insert(result.begin(),'1');
					carry = 0;
				}else {
					result.insert(result.begin(),'0');
					carry = 0;
				}
				i--;j--;
			}
			while(i>=0) {
				debug(i);
				int tmp = (a[i]-'0')+carry;

				if(tmp==2) {
					result.insert(result.begin(),'0');
					carry=1;
				}
				else if(tmp==1) {
					result.insert(result.begin(),'1');
					carry = 0;
				}else {
					result.insert(result.begin(),'0');
					carry = 0;
				}
				i--;
			}
			while(j>=0) {
				debug(j);
				int tmp = (b[j]-'0')+carry;

				if(tmp==2) {
					result.insert(result.begin(),'0');
					carry=1;
				}
				else if(tmp==1) {
					result.insert(result.begin(),'1');
					carry = 0;
				}else {
					result.insert(result.begin(),'0');
					carry = 0;
				}
				j--;
			}
			if(carry) 
				result.insert(result.begin(),'1');





			return result;
		}



};


int main() {

	Solution solve;
	ll tc=1;
	cin>>tc;
	while(tc--) {
		string s1,s2; cin>>s1>>s2;

		string result = solve.addBinary(s1,s2);
		cout<<newln<<result<<newln;
	}
	



	return 0;

}
