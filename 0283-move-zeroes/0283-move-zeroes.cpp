class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0; int i=0;
        while(i<nums.size()){
            if(nums[i]!=0 || (nums.size()-i)<=count){
                i++;
            }
            else{
                count++;
                for(int j=i;j<nums.size()-count;j++){
                    nums[j]=nums[j+1];
                }
                nums[nums.size()-count]=0;
            }
        }
        return;
    }
};