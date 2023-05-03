class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        vector<int> ans;
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
            if(match==1) st.insert(nums1[i]);
        }
        for(int x : st){
            ans.push_back(x);
        }
        res.push_back(ans);
        st.clear();ans.clear();

        for(int i=0;i<nums2.size();i++){
            match=1;
            for(int j=0;j<nums1.size();j++){
                if(nums2[i]==nums1[j]){
                    match=0;
                    break;
                }
            }
            if(match==1) st.insert(nums2[i]);
        }
        for(int x : st){
            ans.push_back(x);
        }
        st.clear();
        
        res.push_back(ans);
        return res;
        
    }
};