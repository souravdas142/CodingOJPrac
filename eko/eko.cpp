#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Eko {

	public:
		bool checkPossible(int m, vector<int>& heights, int mid) {


			int n = heights.size();
			int i = 0;
			ll totalm = 0;

			while(i<n) {

				if(heights[i]>mid) {
					totalm += (heights[i]-mid);
				}
				else {
					break;
				}

				if(totalm>=m) return true;
				i++;

			}

			return false;
		}

		ll solve(int m, vector<int>& heights) {


			ll ans = 0;
			int n = heights.size();
			sort(heights.begin(), heights.end(),greater<int>());

			int low = 0;
			int high = heights[0];

			while(low<=high) {
				int mid = low+(high-low)/2;

				if(checkPossible(m,heights,mid)) {
					ans = mid;
					low = mid+1;
				}
				else {
					high = mid-1;
				}
			}


			return ans;
		}

};

int main() {

	Eko eko;

	int tc = 1;
//	cin>>tc;
	while(tc--) {

		int n; cin>>n;
		int m; cin>>m;
		
		vector<int> heights(n);
		for(auto& e: heights) cin>>e;

		ll ans = eko.solve(m,heights);
		cout<<ans<<"\n";
		

	}
	return 0;
}
