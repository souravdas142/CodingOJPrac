#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Helix {

	public:
		ll solve(vector<int>& nums1, vector<int>& nums2) {

			int n1 = nums1.size();
			int n2 = nums2.size();

			int i = 0, j = 0;
			ll curi = 0, curj = 0;
			ll ans = 0;

			while(i<n1 && j<n2) {

				if(nums1[i]<nums2[j]) {
					curi += nums1[i];
					i++;
				}
				else if(nums2[j]<nums1[i]) {
					curj += nums2[j];
					j++;
				}
				else {
					curi += nums1[i];
					curj += nums2[j];
					ans+=max(curi,curj);
					curi = 0;
					curj = 0;
					i++;
					j++;
				}

			}

			while(i<n1) {

				curi += nums1[i];
				i++;
				
			}

			while(j<n2) {

				curj += nums2[j];
				j++;
			}

			ans+=max(curi,curj);


			return ans;


		}





};

int main() {

	Helix dhelix;

	while(true) {


		int n1; cin>>n1;
		if(n1==0) return 0;
		vector<int> nums1(n1);
		for(auto& e: nums1) cin>>e;

		int n2; cin>>n2;
		vector<int> nums2(n2);
		for(auto& e: nums2) cin>>e;

		ll ans = dhelix.solve(nums1, nums2);
		cout<<ans<<"\n";

	}

	return 0;
}
