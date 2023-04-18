class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-2;
        int mid=0;
        while(low<=high){
            mid=(low+high)/2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]) 
                //Checking whether we are in right half
                    low = mid + 1;  
                     //Shrinking the right half
                else
                    high = mid - 1; //Shrinking the left half
            } else {

                //Checking whether we are in right half
                if (nums[mid] == nums[mid + 1]) 
                    high = mid - 1; //Shrinking the right half                    
                else
                    low = mid + 1; //Shrinking the left half
            }
        }
        return nums[low];
    }
};