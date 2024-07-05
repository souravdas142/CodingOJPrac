#include <stdio.h>

int row,col;

void print(int arr[row][col]) {
	printf("\n");
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
		
}


int main() {

	int local_row,local_col;
	scanf("%d%d",&local_row,&local_col);
	row=local_row;
	col=local_col;
	int arr[4][5] = {
		{1,2,3,4,5},
		{3,4,1,2,5},
		{2,3,1,5,4},
		{3,1,5,2,4}
	};

	int *parr = (int*)arr;
	for(int i = 0;i<20;i++) {
		printf("%d ",*(parr+i));
		if(i%5==0) printf("\n");
	}

	printf("\n\nTest:\n\n");
	print(arr);

	return 0;
}
