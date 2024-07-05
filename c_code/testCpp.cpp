#include <iostream>
using namespace std;

void passArray(int *arr) {
	for(int i = 0;i<3;i++) {

		for (int j = 0;j<4;j++) {
			cout<<arr[i]<<endl;
		}
	}

}

int main() {

	int arr[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}

	};

	passArray(&arr);

	return 0;

}
