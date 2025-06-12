#define vpi vector<pair<int,int> >

ostream& operator <<(ostream& print,vpi& arr) {
    for(int i = 0;i<arr.size();i++) {
        print<<arr[i].first<<" ";
    }
    return print;
}

class Solution {
public:
    void merge(vpi& dnums,int left, int mid,int right, int n,vector<int>& ans) {
       vpi res(right-left+1,{0,0});
        int il = left, ir = mid, jl = mid+1, jr = right,i = 0;

        
        while(il <= ir && jl <= jr) {
            if(dnums[il].first<=dnums[jl].first) {

                
                res[i] = dnums[jl];
                jl++;
            }
            else {
                ans[dnums[il].second]++;
                res[i] = dnums[il];
                il++;
            }
            i++;
        }

        while(il<=ir) {
            res[i++] = dnums[il++];
        }

        while(jl<=jr) {
            res[i++] = dnums[jl++];
        }
        //cout<<res<<endl;
        int ll = left;
        for(int i = 0;i<right-left+1;i++) {
            dnums[ll++] = res[i];
        }

        //cout<<"Nums = "<<dnums<<endl;
       
        

    }
    void mergeSort(vpi& dnums, int left, int right, int n,vector<int>& ans) {
        if(left>=right) {
            return ;
        }
        int mid = left+(right-left)/2;
        mergeSort(dnums,left,mid,n,ans);
        mergeSort(dnums,mid+1,right,n,ans);
        merge(dnums,left,mid,right,n,ans);
        
    }
    vector<int> countSmaller(vector<int>& nums) {

       int n = nums.size();
       int left = 0;
       int right = n-1;
       vpi dnums(n);
       for(int i = 0;i<n;i++) dnums[i] = {nums[i],i};
        vector<int> ans(n,0);
       mergeSort(dnums,left,right,n,ans);
       //cout<<dnums<<endl;
       return ans;

        
    }
};