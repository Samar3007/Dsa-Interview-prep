class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> newN;
        int n=nums.size(), prev = 0;
        for(int i=0;i<n;i++){
            if(prev==nums[i]){
                continue;
            }
            newN.push_back(nums[i]);
            prev=nums[i];
        }

        n=newN.size();

        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(newN[i-1]<newN[i] && newN[i]>newN[i+1]) cnt++;
            else if(newN[i-1]>newN[i] && newN[i]<newN[i+1]) cnt++;
        }

        return cnt;
    }
};