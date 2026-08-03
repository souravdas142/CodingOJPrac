class Solution {
    public static ArrayList<ArrayList<Integer>> triplets(int[] arr) {
        // code here
        Arrays.sort(arr);
        int n = arr.length;
        
        int i = 0;
       
        int target = 0;
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        
        
        while(i<n) {
           
            int j = i+1;
            int k = n-1;
            while(j<k) {
                
                int sum = (arr[i]+arr[j]+arr[k]);
                
                if(sum>target) {
                    k--;
                   
                }
                else if(sum<target) {
                    j++;
                    
                }
                
                else if(sum==target) {
                    ans.add(new ArrayList<>(Arrays.asList(arr[i], arr[j], arr[k])));
                    j++;
                    while(j<n && arr[j]==arr[j-1]) j++;
                    k--;
                    while(k>j && arr[k]==arr[k+1]) k--;
                }
                
                
                
              
                
               
              
            }
            
            
            i++;
            while(i<n && arr[i]==arr[i-1]) i++;
        }
        
        return ans;
    }
}
