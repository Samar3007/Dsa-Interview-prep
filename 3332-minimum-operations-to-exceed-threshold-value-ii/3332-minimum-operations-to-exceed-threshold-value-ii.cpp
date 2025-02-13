class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> st;
        for(auto it:nums){
            st.insert(it);
        }
        if(*st.begin()>=k) return 0;
        int ans = 0;
        while(*st.begin()<k && st.size()>1){
            int max = *next(st.begin(),1);
            int min = *st.begin();
            st.erase(st.begin(),next(st.begin(),2));
            long long sum = (long long)min*2 + max;
            st.insert(sum);
            ans++;
        }
        return ans;
    }
};