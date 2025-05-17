class Solution {
public:
    void sortColors(vector<int>& nums) {
        int freq[3]={0};
        for(int it:nums){
            freq[it]++;
        }
        int j=0;
        for(int i=0;i<3;i++){
            while(freq[i]){
                nums[j++]=i;
                freq[i]--;
            }
        }
        return;
    }
};