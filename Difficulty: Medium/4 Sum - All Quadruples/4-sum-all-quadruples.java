class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int target) {
        // code here
        int n = arr.length;
        Arrays.sort(arr);
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        int i = 0;
        
        while(i<n) {
            
            int j = i+1;
            
            while (j<n) {
                
                int k = j+1;
                int l = n-1;
                
                while(l>k) {
                    int sum = arr[i]+arr[j]+arr[k]+arr[l];
                    
                    
                    if(sum>target) {
                        l--;
                    }
                    else if(sum<target) {
                        k++;
                    }
                    else {
                        ans.add(new ArrayList<>(Arrays.asList(arr[i],arr[j],arr[k], arr[l])));
                        k++;
                        while(k<l && arr[k]==arr[k-1]) k++;
                        l--;
                        
                        
                        while(l>k && arr[l]==arr[l+1]) l--;
                    }
                    
                }
                
                
                
                j++;
                while(j<n && arr[j]==arr[j-1]) j++;
            }
            
            
            
            
            i++;
            while(i<n && arr[i]==arr[i-1]) i++;
        }
        
        return ans;
    }
}