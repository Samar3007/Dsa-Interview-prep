class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> freq(26);
        for(char s: word){
            freq[s-'a']++;
        }
        vector<int> nums;
        for(int s:freq){
            if(s!=0) nums.push_back(s);
        }
        //sort(res.begin(),res.end());
        int mini = 1e6, n=nums.size();
        
        for(int i=0;i<n;i++){
            int diff=0;
            for(int j=0;j<n;j++){
                if(nums[j]<nums[i]){
                    diff+=nums[j];
                }
                else if(nums[j]>nums[i]+k){
                    diff+=(nums[j]-nums[i]-k);
                }
            }
            mini=min(mini,diff);
        }

        //int ans=0;
        // while(l<r){
        //     int diff=res[r]-res[l];
        //     if(diff>k){
        //         if(diff-k>res[l]){
        //             ans+=res[l];
        //             l++;
        //         }
        //         else{
        //             ans+=diff-k;
        //             r--;
        //         }
        //     }
        //     else{
        //         l++;
        //         r--;
        //     }
        // }
        return mini;
    }
};