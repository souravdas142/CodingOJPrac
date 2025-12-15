#include <bits/stdc++.h>
using namespace std;

class Cow {

	public:

		bool letsCheck(vector<int>& stalls, int stall, int cow, int mid) {


			int prev = stalls[0];
			int i = 1;
			cow = cow-1;

			while(i<stall && cow) {

				if(prev+mid <= stalls[i]) {
					cow--;
					prev = stalls[i];
				}

				i++;

				if(cow > (stall-i)) {

					return false;

				}
				

			}

			if(cow == 0) {
				return true;
			}

			return false;


		}

		int solveaggresiveCow(vector<int>& stalls, int stall, int cow) {

			int mini = INT_MAX;
			int maxi = INT_MIN;

			for(auto& e: stalls) {
				mini = min(mini,e);
				maxi = max(maxi,e);
			}

			int low = 1;
			int high = maxi - mini;

			sort(stalls.begin(),stalls.end());

			while(low<=high) {
				int mid = low+(high-low)/2;

				if(letsCheck(stalls,stall,cow,mid)) {
					low = mid+1;
				}
				else {
					high = mid-1;
				}

			}

			return high;


		}

		void solve() {
			int tc = 1;
			cin>>tc;
			while(tc--) {

				int stall, cow;
				cin>>stall>>cow;
				vector<int> stalls(stall,0);
				for(auto& e : stalls) cin>>e;

				int ans = solveaggresiveCow(stalls,stall,cow);
				cout<<ans<<endl;
			}

		}

};


int main() {

	Cow montu;
	montu.solve();
	return 0;
}
