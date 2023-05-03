class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;
        vector<vector<int>> res;
        int match;
        for(int i=0;i<nums1.size();i++){
            match=1;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    match=0;
                    break;
                }
            }
            if(match==1) ans1.push_back(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            match=1;
            for(int j=0;j<nums1.size();j++){
                if(nums2[i]==nums1[j]){
                    match=0;
                    break;
                }
            }
            if(match==1) ans2.push_back(nums2[i]);
        }
        sort( ans1.begin(), ans1.end() );
        sort( ans2.begin(), ans2.end() );
        ans1.erase( unique( ans1.begin(), ans1.end() ), ans1.end() );
        ans2.erase(unique(ans2.begin(),ans2.end()),ans2.end());
        res.push_back(ans1);
        res.push_back(ans2);
        return res;
        
    }
};