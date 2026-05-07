class Solution {
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int target) {
        // code here
        //Arrays.sort(arr);
        
        Set<ArrayList<Integer>> ans = new LinkedHashSet<>();
        
        int n = arr.length;
        int i = 0;
        while(i<n) {
            int j = i+1;
            
            
            
            while(j<n) {
                
                Map<Integer,Integer> look = new LinkedHashMap<>();
                int k = j+1;
                
                while(k<n) {
                    
                    int sum = arr[i]+arr[j]+arr[k];
                    int need = target - sum;
                    if(look.containsKey(need)) {
                        ArrayList<Integer> intmd= new ArrayList<>();
                        intmd.add(arr[i]);
                        intmd.add(arr[j]);
                        intmd.add(arr[k]);
                        intmd.add(need);
                        Collections.sort(intmd);
                        ans.add(intmd);
               
                    }
                    
                    int c = 1;
                    if(look.containsKey(arr[k])) {
                        c = look.get(arr[k])+c;
                    }
                    look.put(arr[k],c);
                    
                    
                    k++;
                    
                }

                j++;                

            }
            
            
            i++;
        }
        
        ArrayList<ArrayList<Integer>> ans2 = new ArrayList<>();
        for(ArrayList<Integer> intmd: ans) {
            ans2.add(intmd);
        }
        
        return ans2;
    }
}