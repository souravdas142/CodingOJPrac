#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

//#define debug(x) printf("%s is : %d",#x,x);

struct info {
    int id;
    int row;
    int col_b;
    int row_b;
    int* A;
    int** B;
    int* res;

};


void print2d(int **arr,int row, int col) { 
    
    printf("\n");
    for (int i = 0 ;i<row;i++ ) {
        for (int j = 0; j<col;j++) {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    

}

void printArr(int *arr,int col) {
    printf("\n");
    for(int i =0;i<col;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
}

void* compute(void *info) {
    
    struct info* all_info = (struct info*)(info);
    //printArr(all_info->A,all_info->row);
    print2d(all_info->B,all_info->row_b,all_info->col_b);
    
    printf("\ntid = %d",all_info->id);
    int col_b = all_info->col_b;
    for(int i = 0;i<col_b; i++) {
        int result =0;
        for(int j = 0;j<col_b;j++) {
            result+=all_info->A[j]*all_info->B[j][i];
        }

        all_info->res[i] = result;

    }

    return NULL;

}


int main() {
    
    int A[3][3] = {
                    {1,2,3},
                    {3,4,5},
                    {6,7,8}
                };
    
    int B[3][4] = {
        
        {3,4,5,6},
        {6,7,8,9},
        {9,10,11}
       
    };

    int row_sz_a = sizeof(A)/sizeof(A[0]);
    int col_sz_a = sizeof(A)/row_sz_a;
    int row_sz_b = sizeof(B)/sizeof(B[0]);
    int col_sz_b = sizeof(A)/row_sz_b;

    pthread_t pid[row_sz_a];
    struct info res[row_sz_a];
    
    // each thread is responsible to generate each row of the resultant matrix
    for(int i = 0;i<row_sz_a;i++) {
        
        res[i].id = i;
        res[i].A = A[i];
        res[i].B = B;
        res[i].row = sizeof(A[0])/sizeof(int);
        res[i].row_b = row_sz_b;
        res[i].col_b = col_sz_b;
        res[i].res = (int*) malloc(sizeof(int)*(sizeof(A)/row_sz_a));
        
        pthread_create(&pid[i],NULL,compute,&res[i]);
        
    }

    for(int i =0 ;i<row_sz_a;i++) {
        pthread_join(pid[i],NULL);
        
    }
    
    int* c[row_sz_a];
    for(int i = 0;i<row_sz_a;i++) {
        c[i] = res[i].res;

        for(int j = 0;j<col_sz_b;j++) {
            printf("c[i][j] = %d ",c[i][j]);
        }
        printf("\n");
    }

// freeing the memory
    for(int i = 0;i<row_sz_a;i++) {
        free(res[i].res);
    }

    return 0;
}
