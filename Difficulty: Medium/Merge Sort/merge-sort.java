class Solution {
    
    void merge(int[] arr, int l, int mid, int r) {
        int[] left = new int[mid-l+1];
        int[] right = new int[r-mid];
        for(int i = 0;i<mid-l+1;i++) {
            left[i] = arr[l+i]; 
        }
        
        for(int i = 0;i<r-mid;i++) {
            right[i] = arr[mid+i+1];
        }
        
        // System.out.print("left = ");
        // for(int i = 0;i<left.length;i++) {
        //     System.out.print(left[i]+" ");
        // }
        // System.out.println();
        
        // System.out.print("right = ");
        // for(int i = 0;i<right.length;i++) {
        //     System.out.print(right[i]+" ");
        // }
        // System.out.println();
        
        int i = 0;
        int j = 0;
       
        int k = l;
        
        
        while(i<mid-l+1 && j<r-mid) {
            if(left[i]<=right[j]) {
                arr[k] = left[i];
            
                i++;
            }
            else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        
        while(i<mid-l+1) {
                arr[k] = left[i];
                k++;
                i++;
        }
        
        while(j<r-mid) {
            arr[k] = right[j];
            j++;
            k++;
        }
        
        
        
    }

    void mergeSort(int arr[], int l, int r) {
        // code here
        if(l>=r) return;
        // System.out.println("l = "+l+", r = "+r);
        
        int n = arr.length;
        int mid = l + (r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}