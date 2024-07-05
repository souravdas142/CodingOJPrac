#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//#define debug(x) printf("%s is : %d",#x,x);
//

int grow_a,gcol_a,grow_b,gcol_b,grow_c,gcol_c;

struct info {
    int id;
	int row;
    int* A;
    int* B;
    int* res;

};


void print2d(int *arr,int row, int col) { 
    
    printf("\n");
	for(int i = 0;i<row;i++) {
		for (int j = 0;j<col;j++) {
			printf("%d ",arr[(i*col+j)]);
		}
		printf("\n");
	}
    

}

void printArr(int *arr,int col) {
	printf("debug: %s",__func__);
    printf("\n");
    for(int i =0;i<col;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void* compute(void *info) {
    
    struct info* all_info = (struct info*)(info);
    //printArr(all_info->A,all_info->row);
	
	int *arrB = all_info->B;
	int *arrA = all_info->A;
	int *single_row_a = malloc(gcol_a*sizeof(int));
	int i = all_info->row;
	int *res = all_info->res;

	for(int j = 0;j<gcol_a;j++) {
		single_row_a[j] = arrA[i*gcol_a+j];
	}
	//printf("\n single_row_a start\n");
	//printArr(single_row_a,gcol_a);
	//printf("\n single_row_a end\n");


    //print2d(arrB,grow_b,gcol_b);
    

	for(int i = 0 ;i<gcol_b;i++) {
		int result = 0;

		for(int j = 0;j<grow_b;j++) {

			result+= arrB[i+(gcol_b*j)] * single_row_a[j];
		}
		res[i] = result;

	}





    return NULL;

}


int main() {

	int row_a,row_b,col_a,col_b;
	scanf("%d%d%d%d",&row_a,&col_a,&row_b,&col_b);

	// checking if multiplication feasible
	if(col_a != row_b) {
		printf("Multiplication is not possible\n");
		return 1;
	}

	int row_c = row_a, col_c = col_b;

	grow_a = row_a, grow_b = row_b, grow_c = row_c;
	gcol_a = col_a, gcol_b = col_b, gcol_c = col_c;
    
	int *A = malloc(row_a * col_a * sizeof(int));
	int *B = malloc(row_b * col_b * sizeof(int));
    

	for(int i = 0;i<row_a;i++) {
		for (int j = 0;j<col_a;j++) {
			int a = rand()%100;
			//printf("random is : %d\n",a);
			A[(i*col_a+j)] = a;
		}
	}

	for(int i = 0;i<row_b;i++) {
		for (int j = 0;j<col_b;j++) {
			int b = rand()%100;
//			printf("random is : %d\n",b);
			B[(i*col_b+j)] = b;
		}
	}


	print2d(A,row_a,col_a);
	print2d(B,row_b,col_b);

    pthread_t pid[row_a];
    struct info res[row_a];
    
    // each thread is responsible to generate each row of the resultant matrix
    for(int i = 0;i<row_a;i++) {
        
        res[i].id = i;
		res[i].row = i;
        res[i].A = A;
        res[i].B = B;
        res[i].res = (int*) malloc(row_c*col_c*sizeof(int));
        
        pthread_create(&pid[i],NULL,compute,&res[i]);
        
    }

    for(int i =0 ;i<row_a;i++) {
        pthread_join(pid[i],NULL);
        
    }
    
    int* c[row_c];
    for(int i = 0;i<row_c;i++) {
        c[i] = res[i].res;
		for(int j = 0;j<col_c;j++) {
			printf("%d ",c[i][j]);
		}
		printf("\n");
    }

	

// freeing the memory
    for(int i = 0;i<row_a;i++) {
        free(res[i].res);
    }

	free(A);
	free(B);

    return 0;
}
