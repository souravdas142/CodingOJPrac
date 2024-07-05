#include <stdio.h>

void constArray(int row, int col) {

	int arr[row][col];

	for(int i = 0;i<row;i++) {
		for(int j = 0;j<col;j++) {
			arr[i][j] = j;
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

}

int main() {

	int row = 3;
	int col = 3;

	constArray(row,col);
	return 0;

}
