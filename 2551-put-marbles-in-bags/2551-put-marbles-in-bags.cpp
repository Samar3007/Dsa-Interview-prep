class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> st;
        int n=weights.size();
        long long min=weights[0]+weights[n-1];
        long long max=weights[0]+weights[n-1];
        
        for(int i=1;i<n;i++){
            st.push_back(weights[i]+weights[i-1]);
        }
        sort(st.begin(), st.end());
        for(int i=0;i<k-1;i++){
            min+=st[i];
        }
        reverse(st.begin(),st.end());
        for(int i=0;i<k-1;i++){
            max+=st[i];
        }
        
        return max-min;
    }
};