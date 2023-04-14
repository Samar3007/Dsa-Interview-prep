class Solution {
//for all integers
/*public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i];
            int j=0;
            int count=0;
            
            while((i+j)<nums.size() && temp==nums[i+j])
            {
                count++;
                j++;
                maxi=max(count,maxi);
            }
        }
        return maxi;
    }
};*/
    
//for binary
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0,i=0,count=0;
        while(i<nums.size()){
            
            if(nums[i]==1){
                count++;
            }
            
            else{
                count=0;
            }
            i++;
            if(count>maxi){
                maxi=count;
            }
        }
        return maxi;
}
};