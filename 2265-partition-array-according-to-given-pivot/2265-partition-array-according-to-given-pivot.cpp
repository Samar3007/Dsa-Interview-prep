class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int cnt = 0;
        vector<int> less, more;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                cnt++;
            }
            else{
                more.push_back(nums[i]);
            }
        }
        while(cnt){
            less.push_back(pivot);
            cnt--;
        }
        for(int i=0;i<more.size();i++){
            less.push_back(more[i]);
        }
        return less;
    }
};