class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        map<int,int> mpp;
        for(int it:nums){
            if(mpp.find(it)==mpp.end()){
                mpp[it]=1;
            }
            else mpp[it]++;
        }
        int dom = -1, freq = 0;
        for(auto it:mpp){
            if(it.second>n/2){
                dom = it.first;
                freq = it.second;
                break;
            }
        }
        if(dom==-1) return -1;
        int cnt = 0, ans = -1;
        for(int i=0;i<n;i++){
            if(nums[i]==dom) cnt++;
            if(cnt>(i+1)/2 && freq-cnt>(n-i-1)/2){
                ans = i;
                break;
            }
        }
        return ans;
    }
};