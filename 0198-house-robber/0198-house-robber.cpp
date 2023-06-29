class Solution {
public:
    int func(vector<int>& arr){
        int prev2=0,prev1=arr[0];
        
        for(int i=1;i<arr.size();i++){
            
            int left=arr[i];
            if(i>1) left+=prev2;
            int right=prev1;
            
            int curr=max(left,right);
            
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
    
        return func(nums);
    }
    
    
};