class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,1);
        vector<int> left(n,1);
        vector<int> right(n,1);
        int rp=1,lp=1;
        for(int i=n-2;i>=0;i--){
            right[i]=rp*nums[i+1];
            rp=right[i];
           
        }
        
        for(int j=1;j<=n-1;j++){
            left[j]=lp*nums[j-1];
            lp=left[j];
        }
        
        for(int k=0;k<n;k++){
                ans[k]=left[k]*right[k];
        }
        
        return ans;
    }
};